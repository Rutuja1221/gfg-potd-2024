//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        if (nums.size() % 2 != 0) {
            // If the array size is odd, it's not possible to form pairs.
            return false;
        }

        unordered_map<int, int> remainderFreq;

        // Count the frequency of each remainder when dividing by k.
        for (int num : nums) {
            int remainder = (num % k + k) % k;
            remainderFreq[remainder]++;
        }

        // Check if the frequency of each remainder is valid for forming pairs.
        for (auto& entry : remainderFreq) {
            int remainder = entry.first;
            int freq = entry.second;

            if (remainder == 0) {
                // For remainder 0, the frequency should be even.
                if (freq % 2 != 0) {
                    return false;
                }
            } else if (2 * remainder == k) {
                // For remainder k/2, the frequency should be even.
                if (freq % 2 != 0) {
                    return false;
                }
            } else {
                // For other remainders, the frequency of remainder and k-remainder should match.
                if (remainderFreq[k - remainder] != freq) {
                    return false;
                }
            }
        }

        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends