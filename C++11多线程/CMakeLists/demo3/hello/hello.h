#pragma once
#include <iostream>

using namespace std;

class Hello
{
public:
    Hello();
    ~Hello();
    void setVal(int val);
    int getVal();
private:
    int _val;
};