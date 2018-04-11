#include <iostream>
#include <vector>

using namespace std;

template<class TContainer>
class VecScopedGuard{
public:
  VecScopedGuard(TContainer* vecptr)
    : engaged_(true), vecptr_(vecptr){ // Assign vecptr and set guard to true
  }

  ~VecScopedGuard(){
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
    VecScopedGuard<vector<string>> guard1(&firstVector);
    secondVector.push_back(myString);
    VecScopedGuard<vector<string>> guard2(&secondVector);

    guard1.disengage();
    guard2.disengage();
  }catch(...){
    cout << "Caught error." << endl;
  }

  return 0;
}
