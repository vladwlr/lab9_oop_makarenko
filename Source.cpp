#include <iostream>
using namespace std;

// Базовий клас
class Base {
public:
    virtual void myname() {
        cout << "This is class Base" << endl;
    }
    virtual ~Base() {} // Віртуальний деструктор
};

// Похідний клас DerA
class DerA : virtual public Base {
public:
    void myname() override {
        cout << "This is class DerA" << endl;
    }
};

// Похідний клас DerB
class DerB : virtual public Base {
public:
    void myname() override {
        cout << "This is class DerB" << endl;
    }
};

// Клас DerAB, який успадковує від DerA і DerB
class DerAB : public DerA, public DerB {
public:
    void myname() override {
        cout << "This is class DerAB" << endl;
    }
};

int main() {
    // Створення об'єктів для кожного класу
    Base baseObj;
    DerA derAObj;
    DerB derBObj;
    DerAB derABObj;

    // Виклик myname для кожного об'єкта
    baseObj.myname();
    derAObj.myname();
    derBObj.myname();
    derABObj.myname();

    // Масив покажчиків на базовий клас
    Base* ptrs[4];

    // Динамічне створення об'єктів
    ptrs[0] = new Base();
    ptrs[1] = new DerA();
    ptrs[2] = new DerB();
    ptrs[3] = new DerAB();

    // Виклик myname для кожного динамічного об'єкта
    for (int i = 0; i < 4; ++i) {
        ptrs[i]->myname();
    }

    // Звільнення пам'яті
    for (int i = 0; i < 4; ++i) {
        delete ptrs[i];
    }

    return 0;
}