#include <iostream>
using namespace std;
class box
{
private:
    int *integer;

public:
    box(int i)
    {
        integer = new int(i);
        *integer = i;
    }
    ~box()
    {
        delete integer;
    }
    box(box &other)
    {
        integer = new int(*other.integer);
    }
    box &operator=(const box &other)
    {
        if (this != &other)
        {
            delete integer;
            integer = new int(*other.integer);
        }
        return *this;
    }
    void setter(int i)
    {
        *integer = i;
    }
    void dsiplay(){
        cout<<"value: "<<*integer<<endl;
    }
};
int main(){
    box box1(10);
    box1.dsiplay();
//since we hace created deep copy constructor shallow copy is impossible but if we shallow copy
// box box2=box1;
//box2.setter(20);
//box2.display();
//box1.display(); both would show 20 instead of 10 both values would be changed

//deep copy
box box2(box1);
box2.setter(20);
box2.dsiplay();
}