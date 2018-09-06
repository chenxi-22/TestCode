// #include <iostream>
// using namespace std;

// Design pattern

// 单例模式
// 饿汉模式与懒汉模式

// 懒汉模式
// class CSingleton {
// public:
//   static CSingleton* get_instance() {
//     if (_instance != nullptr)
//       _instance = new CSingleton;
//     return _instance;
//   }
// private:
//   CSingleton() = default;
//   static CSingleton* _instance;
// };
// CSingleton* CSingleton::_instance = nullptr;   /* 初始化 _instance */
// 上面的模式下，会有两个问题: a.内存泄漏，new 出来的 CSingleton 没有释放
//                             b.线程安全问题

// 解决方式如下:
// class CSingleton {
// public:
//   static CSingleton* get_instance() {
//     if (_instance != nullptr) {
//       lock();
//       if (_instance != nullptr)
//         _instance = new CSingleton;
//       unlock();
//       return _instance;
//     }
//   }
// private:
//   class help_delete {
//   public:
//     static void _delete() {
//       if (_instance != nullptr)
//         delete _instance;
//     }
//   };
//   help_delete hd;
//   CSingleton() = default;
//   static CSingleton* _instance;
// };
// CSingleton* CSingleton::_instance = nullptr;   /* 初始化 _instance */

// 饿汉模式
// class CSingleton {
//   static CSingleton* get_instance() {
//     return _instance;
//   }
// private:
//   CSingleton() = default;
//   static CSingleton* _instance;
// };
// CSingleton* CSingleton::_instance = new CSingleton;


// 简单工厂模式
// enum type {
//   typeA,
//   typeB
// };

// class product {
// public:
//   virtual void show() = 0;
// };

// class A : public product {
// public:
//   virtual void show() {
//     cout << "A" << endl;
//   }
// };

// class B : public product {
// public:
//   virtual void show() {
//     cout << "B" << endl;
//   }
// };

// class Factory {
// public:
//   static product* create(int type) {
//     switch (type) {
//     case typeA:
//       return new A;
//       break;
//     case typeB:
//       return new B;
//       break;
//     default:
//       break;
//     }
//   }
// };

// void Test() {
//   Factory f;
//   product* pA = f.create(typeA);
//   product* pB = f.create(typeB);
//   pA->show();
//   pB->show();
// }

// 工厂方法模式
// class product {
// public:
//   virtual void show() = 0;
// };

// class A : public product {
// public:
//   virtual void show() {
//     cout << "A" << endl;
//   }
// };

// class B : public product {
// public:
//   virtual void show() {
//     cout << "B" << endl;
//   }
// };

// class Factory {
// public:
//   virtual product* create() = 0;
// };

// class FactoryA : public Factory {
// public:
//   virtual product* create() {
//     return new A;
//   }
// };

// class FactoryB : public Factory {
// public:
//   virtual product* create() {
//     return new B;
//   }
// };

// void Test() {
//   Factory* fa = new FactoryA;
//   product* a = fa->create();
//   a->show();

//   Factory* fb = new FactoryB;
//   product* b = fb->create();
//   b->show();
// }

// 抽象工厂模式
// class brush {
// public:
//   virtual void tooth_brush() = 0;
// };

// class paste {
// public:
//   virtual void tooth_paste() = 0;
// };

// class brush1 : public brush {
// public:
//   virtual void tooth_brush() {
//     cout << "good brush" << endl;
//   }
// };

// class brush2 : public brush {
// public:
//   virtual void tooth_brush() {
//     cout << "bad brush" << endl;
//   }
// };

// class paste1 : public paste {
// public:
//   virtual void tooth_paste() {
//     cout << "good paste" << endl;
//   }
// };

// class paste2 : public paste {
// public:
//   virtual void tooth_paste() {
//     cout << "bad paste" << endl;
//   }
// };

// class Factory {
// public:
//   virtual brush* product_brush() = 0;
//   virtual paste* product_paste() = 0;
// };

// class fact_good : public Factory {
// public:
//   virtual brush* product_brush() {
//     return new brush1;
//   }

//   virtual paste* product_paste() {
//     return new paste1;
//   }
// };

// class fact_bad : public Factory {
// public:
//   virtual brush* product_brush() {
//     return new brush2;
//   }

//   virtual paste* product_paste() {
//     return new paste2;
//   }
// };

// void Test() {
//   Factory* f_good = new fact_good;
//   f_good->product_brush()->tooth_brush();
//   f_good->product_paste()->tooth_paste();

//   Factory* f_bad = new fact_bad;
//   f_bad->product_brush()->tooth_brush();
//   f_bad->product_paste()->tooth_paste();
// }

// int main()
// {
//   Test();

//   system("pause");
//   return 0;
// }
