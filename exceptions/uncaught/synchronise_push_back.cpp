#include <iostream>
#include <vector>

using namespace std;

void updateVector(vector<string>& firstVector_, vector<string>& secondVector_, string myString){
  
  firstVector_.push_back(myString);
  
  try{
    secondVector_.push_back(myString);
  }catch(...){
    firstVector_.pop_back();
    cout << "second vector update failed." << endl;
  }
  
}

void updateVector2(vector<string>& firstVector_, vector<string>& secondVector_, string myString){
  
  firstVector_.push_back(myString);
  
  try{
    bad_alloc excep;
    throw excep;
    secondVector_.push_back(myString);
  }catch(...){
    firstVector_.pop_back();
    cout << "second vector update failed." << endl;
  }
  
}

int main(){
  
  vector<string> firstVector;
  vector<string> secondVector;
  string myString("Hello World");
  
  cout << "Calling updateVector " << endl;
  updateVector(firstVector, secondVector, myString);
  cout << "first vector size is " << firstVector.size() << " second vector size is " << secondVector.size() << endl;
  
  cout << "Calling updateVector2 " << endl;
  updateVector2(firstVector, secondVector, myString);
  cout << "first vector size is " << firstVector.size() << " second vector size is " << secondVector.size() << endl;

  
  return 0;
}