//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            long a;
            a = Long.parseLong(br.readLine().trim());
            
            
            long b;
            b = Long.parseLong(br.readLine().trim());
            
            Solution obj = new Solution();
            long res = obj.sumOfPowers(a, b);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends




class Solution {
    public static long sumOfPowers(long a, long b) {
        // function to calculate the sum of powers of primes
        long sum = 0;
        for (long i = a; i <= b; i++) {
            sum += getPrimePowersSum(i);
        }
        return sum;
    }

    // function to calculate the sum of powers of primes for a single number
    private static long getPrimePowersSum(long num) {
        long sum = 0;

        for (long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                int count = 0;
                while (num % i == 0) {
                    num /= i;
                    count++;
                }
                sum += count;
            }
        }

        if (num > 1) {
            sum += 1; // num is a prime number
        }

        return sum;
    }
}
        
