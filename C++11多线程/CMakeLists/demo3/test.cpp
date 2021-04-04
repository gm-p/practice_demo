#include <iostream>
#include <memory>
#include "hello/hello.h"

using namespace std;

class Test: public enable_shared_from_this<Test>
{
public:
    Test(){}
    ~Test(){}
    shared_ptr<Test> getPtr()
    {
        return shared_from_this();
    }

    void set(int id, string name)
    {
        _id = id;
        _name = name;
    }
    
    int getId()
    {
        return _id;
    }
    string getName()
    {
        return _name;
    }
private:
    int _id;
    string _name;
};

int main()
{
    shared_ptr<Test> t1 = make_shared<Test>();
    shared_ptr<Hello> t2 = make_shared<Hello>();
    t1->set(1, "test");
    cout<<"id: "<<t1->getId()<<endl;
    cout<<"name: "<<t1->getName()<<endl;
    t2->setVal(10);
    cout<<"val: "<<t2->getVal()<<endl;
    return 0;
}