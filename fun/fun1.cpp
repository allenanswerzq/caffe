#include <iostream>
#include <string>
#include <map>

//using namespace std;
using std::map;
using std::string;
using std::cout;

// A simple registry for caffe commands.
typedef int (*BrewFunction)();
typedef map<std::string, BrewFunction> BrewMap;
BrewMap g_brew_map;

// Paste syntax 
#define RegisterBrewFunction(func) \
namespace { \
class __Registerer_##func { \
 public: /* NOLINT */ \
  __Registerer_##func() { \
    g_brew_map[#func] = &func; \
  } \
}; \
__Registerer_##func g_registerer_##func; \
}


static BrewFunction GetBrewFunction(const std::string& name) {
  if (g_brew_map.count(name)) {
    return g_brew_map[name];
  } else {
    std::cout << "Available caffe actions:";
    for (BrewMap::iterator it = g_brew_map.begin();
         it != g_brew_map.end(); ++it) {
      std::cout << "\t" << it->first;
    }
    std::cout << "Unknown action: " << name;
    return NULL;  // not reachable, just to suppress old compiler warnings.
  }
}

int fun() {
    std::cout << "It's fun to play code\n";
    return 0;
}
RegisterBrewFunction(fun);

class X {
  int i;
public:
  X(int ii = 0);
  void modify();
};

X::X(int ii) { i = ii; }

void X::modify() { i++; }

X f5() {
  return X();
}
// prevent return value to be a lvalue
const X f6() {
  return X();
}

void f7(X& x) { // Pass by non-const reference
  x.modify();
}

/*
int main() {
  f5() = X(1); // OK -- non-const return value
  f5().modify(); // OK
  f7(f5()); // Causes warning or error
  // Causes compile-time errors:
  f7(f5());
  f6() = X(1);
  f6().modify();
  f7(f6());
} 
/*
/*
int main() {
    BrewFunction p;
    p = GetBrewFunction("fun");
    p();
}
*/


class Test {
public:
  enum Brew {CPU, GPU};
};
/*
int main() {
  cout << Test::GPU;
}
*/

#include <vector>
namespace test {
  using std::vector;
}

using test::vector;
int main() {
  vector<int> x(1, 0);
}
