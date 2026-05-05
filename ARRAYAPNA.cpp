subarray problems
#include <iostream>
#include <vector>   
using namespace std;
void printsubaaray( int *arr , int n)
{
    for(int start=0 ; start< n ; start++)
    {
        for(int end = start ;end<n ; end++)
        {
            //cout<<"("<<start<<","<<end<<")"<<" ";
            for(int i = start ; i<=end; i++)
            {
                cout<<arr[i];
            }
            cout<<" , ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[]={1,2,3 , 4 , 5};
    int n =sizeof(arr)/sizeof(int);
    printsubaaray(arr,n);
    return 0;
}

time complexity : O(n^3)
space complexity : O(1) for function and O(n) for array



Print maximum subarray sum

1. BRUTE FORCE APPROACH

#include <iostream>
using namespace std;

void printMaxSubArray( int *arr , int n )
{   
    int maxSum = INT_MIN;
    for(int start =0 ; start<n ; start++)
    {
        for(int end =start ; end<n ; end++)
        {
            int currSum =0 ;
            for(int i =start ; i<=end ;i++)
            {
                currSum+=arr[i];
            }
            cout<<currSum <<" ";
            maxSum = max(maxSum , currSum);
        }   
        cout<<endl;

    }
    cout<<"Max sum is : "<<maxSum<<endl ;
}
int main()
{
    int arr[]={2 , -3 ,6 ,-5 ,4,2};
    int n =sizeof(arr)/sizeof(int);
    printMaxSubArray(arr,n);
    return 0;
}

2. optimized approach
#include <iostream>
using namespace std;

void printMaxSubArray2( int *arr , int n )
{   
    int maxSum = arr[0];
    for(int start =0 ; start<n ; start++)
    {
        int currSum = 0;
        for(int end =start ; end<n ; end++)
        {
            
            currSum = currSum + arr[end];
            maxSum = max(maxSum , currSum);
        }   
        cout<<endl;

    }
    cout<<"Max sum is : "<<maxSum<<endl ;
}
int main()
{
    int arr[]={2 , -3 ,6 ,-5 ,4,2};
    int n =sizeof(arr)/sizeof(int);
    printMaxSubArray2(arr,n);
    return 0;
}


buy and sell stock problem
#include <iostream>
#include <climits>
using namespace std;

void maxProfit(int *prices, int n)
{
    int bestbuy[100000];
    bestbuy[0] = INT_MAX;

    for(int i = 1; i < n; i++)
    {
        bestbuy[i] = min(bestbuy[i-1], prices[i-1]);
    }
   int maxProfit =0;
    for(int i =1 ; i<n ; i++)
    {
        int currProfit = prices[i] - bestbuy[i];
         maxProfit = max(maxProfit , currProfit);
        
    }
    cout << "Max profit is: " << maxProfit << endl;

}

int main()
{
    int prices[] = {7,1,5,3,6,4};  
    int n = sizeof(prices)/sizeof(int);

    maxProfit(prices, n);
    return 0;
}