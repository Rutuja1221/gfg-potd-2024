//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int N = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int ans = ob.TotalWays(N);
            System.out.println(ans);           
        }
    }
}

// } Driver Code Ends



class Solution {
    public int TotalWays(int N) {
        final int MOD = 1000000007;

        // Initialize two variables to store the count of ways for buildings and spaces for one side of the road
        long waysBuild = 1;
        long waysSpace = 1;

        // Calculate the count of ways for each position for one side of the road
        for (int i = 2; i <= N; i++) {
            // Buildings at the current position can only be added by extending the existing space at the previous position
            long currentBuild = waysSpace;

            // Spaces at the current position can be added by either adding a space to the previous building
            // or extending the existing space at the previous position
            long currentSpace = (waysBuild + waysSpace) % MOD;

            // Update the previous values for the next iteration
            waysBuild = currentBuild;
            waysSpace = currentSpace;
        }

        // Total ways for N plots on one side of the road is the sum of ways to construct a building and space at the last position
        long totalWaysOneSide = (waysBuild + waysSpace) % MOD;

        // Total ways for N plots on both sides of the road is the square of ways for one side
        int totalWays = (int) (totalWaysOneSide * totalWaysOneSide % MOD);

        return totalWays;
    }
}
