#include <iostream>
#include <string>
#include <vector>

// Disable the copy and assignment operator for a class.
#define DISABLE_COPY_AND_ASSIGN(classname) \
private:\
  classname(const classname&);\
  classname& operator=(const classname&)

// Sigleton design pattern
// Only one object of specific class exists through whole system
class Fun {
public:
    int x;
    static Fun* Get() {
        Fun *f = new Fun();
        return f;
    };

// Use macro we can write type here not defined yet
#ifdef AAA
cublasHandle_t a_;
#endif

private:
    Fun()   // Note: private constructor to prevent duplicate instantiation  
        : x(2) {};
    Fun(const Fun&);
    Fun& operator=(const Fun&);
}; 

void fun(const int& a) {
    // a = 2; Error: assignment of read-only reference
    std::cout << a << "\n";
}

#define STRINGIFY(m) #m
#define AS_STRING(m) STRINGIFY(m)

int main() {
    //int x = 1;
    //fun(x);
    //std::cout << STRINGIFY(func) << "\n";
    //Fun *f = new Fun(); Error occurs here  
    return 0;
}