#include <iostream>
#include <cmath>
using namespace std;
class Test
{
public:
    float r, area ;
    int area1;
    float a,b,c;
    float s = (a+b+c)*0.5;
    void input()
    {
        cout << "Enter radius of a circle:"<<endl;
        cin >> r;
        cout << "Enter the three sides of the triangle\n";
        cin >> a >> b >> c;
    }
    void findArea()
    {
        area = 3.14 * r * r;
        area1 = sqrt(s*(s-a)*(s-b)*(s-c));
    }
    void display()
    {
        cout << "Area of circle is :" << area<<endl;
        cout << "Area of Triangle :" << area1;
    }
};
int main()
{
    Test obj;
    obj.input();
    obj.findArea();
    obj.display();
    return 0;
}
