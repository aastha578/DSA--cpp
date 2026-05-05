vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; 
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        
        dq.push_back(i);

        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}


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

//find all the anagrams in the string using sliding window and frequency array
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> freqP(26, 0), freqS(26, 0);
        
        // store frequency of p
        for (char c : p) {
            freqP[c - 'a']++;
        }

        int k = p.size();
        int l = 0;
        vector<int> ans;

        for (int r = 0; r < s.size(); r++) {

            // add current character
            freqS[s[r] - 'a']++;

            // if window size exceeds k, remove left char
            if (r - l + 1 > k) {
                freqS[s[l] - 'a']--;
                l++;
            }

            // if window size == k, check
            if (r - l + 1 == k) {
                if (freqS == freqP) {
                    ans.push_back(l);
                }
            }
        }

        return ans;
    }
};


maximum consecutive ones in and array using sliding window approach
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < nums.size(); right++) 
        {
            if (nums[right] == 0) 
            {
                left = right + 1;
            }
             max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};


maximum consecutive ones using sliding window approach with  flipping at most k zeos

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int l=0;
        int r =0 ;
        int zcount=0;
        int max_len =0;
        for (int r = 0; r < nums.size(); r++) 
        {
            if (nums[r] == 0) 
            {
                 zcount++;
            }
            while (zcount > k) {
            if (nums[l] == 0) {
                zcount--;
            }
            l++;
        }
        
        max_len = max(max_len, r - l + 1);
    }

    return max_len;

    }
};



fruits into the baskets using sliding window approach
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;

            
            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};


#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    vector<int> freq(26, 0);  // since only lowercase letters
    int left = 0, max_len = 0;
    int distinct_count = 0;

    for (int right = 0; right < str.size(); right++) {
        // Add current character
        if (freq[str[right] - 'a'] == 0) {
            distinct_count++;
        }
        freq[str[right] - 'a']++;

        // Shrink if more than K distinct
        while (distinct_count > k) {
            freq[str[left] - 'a']--;
            if (freq[str[left] - 'a'] == 0) {
                distinct_count--;
            }
            left++;
        }

        // Update answer
        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}


#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    vector<int> freq(26, 0);
    int left = 0, max_len = 0;
    int distinct = 0;

    for (int right = 0; right < str.size(); right++) {

        if (freq[str[right] - 'a'] == 0) {
            distinct++;
        }
        freq[str[right] - 'a']++;

        while (distinct > k) {
            freq[str[left] - 'a']--;
            if (freq[str[left] - 'a'] == 0) {
                distinct--;
            }
            left++;
        }

        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k;
        string str;

        cin >> k;
        cin >> str;

        cout << kDistinctChars(k, str) << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    vector<int> freq(26, 0);
    int left = 0, max_len = 0, distinct = 0;

    for (int right = 0; right < str.size(); right++) {

        if (freq[str[right] - 'a'] == 0) {
            distinct++;
        }
        freq[str[right] - 'a']++;

        while (distinct > k) {
            freq[str[left] - 'a']--;
            if (freq[str[left] - 'a'] == 0) {
                distinct--;
            }
            left++;
        }

        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k;
        string str;

        cin >> k >> str;

        cout << kDistinctChars(k, str) << endl;
    }

    return 0;
}