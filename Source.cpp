#include <iostream>
using namespace std;

// ������� ����
class Base {
public:
    virtual void myname() {
        cout << "This is class Base" << endl;
    }
    virtual ~Base() {} // ³��������� ����������
};

// �������� ���� DerA
class DerA : virtual public Base {
public:
    void myname() override {
        cout << "This is class DerA" << endl;
    }
};

// �������� ���� DerB
class DerB : virtual public Base {
public:
    void myname() override {
        cout << "This is class DerB" << endl;
    }
};

// ���� DerAB, ���� ��������� �� DerA � DerB
class DerAB : public DerA, public DerB {
public:
    void myname() override {
        cout << "This is class DerAB" << endl;
    }
};

int main() {
    // ��������� ��'���� ��� ������� �����
    Base baseObj;
    DerA derAObj;
    DerB derBObj;
    DerAB derABObj;

    // ������ myname ��� ������� ��'����
    baseObj.myname();
    derAObj.myname();
    derBObj.myname();
    derABObj.myname();

    // ����� ��������� �� ������� ����
    Base* ptrs[4];

    // �������� ��������� ��'����
    ptrs[0] = new Base();
    ptrs[1] = new DerA();
    ptrs[2] = new DerB();
    ptrs[3] = new DerAB();

    // ������ myname ��� ������� ���������� ��'����
    for (int i = 0; i < 4; ++i) {
        ptrs[i]->myname();
    }

    // ��������� ���'��
    for (int i = 0; i < 4; ++i) {
        delete ptrs[i];
    }

    return 0;
}