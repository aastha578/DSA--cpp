// Implentation of stack using vector
#include <iostream>
#include <climits>
#include <vector>
using namespace std;


class stack 
{
    vector<int> vec ;

public:
      void push(int val){
        vec.push_back(val);
      }
      void pop(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return ;
        }   
        vec.pop_back();
      }

      int top(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return -1;
        }
           int lastidx = vec.size() - 1;
           return vec[lastidx];
      }

      bool isEmpty(){
        return vec.size() == 0;

      }

};


int main()
{
    stack s;

    s.push(1);
    s.push(2);
    s.push(3);  
    cout<<s.top()<<endl; // 3
    

    while(!s.isEmpty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0 ;
}


//implementation of stack using arrays 
#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            arr[top] = x;
            cout << "Inserted: " << x << endl;
        }
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "Deleted: " << arr[top] << endl;
            top--;
        }
    }

    // Peek operation
    void peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.peek();

    return 0;
}

// implementation of stack using template and vector
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

template<class T>
class stack 
{
    vector<T> vec ;

public:
      void push(T val){
        vec.push_back(val);
      }
      void pop(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return ;
        }   
        vec.pop_back();
      }

      T top(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return -1;
        }
           int lastidx = vec.size() - 1;
           return vec[lastidx];
      }

      bool isEmpty(){
        return vec.size() == 0;

      }

};


int main()
{
    stack <int>s;

    s.push(1);
    s.push(2);
    s.push(3);  
    cout<<s.top()<<endl; // 3
    

    while(!s.isEmpty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0 ;
}

// implementation of stack using template and list
#include <iostream>
#include <climits>
#include <vector>
#include<list>
using namespace std;

template<class T>
class stack 
{
    list<T>ll ;

public:
      void push(T val){
        ll.push_front(val);
      }
      void pop(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return ;
        }   
        ll.pop_front();
      }

      T top(){
        if(isEmpty()){
            cout<<"Stack is empty "<<endl;
            return -1;
        }
           return ll.front();
      }

      bool isEmpty(){
        return ll.size()==0;;

      }

};


int main()
{
    stack <int>s;

    s.push(1);
    s.push(2);
    s.push(3);  
    cout<<s.top()<<endl; // 3
    

    while(!s.isEmpty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0 ;
}


//implementation of stack using template and linked list without using stl
#include <iostream>
using namespace std;

template<class T>
class node {
public:
    T data;
    node<T>* next;

    node(T val) {
        data = val;
        next = NULL;
    }
};

template<class T>
class stack {
    node<T>* head;

public:
    stack() {
        head = NULL;
    }

    void push(T val) {
        node<T>* newnode = new node<T>(val);

        newnode->next = head;
        head = newnode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            throw runtime_error("Empty stack");
        }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl; // 3

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}



#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>st;
    st.push(1);
    st.push(2); 
    st.push(3);

    while(!st.empty())
    {
       int x= st.top();
        st.pop();
        cout<<x<<" ";
    }
    return 0;

}

/* leetcode 20 : Vlid parentheses
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

*/

Previous smaller element
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) 
    {
     int n =arr.size();
     vector<int> ans(n,-1);
     stack<int>st;
     for (int i =0 ; i<n;i++)
     {
         while(!st.empty()  && st.top()>=arr[i])
         {
             st.pop();
         }
         if(!st.empty())
         {
             ans[i]=st.top();
             
         }
         st.push(arr[i]);
     }
     return ans;
      
    }
};
 
previous greater element
class Solution {
  public:
    vector<int> prevGreater(vector<int>& arr) 
    {
     int n =arr.size();
     vector<int> ans(n,-1);
     stack<int>st;
     for (int i =0 ; i<n;i++)
     {
         while(!st.empty()  && st.top()<=arr[i])
         {
             st.pop();
         }
         if(!st.empty())
         {
             ans[i]=st.top();
             
         }
         st.push(arr[i]);
     }
     return ans;
      
    }
};

Daily temperatures
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> st; // Stack to store indices of temperatures

        for (int i = 0; i < n; i++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx; // Calculate the number of days until a warmer temperature
            }
            st.push(i); // Push current index onto the stack
        }
        return ans;
    }
};

largest rectangle in histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

class Solution {
public:
    // Next Smaller Element (Right)
    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    // Previous Smaller Element (Left)
    vector<int> pse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsei = nse(heights);
        vector<int> psei = pse(heights);

        int n = heights.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int w = nsei[i] - psei[i] - 1;
            int area = h * w;
            maxi = max(maxi, area);
        }

        return maxi;
    }
};

time complexity : O(5n)
space complexity : O(n) for stack and O(n) for ans vector ie 2n 


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];
                st.pop();

                int nse = i;  
                int pse = st.empty() ? -1 : st.top();

                int w = nse - pse - 1;
                int area = h * w;

                maxi = max(maxi, area);
            }
            st.push(i);
        }

        
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int w = nse - pse - 1;
            int area = h * w;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};

maximal rectangle in binary matrix
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxArea = 0;
        int n = matrix[0].size();
        vector<int> heights(n, 0);

        for (const auto& row : matrix) {
            for (int i = 0; i < n; i++) {
                heights[i] = row[i] == '1' ? heights[i] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int w = nse - pse - 1;
                maxi = max(maxi, h * w);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int w = nse - pse - 1;
            maxi = max(maxi, h * w);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int nr = matrix.size();
        if (nr == 0) return 0;

        int nc = matrix[0].size();
        vector<int> arr(nc, 0);
        int maxrec = 0;

        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (matrix[i][j] == '1')
                    arr[j] += 1;   // build height
                else
                    arr[j] = 0;    // reset height
            }

            int area = largestRectangleArea(arr);
            maxrec = max(maxrec, area);
        }

        return maxrec;
    }
};

longest valid parentheses
class Solution {    
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Initialize with -1
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};