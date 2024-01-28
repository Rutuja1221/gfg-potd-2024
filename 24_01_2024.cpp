#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& edgeCount) {
        visited[node] = true;
        edgeCount += adj[node].size(); // Counting edges for later check

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, edgeCount);
            }
        }
    }

    int isTree(int n, int m, vector<vector<int>>& edges) {
        if (m != n - 1) {
            // Number of edges should be equal to (number of nodes - 1) for a tree
            return 0;
        }

        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int edgeCount = 0;

        dfs(0, adj, visited, edgeCount);

        // Check if the graph is connected and has no cycles
        for (bool nodeVisited : visited) {
            if (!nodeVisited) {
                return 0; // Graph is not connected
            }
        }

        // Check if the graph has no cycles (edges counted twice in undirected graph)
        return (edgeCount / 2 == n - 1) ? 1 : 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
