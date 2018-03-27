#### Curso   Exceptions   Exceptions Recap   Recap Exceptions

## Recap Exceptions

You have previously seen the try-catch exception handling mechanism in the c++ language like in the following code.

```c++
#include <iostream>
#include <string>

int main() {
    try{
        throw 6;
    }
    catch(int e) {
        std::cout << "Int exception thrown " << std::to_string(e) << std::endl;
    }
} 
```

This is the main mechanism provided in the c++ language for exception handling and should be used. We will discuss 
other ways of extending this mechanism to allow us to implement more complicated error reporting when an exception occurs.

---

#### Curso   Exceptions   Exceptions Recap   Standard Exception Class Hierarchy

The Standard exception class hierarchy
The c++ standard library provides an exception base class that can be derived and allows us to override the what and ~exception virtual functions in our derived class. This allows us to return a custom error message string and the destructor allows us to free any memory allocated on the heap with the operator new function. For example

```c++
#include <iostream>
#include <exception>

using namespace std;

class derivedexception: public exception {
      virtual const char* what() const throw() {
        return "My derived exception";
      }
} myderivedexception;

int main () {
      try {
        throw myderivedexception;
      }
      catch (exception& e) {
        cout << e.what() << '\n';
      }
}
```

In the first two lines, we include the input and output stream libraries and the standard exception base class. 
The third line declares we are using the std namespace. The fourth line declares our derived class called derived
exception and that we are accessing the base class exception's public members. The fifth line defines our overridden 
base class function what() which returns the const char* c string "My derived exception”. The next two lines close 
the function and class scope. The next line is the main entry point of the program, then on line ten we open a 
try-block to place the following code under an exception inspection. The next line throws an exception of type 
myderivedexception which transfers control to the exception handler. The exception handler is declared with the 
keyword catch on line 13. The type passed as a parameter to catch is compared to the type of the thrown exception, 
in this case the type is exception and our class derivedexception inherits from exception so the handler for derived 
exception is executed and when we invoke the function what() “My derived exception” is returned.

There are a number of exceptions in the standard library which derive from the standard exception base class. The 
ones which derive from the exception base class are

```c++
std::bad_alloc  //thrown by new
std::bad_cast   //thrown by dynamic_cast
std::bad_typeid  //thrown by typeid
std::bad_exception
std::logic_error  //thrown by reading the code
std::runtime_error  //thrown when not detecable by code analisys
std::bad_function_call  //c++11
std::bad_weak_ptr   //c++11
```

Further there are some more exception which derive from std::logic_failure which are

```c++
std::domain_error
std::invalid_argument
std::length_error
std::out_of_range
std::future_error  //c++11
```

And there are also some exception that derive from std::runtime_error which are

```c++
std::overflow_error
std::range_error
std::underflow_error
std::system_error  //c++11
```

Also the following inherit from std::bad_alloc

```c++
std::bad_array_new_length
```

And the following inherit from std::system_error only in c++11

```c++
std::ios_base::failure
```

All of these derive from `std::exception` and therefore can all be caught by the std::exception type.

