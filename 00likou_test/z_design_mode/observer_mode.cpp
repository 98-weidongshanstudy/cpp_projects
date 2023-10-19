#include <iostream>
#include <string>
#include <list>
using namespace std;

class Subject;
//观察者 基类 （内部实例化了被观察者的对象sub）
class Observer
{
protected:
    string name;
    Subject *sub;

public:
    Observer(string name, Subject *sub)
    {
        this->name = name;
        this->sub = sub;
    }
    virtual void update() = 0;
};

class StockObserver : public Observer
{
public:
//构造函数，直接初始基类
    StockObserver(string name, Subject *sub) : Observer(name, sub)
    {
    }
    void update();
};

class NBAObserver : public Observer
{
public:
//构造函数，直接初始基类
    NBAObserver(string name, Subject *sub) : Observer(name, sub)
    {
    }
    void update();
};
//被观察者 基类 （内部存放了所有的观察者对象，以便状态发生变化时，给观察者发通知）
class Subject
{
protected:
    list<Observer *> observers;

public:
    string action; //被观察者对象的状态
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};

class Secretary : public Subject
{
    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }
    void detach(Observer *observer)
    {
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            if ((*iter) == observer)
            {
                observers.erase(iter);
                return;
            }
            ++iter;
        }
    }
    //这里面实际上使用了多态的特性
    //调用基类的虚函数，最终实际执行动作的是派生类的实际函数
    void notify()
    {
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            (*iter)->update();
            ++iter;
        }
    }
};

void StockObserver::update()
{
    cout << name << " get msg:" << sub->action << endl;
    if (sub->action == "liang coming!")
    {
        cout << "close stock ,work hard" << endl;
    }
}

void NBAObserver::update()
{
    cout << name << " get msg:" << sub->action << endl;
    if (sub->action == "liang coming!")
    {
        cout << "close NBA ,work hard" << endl;
    }
}

int main()
{
    //被观察者
    Subject *dwq = new Secretary();

    //观察者 将 被观察者对象的基类初始化到自己基类的成员函数中，
    //当收到通知的时候，执行更新的动作，这个时候可以去查看被观察者基类的成员对象
    Observer *xs = new NBAObserver("xiaoshuai", dwq);
    Observer *zy = new NBAObserver("zouyue", dwq);
    Observer *lm = new StockObserver("limin", dwq);

    //被观察者绑定观察者 将观察者对象push到其自身内部
    dwq->attach(xs);
    dwq->attach(zy);
    dwq->attach(lm);

    //被观察者通知观察者
    dwq->action = "go eat !";
    dwq->notify();
    cout << endl;
    dwq->action = "liang coming!";
    dwq->notify();
    return 0;
}

//学习感受
//被观察者有一个基类，里面有相应各种各样的信息

//被观察者内部使用list将所有观察者push到其内部

//被观察者的派生类来执行通知的动作
//这里用了多态的特性，执行notify的时候，调用的是基类的成员函数

//观察者有一个基类，里面有被观察者的基类，
//观察者在初始化的时候，可以将被观察者的基类指针初始化到自身对象中