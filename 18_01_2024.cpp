//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int min_sprinklers(int gallery[], int n) {
        vector<pair<int, int>> sprinklers;

        // Step 1: Initialize the sprinklers array
        for (int i = 0; i < n; i++) {
            if (gallery[i] >= 0) {
                sprinklers.push_back({i - gallery[i], i + gallery[i]});
            }
        }

        // Step 2: Sort the sprinklers array based on their start points
        sort(sprinklers.begin(), sprinklers.end());

        int ans = 0;
        int i = 0;
        int target = 0;

        // Step 3: Greedy approach to select the minimum number of sprinklers
        while (i < n) {
            if (target >= n) break;  // Gallery is covered

            int maxRange = -1;

            // Find the sprinkler with the maximum coverage that starts before or at the target
            while (i < n && sprinklers[i].first <= target) {
                maxRange = max(maxRange, sprinklers[i].second);
                i++;
            }

            if (maxRange == -1) {
                // No sprinkler covers the current target, return -1
                return -1;
            }

            ans++;
            target = maxRange + 1;  // Move to the next uncovered position
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends