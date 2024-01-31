//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[], int N) {
        int result = 0;

        for (int i = 0; i < 32; i++) {  // Considering each bit position
            int sum = 0;

            for (int j = 0; j < N; j++) {
                if ((arr[j] >> i) & 1) {
                    sum++;
                }
            }

            // If the sum is not a multiple of 3, set the corresponding bit in the result
            if (sum % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends