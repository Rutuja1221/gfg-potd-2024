//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.lang.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();
            Solution ob = new Solution();
            int ans = ob.smallestSubstring(S);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

class Solution {
    public int smallestSubstring(String S) {
        int[] count = new int[3]; // to store count of 0, 1, and 2
        int left = 0; // left pointer of the window
        int minLength = Integer.MAX_VALUE; // to store the minimum length of the substring

        for (int right = 0; right < S.length(); right++) {
            char currentChar = S.charAt(right);
            count[currentChar - '0']++;

            // Move the left pointer to minimize the window
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                minLength = Math.min(minLength, right - left + 1);
                char leftChar = S.charAt(left);
                count[leftChar - '0']--;
                left++;
            }
        }

        return (minLength == Integer.MAX_VALUE) ? -1 : minLength;
    }
}