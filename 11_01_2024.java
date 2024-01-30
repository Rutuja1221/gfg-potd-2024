//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String S = sc.next();
            int K = sc.nextInt();
            Solution obj = new Solution();
            System.out.println(obj.removeKdigits(S, K));
        }
    }
}

// } Driver Code Ends



class Solution {
    public String removeKdigits(String S, int K) {
        int len = S.length();
        char[] result = new char[len];
        int top = 0;

        for (char digit : S.toCharArray()) {
            while (K > 0 && top > 0 && result[top - 1] > digit) {
                top--;
                K--;
            }

            // Skip pushing leading zeroes onto the result
            if (top == 0 && digit == '0') {
                continue;
            }

            result[top++] = digit;
        }

        // Handle cases where K removals are not exhausted
        int remainingDigits = top - K;
        top = Math.max(0, remainingDigits);

        // If the result is empty, return "0"
        if (top == 0) {
            return "0";
        }

        // Construct the final result string from the array
        return new String(result, 0, top);
    }
}
