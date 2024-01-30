//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int R, int C)
    {
        vector<int> result;
        unordered_set<string> rowSet;

        for (int i = 0; i < R; ++i)
        {
            string rowString = "";
            for (int j = 0; j < C; ++j)
            {
                rowString += to_string(matrix[i][j]);
            }

            // Check if the rowString is already in the set
            if (rowSet.count(rowString) > 0)
            {
                result.push_back(i);
            }
            else
            {
                rowSet.insert(rowString);
            }
        }

        return result;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends