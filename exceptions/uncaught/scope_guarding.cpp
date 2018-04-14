#include <iostream>
#include <vector>

using namespace std;

template<class TContainer>
class VecScopeGuard{
public:
  VecScopeGuard(TContainer* vecptr)
    : engaged_(true), vecptr_(vecptr){ // Assign vecptr and set guard to true
  }

  ~VecScopeGuard(){
    if(engaged_){    // Remove last vector entry
      vecptr_->pop_back();
    }
  }

  void disengage(){
    engaged_ = false;   // Vectors updated so release guard
  }
private:
  bool engaged_;
  TContainer* vecptr_;
};

int main(){
  vector<string> firstVector;
  vector<string> secondVector;
  string myString("Hello World!");

  try{
    firstVector.push_back(myString);
    VecScopeGuard<vector<string>> guard1(&firstVector);
    secondVector.push_back(myString);
    VecScopeGuard<vector<string>> guard2(&secondVector);

    guard1.disengage();
    guard2.disengage();
  }catch(...){
    cout << "Caught error." << endl;
  }
  
  cout << "First use of scope guards ok, first vector size is  " << firstVector.size() << " second vector size is " << secondVector.size() << endl;
  
  //Clear vectors.
  firstVector.clear();
  secondVector.clear();

  cout << "First use of scope guards ok, first vector size is  " << firstVector.size() << " second vector size is " << secondVector.size() << endl;

  try{
    firstVector.push_back(myString);
    VecScopeGuard<std::vector<std::string>> guard1(&firstVector);
    
    std::bad_alloc excp;
    throw excp; //Replicate error updating second vector.
    
    secondVector.push_back(myString);
    VecScopeGuard<std::vector<std::string>> guard2(&secondVector);
    guard1.disengage();
    guard2.disengage();
    
  }catch(bad_alloc e){
    cout << "Caught exception " << endl;
    cout << "Second use of scope guards error, first vector size is  " << firstVector.size() << " second vector size is " << secondVector.size() << endl;
  }
  
  return 0;
}


/*
Output:

First use of scope guards ok, first vector size is  1 second vector size is 1
First use of scope guards ok, first vector size is  0 second vector size is 0
Caught exception 
Second use of scope guards error, first vector size is  0 second vector size is 0

*/