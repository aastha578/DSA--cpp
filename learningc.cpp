#include <iostream>
using namespace std;

int main() {
    

    for(int i=1;i<=4;i++)
    {
        cout<<"*"<<" ";
        for(int j=1;j<=3;j++)
        {
            if(i=2 && j=1 && i=2 && j=5)
            {
                cout<<"*" <<" ";   
            }
            else
            {
                cout<<" "<<" ";
            }
        }


        cout<<"*"<<" ";
    }
   
}


class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push_back(c);
            else if (stk.empty() || !match(stk.back(), c))
                return false;
            else
                stk.pop_back();
        }
        return stk.empty();
    }

    bool match(char l, char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }
};

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> s;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int val = arr[i];
            while (!s.empty() && s.top() <= val) s.pop();
            arr[i] = s.empty() ? -1 : s.top();
            s.push(val);
        }
        return arr;
    }
};