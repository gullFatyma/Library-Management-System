#include<iostream>
using namespace std;

class shape
 {
 public:
 float x,y;
 void show()
 {
    cout<<" I am shape...."<<endl;
 }
 };
 class circle :public shape
 {
    public:
    void show()
 {
    cout<<" I am circle...."<<endl;
 }

 };
 class Rectangle :public shape
 {
    public:
    void show()
 {
    cout<<" I am Rectangle...."<<endl;
 }
 float calculate(float l , float w)
 {
   return l*w;
 }
 };
 class Myself: public shape,Rectangle
 {
public:
void show()
{
    cout<<"I am myself"<<endl;
}
 };
 int main()
{
    shape b;
    Rectangle r;
    circle c;
    Myself m;
    b.show();
    cout<<"=============="<<endl;
    r.show();
    cout<<"..."<<r.calculate(34.3,34.5);
    cout<<"=============="<<endl;
    c.show();
    shape* s=&r;
    cout<<"=============="<<endl;
    s->show();
    cout<<"=============="<<endl;
    m.show();
    m.x;//ambiguity .....dimond problem would occur....
    return 0;
}