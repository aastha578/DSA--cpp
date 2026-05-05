/*#include <iostream>
using namespace std;
/*FIND the largest elemnt in the array 
int main()
{
    int arr[5]={5,4, 3, 9, 2};
    int max=arr[0];

    for(int i=0;i<5;i++)
    {  
        if(arr[i]>max)
        {
            max=arr[i];
        }

    }
    cout<<max;
    return 0;
}
*/

/* 
int main()
{  
   int  n ;
   cout<<"Enter the size of the array :";
   cin>>n;
   
   char arr[n];
   cout<<"Enter the elements of the array : ";
   for(int i=0;i<n;i++) 
   {
      cin>>arr[i];
   }

   int character ;
   cout<<"Enter the charcter to be searched in the array : ";
   cin>>character;


   for(int i =0;i<n;i++)
   {
      if(arr[i]==character)
      {
         cout<<"Character found at index "<<i;
      }
      else
      {
            cout<<"Character not found ";
      }
   }
}*/


/*Q 1 :Search an element in an array

#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, X;
    cin >> N >> X;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (A[i] == X) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
*/
/*
Q 2 : Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expected = n * (n + 1) / 2;

    int actual = 0;
    for (int i = 0; i < n; i++) {
        actual += nums[i];
    }

    return expected - actual;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << missingNumber(nums);

    return 0;
}

*/
/*
Q 3 : Given an integer x, return true if x is a palindrome, and false otherwise.


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        return x == reversedHalf || x == reversedHalf / 10;
    }
};


*/
/*
Q 4: Find maximum in an Array
Given a list of 
N
N integers, representing height of mountains. Find the height of the tallest mountain.

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T > 0) {
        int N;
        cin >> N;
        long long maxHeight = 0;
        for (int i = 0; i < N; i++) {
            long long h;
            cin >> h;

            if (h> maxHeight) {
                maxHeight = h;s
            }
        }
        cout<< maxHeight <<endl;
        T--; 
    }

    return 0;
}

*/
 

/* Linear search 

int linearSearch(int arr[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

int arr[] = {2, 4, 0, 1, 9};
int n=sizeof(arr)/sizeof(int);
int key ;
cout<<"Enter the element to be searched : ";
cin>>key;
int a;
a=linearSearch(arr,n,key);
cout<<"Element found at index "<<a;
}

*/


/*REVERSE AN ARRAY 

int main()
{
    int arr[]={5,4,3,2,1};
    int n =sizeof(arr)/sizeof(int);
    int reversed_arr[n];
    for(int i=n-1;i>=0; i--)
    {
        reversed_arr[i]=arr[n-i-1];
    }
    for (int i = 0; i < n; i++) {
        cout << reversed_arr[i] << " ";
    }
    return 0;
}

*/

// Reverse an array using 2 pointer approach 

/*int main()
{
    int arr[]={5,4,3,2,1};
    int n =sizeof(arr)/sizeof(int);
    int start=0;
    int end=n-1;
    int temp;
    while(start<end)
    {
       temp=arr[start];
       arr[start]=arr[end];
       arr[end]=temp;

        start++;
        end--;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
*/



/* BINARY SEARCH 

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n =sizeof(arr)/sizeof(int);
    int key;
    cout<<"Enter the value of key to be searched:";
    cin>>key;
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    if(arr[mid]==key)
    {
    cout<<"Element found at index : "<<mid;
    }
    else if(arr[mid]<key)
    {
        start=mid+1;
    }
    else 
    {
        end=mid-1;
    }
    return 0;
}

int main()
{
    int N ;
    cin>>N ;
    for(int i =1;i<= N; i++)
    {
        char s='A'+(N-i);
        char e='A'+(N-1);
        for(char ch= s ; ch<=e ; ch++)
        {
            cout<<ch ;
        }
         if (i != N)
         {
              cout << '\n'; 
          }
    }
     return 0;
}
*/

/* Second Largest Element in an Array  
int main()
{
    int arr[]={5,4,3,2,1};
    int n =sizeof(arr)/sizeof(int);
    int largest=arr[0];
    int second_largest=arr[0];

    for(int i=0;i<n;i++)
    {
       
        if(arr[i]>largest)
        second_largest=largest;
        largest=arr[i];
        
       
    }
}
*/

/*
MAXIMUM SUBARRAY
(bructe force approach)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];

        for(int i = 0; i < n; i++) {
            int currentSum = 0;

            for(int j = i; j < n; j++) {
                currentSum += nums[j];
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};

(Kadane's algorithm)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int current_sum = 0;
        int max_sum = nums[0];

        for(int val : nums) {
            current_sum += val;

            max_sum = max(max_sum, current_sum);

            if(current_sum < 0) {
                current_sum = 0;
            }
        }

        return max_sum;
    }
};
  

Two sum 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Indices: " << i << " " << j << endl;
                return 0; 
            }
        }
    }

    cout << "No pair found!" << endl;
    return 0;
}


*/

/*
Majority element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for(int val : nums) {
            int frequency = 0;

            for(int x : nums) {
                if(x == val) {
                    frequency++;
                }
            }

            if(frequency > n / 2) {
                return val;
            }
        }

        return -1;  // safety return
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int freq=1;
        int maj = nums[0];
        for(int i =1; i<n ;i++)
        {
            if(nums[i]==nums[i-1])
            {
                freq++;
            }
            else
            {
                freq =1 ;
                maj=nums[i];
            }
            if(freq >n/2)
            {
                 return maj;
            }
        }
        return maj ;
    }
};

remove duplicate elemets from the sorted arrray 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;  // position for next unique element

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

*/


/*
Niether minimum nor maximum element in an array
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        auto [mi, mx] = minmax_element(nums.begin(), nums.end());
        for (int x : nums) {
            if (x != *mi && x != *mx) {
                return x;
            }
        }
        return -1;
    }
};


Zero Moves 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                swap(nums[i], nums[k++]);
            }
        }
    }
};

*/

SWap colors in an array
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 =0, count1=0, count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count0++;
            else if(nums[i]==1)
                count1++;
            else
                count2++;
        }
        
        int i=0;
        while(count0>0)
        {
            nums[i++]=0;
            count0--;
        } 
        
        while(count1>0)
        {
            nums[i++]=1;
            count1--;
        }
        
        while(count2>0)
        {
            nums[i++]=2;
            count2--;
        }
        
    }
};
*/

/* 
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {   int n = nums.size();
        int l=0;
        int m=0;
        int h=n-1;
        
        while(m<=h)
        {
             if(nums[m]==0)
            {
                swap(nums[l],nums[m]);
                l++,m++;
            }
            else if(nums[m]=1)
            {
                m++;
            }
            else
            {
            swap(nums[m],nums[h]);
            h--;
            }
        }

    }

};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        for (int h = m * n; h; --h) {
            ans.push_back(matrix[i][j]);
            vis[i][j] = true;
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) {
                k = (k + 1) % 4;
            }
            i += dirs[k];
            j += dirs[k + 1];
        }
        return ans;
    }
};


function spirallyTraverse(mat) {
    const m = mat.length;
    const n = mat[0].length;
    
    const res = [];
    const vis = Array.from({length : m},
                           () => Array(n).fill(false));

    // Arrays to represent the changes in row and column
    // indices: turn right(0, +1), turn down(+1, 0), turn
    // left(0, -1), turn up(-1, 0)
    const dr = [ 0, 1, 0, -1 ];
    const dc = [ 1, 0, -1, 0 ];

    // Initial position in the matrix
    let r = 0, c = 0;

    // Initial direction index (0 corresponds to 'right')
    let idx = 0;

    for (let i = 0; i < m * n; ++i) {
    
        // Add current element to result array
        res.push(mat[r][c]);

        // Mark current cell as visited
        vis[r][c] = true;

        // Calculate the next cell coordinates based on
        // current direction
        const newR = r + dr[idx];
        const newC = c + dc[idx];

        // Check if the next cell is within bounds and not
        // visited
        if (newR >= 0 && newR < m && newC >= 0 && newC < n
            && !vis[newR][newC]) {
            r = newR;
            c = newC;
        }
        else {
        
            // Change direction (turn clockwise)
            idx = (idx + 1) % 4;
            r += dr[idx];
            c += dc[idx];
        }
    }

    return res;
}

// Driver Code
const mat = [
    [ 1, 2, 3, 4 ], 
    [ 5, 6, 7, 8 ], 
    [ 9, 10, 11, 12 ],
    [ 13, 14, 15, 16 ]
];

const res = spirallyTraverse(mat);
console.log(res.join(" "));




function spirallyTraverse(mat) {
    const m = mat.length;
    const n = mat[0].length;

    const res = [];

    // Initialize boundaries
    let top = 0, bottom = m - 1, left = 0, right = n - 1;

    // Iterate until all elements are printed
    while (top <= bottom && left <= right) {

        // Print top row from left to right
        for (let i = left; i <= right; ++i) {
            res.push(mat[top][i]);
        }
        top++;

        // Print right column from top to bottom
        for (let i = top; i <= bottom; ++i) {
            res.push(mat[i][right]);
        }
        right--;

        // Print bottom row from right to left (if exists)
        if (top <= bottom) {
            for (let i = right; i >= left; --i) {
                res.push(mat[bottom][i]);
            }
            bottom--;
        }

        // Print left column from bottom to top (if exists)
        if (left <= right) {
            for (let i = bottom; i >= top; --i) {
                res.push(mat[i][left]);
            }
            left++;
        }
    }

    return res;
}

// Driver Code
const mat = [[1, 2, 3, 4], 
             [5, 6, 7, 8], 
             [9, 10, 11, 12], 
             [13, 14, 15, 16]];

const res = spirallyTraverse(mat);
console.log(res.join(" "));



check Anagram 
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size()) return false ;
             
             vector<int>freqa(26,0);
             for(char alphabet: s)
             {
                    freqa[alphabet - 'a']++;

             }
             for(char alphabet: t)
             {
                    freqa[alphabet - 'a']--;
                    if(freqa[alphabet-'a']<0) 
                    {
                        return false;
                    }

             }
             return true ;
 }
};
 
/*using map 

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size()) return false ;
             
             unordered_map<char,int>mp;
             for(char alphabet: s)
             {
                    mp[alphabet - 'a']++;

             }
             for(char alphabet: t)
             {
                    mp[alphabet - 'a']--;
                    if(mp[alphabet-'a']<0) 
                    {
                        return false;
                    }

             }
             return true ;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};


217 .Contains Duplicate using sort

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
};

217 .Contains Duplicate using map

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > 1) {
                return true;
            }
        }
        
        return false;
    }
};


/* Matrix diagonal sum 
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int sum=0;
        int n = mat.size();
        for(int i =0;i<n;++i)
        {
            int j = n - i - 1;
            sum += mat[i][i] + (i == j ? 0 : mat[i][j]);
        }
        return sum;
    }
};
*/


/*  
BINARY SEARCH USING UPPER AN LOWER BOUND 


class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) 
    {
        int n = arr.size();
        int l =0 , h=n-1;
        int ans = -1;
        
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            
            if(arr[mid]==k)
            {
                ans = mid;
                h= mid-1 ;
            }
            else if(arr[mid]>k)
            {
                h=mid-1;
            }
            else 
            {
                l=mid+1;
            }
            
        }
        return ans;
   
    }
};

*/

/* */
#LOWER BOUND PROBLEM  -BINARY SEARCH 

class Solution 
{
  public:
    int lowerBound(vector<int>& arr, int target) 
    {
        int n =arr.size();
        int l = 0;
        int h= n - 1 ;
        
        int ans = n;
        
        while(l<=h)
        {
             int mid = l+(h-l)/2;
                if(arr[mid]>=target)
                {
                        ans=mid;
                        h=mid-1;
                }
                else
                {
        
                    l= mid+1;
                }
    
        }
    
    return ans ;
    }
};
*/

 /* 35. serach position insert 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
           int mid =l+(r-l)/2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

*/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1ll) >> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};

left, right = 1, x
first_true_index = -1

while left <= right:
    mid = (left + right) // 2
    if mid > x // mid:  # feasible: mid * mid > x (overflow-safe)
        first_true_index = mid
        right = mid - 1
    else:
        left = mid + 1




Find the smallest letter greater than target in a sorted array of characters
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return letters[left % letters.size()];
    }
};



/* Find th perfect square 
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == num)
                return true;
            else if (square < num)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
*/



class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) return k;
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] - mid - 1 >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1);
    }
};


class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        for(int x: arr)
        {
            if(x<= k) k++;
            else 
            {
                break ;
            }
            
        }
         return  k ;
    }
   
};


class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        for(int x: arr)
        {
            if(x<= k) k++;
            else 
            {
                break ;
            }
            
        }
         return  k ;
    }
   
};

//sliding window 

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = 0;
        int maxsum = INT_MIN;
        int winsum = 0;

        while (r < n) {
            winsum += arr[r]; 

            if (r - l + 1 > k) {
                winsum -= arr[l];
                l++;
            }

            if (r - l + 1 == k) {
                maxsum = max(maxsum, winsum);
            }

            r++;
        }

        return maxsum;
    }
};


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
    
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        double maxSum = windowSum;
        
    
        for (int i = k; i < n; i++) {
            windowSum += nums[i];      
            windowSum -= nums[i - k];   
            
            maxSum = max(maxSum, windowSum);
        }
        
       
        return maxSum / k;
    }
};




class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        double maxsum = INT_MIN;   
        double winsum = 0;      

        while (r < n) {
            winsum += nums[r];  
            if (r - l + 1 > k) {
                winsum -= nums[l];
                l++;
            }

           
            if (r - l + 1 == k) {
                maxsum = max(maxsum, winsum);
            }

            r++;
        }

      
        return maxsum / k;
    }
};