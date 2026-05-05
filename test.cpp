//first neagative in every window of size k
class Solution {
public:
    vector<int> firstNegative(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = 0;
        vector<int> ans;

        while (r < n) {
            if (arr[r] < 0) {
                ans.push_back(arr[r]);
            }

            if (r - l + 1 > k) {
                if (arr[l] < 0) {
                    ans.erase(ans.begin());
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};

//brute force approach first neagative in every window of size k using dequeue
class Solution {
public:    vector<int> firstNegative(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            int firstNeg = 0;
            for (int j = i; j < i + k; j++) {
                if (arr[j] < 0) {
                    firstNeg = arr[j];
                    break;
                }
            }
            ans.push_back(firstNeg);
        }
        return ans;
    }
};

//optimal force approach first neagative in every window of size k using dequeue
class Solution {
public:    vector<int> firstNegative(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                dq.push_back(i);
            }

            if (i >= k - 1) {
                if (!dq.empty() && dq.front() < i - k + 1) {
                    dq.pop_front();
                }
                ans.push_back(dq.empty() ? 0 : arr[dq.front()]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        int n = arr.size();
        int l = 0, r = 0;
        vector<int> ans;
        deque<int> dq;

        while (r < n) {
            // Step 1: Add negative elements index
            if (arr[r] < 0) {
                dq.push_back(r);
            }

            // Step 2: When window size == k
            if (r - l + 1 == k) {
                // Store answer
                if (dq.empty()) {
                    ans.push_back(0);
                } else {
                    ans.push_back(arr[dq.front()]);
                }

                // Step 3: Slide window
                if (!dq.empty() && dq.front() == l) {
                    dq.pop_front();
                }

                l++;
            }

            r++;
        }

        return ans;
    }
};