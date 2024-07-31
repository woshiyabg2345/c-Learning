// c++ 中友元函数
// https://blog.csdn.net/qq_31930499/article/details/80299781

// 1，普通函数友元函数：
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
        friend void Print(const A& obj); // 声明友元函数

};

void Print(const A& obj)  // 定义友元函数和一般函数一样
{
    cout<< obj.num<<endl;
}

void testFun1()
{
    A obj;
    Print(obj); // 直接调用
}

// 2.类Y的所有成员函数都为类X友元函数-----> 友元类
// 声明位置私有公有都可以


class X
{
    private:
    char * name ;
    int age;
    private:
    friend class Y; // 声明Y为X的友元类
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

// 3、类E的一个成员函数为类F的友元函数  顺序不可以错
class F; // 需要提前声明
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