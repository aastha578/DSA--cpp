#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for(int val : vec)
    {
        cout << val << " ";
    }

    cout << endl;
    cout<<*(vec.begin())<<endl;

    cout<<*(vec.end()-1)<<endl;
    while(!vec.empty())
    {
        cout << "popped value is " << vec.back() << endl;
        vec.pop_back();
    }


    cout << endl;

    

    vector<int> vec2(3,10);

    for(int val : vec2)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}