#include <iostream>
using namespace std;

class A {
public:
  virtual void fun1() {
    cout<<"A::fun1()"<<endl;
  }
  virtual void fun2() {
    cout<<"A::fun2()"<<endl;
  }
};


class B {
public:
  virtual void fun1() {
    cout<<"B::fun1()"<<endl;
  }
  virtual void fun2() {
    cout<<"B::fun2()"<<endl;
  }
};

class C : public A, public B {
public:
  virtual void fun1() {
    cout<<"C::fun1()"<<endl;
  }
};

int main()
{
  A a;
  B b;
  C c;

  return 0;
}


