#include <iostream>

using namespace std;

class throwexception {
public:
    throwexception(); //Constructor

    ~throwexception();  //Destructor
};

throwexception::throwexception(){
  cout << "throwexception object constructed" << endl;
}

throwexception::~throwexception(void) {
  cout << "throwexception destructor called." << endl;
  throw 9;
}
int main(){
  
  try{
    throwexception texc;
    cout << "Throwing exception will cause termination of program." << endl;
    throw 7;
  }catch(...){
    cout << "Main Exception caught" << endl;
    return -1;
  }
  
  return 0;
}