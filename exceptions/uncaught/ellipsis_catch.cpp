#include <iostream>
#include <exception>

using namespace std;

int main(){
  try{
    throw 20;
  }catch(int e){
    cout << "int exception" << endl;
  }catch(double e){
    cout << "double exception" << endl;
  }catch(...){
    cout << "All other exceptions" << endl;
  }
  
  
  try{
    throw 20.0;
  }catch(int e){
    cout << "int exception" << endl;
  }catch(double e){
    cout << "double exception" << endl;
  }catch(...){
    cout << "All other exceptions" << endl;
  }
  
  try{
    throw true;
  }catch(int e){
    cout << "int exception" << endl;
  }catch(double e){
    cout << "double exception" << endl;
  }catch(...){
    cout << "All other exceptions" << endl;
  }
  
  return 0;
}