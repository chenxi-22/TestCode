#include <iostream>
#include <pthread.h>
using namespace std;

// 饿汉模式
class csingleton1 {
public:
  static csingleton1* get_instance() {
    return _instance;
  }
private:
  csingleton1() = default;
  static csingleton1* _instance;
};
csingleton1* csingleton1::_instance = new csingleton1;

// 懒汉模式
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
class csingleton2 {
public:
  static csingleton2* get_instance() {
    if (_instance != nullptr) {
      pthread_mutex_lock(&lock);
      if (_instance != nullptr) {
        _instance = new csingleton2;
      }
      pthread_mutex_unlock(&lock);
    }
    return _instance;
  }
private:
  csingleton2() = default;
  static csingleton2* _instance;
  class help {
  public:
    ~help() {
      if (_instance) {
        delete _instance;
      }
    }
  };
  static help hp;
};

// 简单工厂模式
// enum type {
//   typeA,
//   typeB
// };
// 
// class product {
// public:
//   virtual void show() = 0;
// };
// 
// class factoryA : public product {
// public:
//   virtual void show() {
//     cout << "factoryA" << endl;
//   }
// };
// 
// class factoryB : public product {
// public:
//   virtual void show() {
//     cout << "factoryB" << endl;
//   }
// };
// 
// class factory {
// public:
//   static product* create(int type) {
//     switch(type) {
//     case typeA:
//       return new factoryA;
//       break;
//     case typeB:
//       return new factoryB;
//       break;
//     default:
//       break;
//     }
//   }
// };

// 工厂方法模式
// class product {
// public:
//   virtual void show() = 0;
// };
// 
// class A : public product {
// public:
//   virtual void show() {
//     cout << "A" << endl;
//   }
// };
// 
// class B : public product {
// public:
//   virtual void show() {
//     cout << "B" << endl;
//   }
// };
// 
// class factory {
// public:
//   virtual product* create() = 0;
// };
// 
// class factoryA : public factory {
// public:
//   virtual product* create() {
//     return new A;
//   }
// };
// 
// class factoryB : public factory {
// public:
//   virtual product* create() {
//     return new B;
//   }
// };

// 抽象工厂模式
class Apple {
public:
  virtual void apple() = 0;
};

class Bnana {
public:
  virtual void bnana() = 0;
};

class good_apple : public Apple {
public:
  virtual void apple() override {
    cout << "good apple" << endl;
  }
};

class bad_apple : public Apple {
public:
  virtual void apple() override {
    cout << "bad apple" << endl;
  }
};

class good_bnana : public Bnana {
public:
  virtual void bnana() override { 
    cout << "good bnana" << endl;
  }
};

class bad_bnana : public Bnana {
public:
  virtual void bnana() override {
    cout << "bad bnana" << endl;
  }
};

class factory {
public:
  virtual Apple* product_apple() = 0;
  virtual Bnana* product_bnana() = 0;
};

class factory_good : public factory {
public:
  virtual Apple* product_apple() override {
    return new good_apple;
  }
  virtual Bnana* product_bnana() override {
    return new good_bnana;
  }
};

class factory_bad : public factory {
public:
  virtual Apple* product_apple() override {
    return new bad_apple;
  }
  virtual Bnana* product_bnana() override {
    return new bad_bnana;
  }
};

int main()
{
  factory* f_good = new factory_good;
  factory* f_bad = new factory_bad;
  cout << "apple" << endl;
  Apple* apple_good = f_good->product_apple();
  apple_good->apple();
  Apple* apple_bad = f_bad->product_apple();
  apple_bad->apple();

  cout << "bnana" << endl;
  Bnana* bnana_good = f_good->product_bnana();
  bnana_good->bnana();
  Bnana* bnana_bad = f_bad->product_bnana();
  bnana_bad->bnana();

  return 0;
}
