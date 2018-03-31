#include <iostream>
#include <exception>

using namespace std;

int main(){
  try{
    try{
      throw 10;
    }catch(int e){
      cout << "Integer exception caught" << endl;
      throw;
    }
  }catch(...){
    cout << "An exception has been caught" << endl;
  }
  
  return 0;
}