#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// User function Template for C++
class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // Create a 2D array to store minimum multiplications
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Parenthesis table to store the optimal order of parenthesis
        vector<vector<string>> parenthesis(n, vector<string>(n, ""));

        // Initialize the dp array with 0 for single matrix
        for (int i = 1; i < n; i++) {
            dp[i][i] = 0;
            parenthesis[i][i] = char('A' + i - 1);
        }

        // Fill the dp array using bottom-up approach
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int //{ j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k <= j - 1; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        parenthesis[i][j] = "(" + parenthesis[i][k] + parenthesis[k + 1][j] + ")";
                    }
                }
            }
        }

        return parenthesis[1][n - 1];
    }
};


//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends