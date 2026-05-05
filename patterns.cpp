#include <iostream>
using namespace std;
 
// floyd's triangle pattern

/*int main()
 {  
    int n=5;
    int num =1;
    for(int i=1 ; i<n ; i++)
    {
         for(int j =1 ; j<=i ; j ++)
         {
            cout<<num;
            num++;
         }
         cout<<endl;
    }
 }
*/


/* Butterfly

#include <iostream>
using namespace std ;

int main()
{
    int  n=8;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<< " * ";
        }
        for(int j=1;j<=2*(n-i);j++)
        {
            cout<<"   ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<" * "; 
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<< " * ";
        }
        for(int j=1;j<=2*(n-i);j++)
        {
            cout<<"   ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<" * "; 
        }
        cout<<endl;
    }

}

*/


 /* Q. Hollow Diamond

#include <iostream>
using namespace std ;

int main()
{
    int n=4;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            cout<< "*";
        }
        for(int j=1;j<=2*(i-1);j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=n-i+1;j++)
        {
            cout<< "*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<< "*";
        }
        for(int j=1;j<=2*(n-i);j++)
        {
            cout<<" ";
            
        }
        for(int j =1;j<=i;j++)
        {
            cout<<"*";
        }
        
        cout<<endl;
    }
}

*/


/*  Decreasing trainagle

#include <iostream>
using namespace std;

int main() {
    int n = 8;
    for (int i = 0; i < n; i++) 
    {
        for (int j = n - 1 - i; j >= 0; j--) {
            cout << j << " ";
        }
        cout << endl; 
    }
    
}
*/


//1-0 traingle 

/*#include <iostream>
using namespace std;
int num= true;
int n =5;
int main()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<num<<" ";
            num = !num;
        }
        cout<<endl;
    }
}
*/

 /* 
 ROMBUS PATTERN

 int main()
 {
    int n =5;
    for(int i =0; i<=n ; i++)
    {
       
        for(int j = 0 ; j<=n-i-1; j++)         
        {
            cout<<" ";
        }

        for(int j = 0 ; j<n; j++)
        {
               cout<<"*";

        }

        
     cout<<endl;
    }

 }
    