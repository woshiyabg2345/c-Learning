// c++ ����Ԫ����
// https://blog.csdn.net/qq_31930499/article/details/80299781

// 1����ͨ������Ԫ������
#include <iostream>


using namespace std;
class A
{
    private:
        int num;
        public:
        A()
        {
            num = 1;
        }
        friend void Print(const A& obj); // ������Ԫ����

};

void Print(const A& obj)  // ������Ԫ������һ�㺯��һ��
{
    cout<< obj.num<<endl;
}

void testFun1()
{
    A obj;
    Print(obj); // ֱ�ӵ���
}

// 2.��Y�����г�Ա������Ϊ��X��Ԫ����-----> ��Ԫ��
// ����λ��˽�й��ж�����


class X
{
    private:
    char * name ;
    int age;
    private:
    friend class Y; // ����YΪX����Ԫ��
    public:
    X(char* _name,int age):name(_name),age(age){};
};

class Y
{
    private:
        char *name;
        int age;
    public:
        Y(char* _name,int _age):name(_name),age(_age){}
        void disp(const X& obj );
};

void Y::disp(const X& obj)
{
    std::cout<< " name "<< obj.name<<" age "<< obj.age<<std::endl;
}
void testFun2()
{
    X x("x",19);
    Y y("y",19);
    y.disp(x);
}

// 3����E��һ����Ա����Ϊ��F����Ԫ����  ˳�򲻿��Դ�
class F; // ��Ҫ��ǰ����
class E
{
       private:
    char *name;
    int age;
    public :
    E(char*_name,int _age):name(_name),age(_age){}
    void disp(F& obj);
    //void disp(F obj);
};
class F
{


    private:
    char *name;
    int age;
    public :
    F(char*_name,int _age):name(_name),age(_age){}
    friend void E::disp(F& obj);
};


void E::disp(F& obj)
{
    std::cout<< " name "<< obj.name<< " age "<<obj.age<<std::endl;
}

void testFun3()
{
    F f("is f",19);
    E e( "is e",19);
    e.disp(f);

}