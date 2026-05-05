#include <iostream>
using namespace std;
 

void m2(int &a ,int &b, int &c)
{
     a*=2;
    b*=2;
    c*=2;
}
int main()
{
    int x=1,y=2,z=3;
    m2(x,y,z);
    cout<<x<<y<<z<<"\n";
    return 0;
}