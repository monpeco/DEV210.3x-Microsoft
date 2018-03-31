#include <iostream>
#include <exception>

using namespace std;

class derivedException : public exception{
  virtual const char* what() const throw(){
    return "My derived exception";
  }
};

int main(){
  
  derivedException myderivedException;
  
  try{
    
    throw myderivedException;
    
  }catch(exception &e){
    cout << e.what() << endl;
  }
  
  return 0;
}