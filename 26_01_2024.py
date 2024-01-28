//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

// } Driver Code Ends
//User function Template for Java
//User function Template for Java
class Solution {
    boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int solve(int Num1, int Num2) {
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();

        queue.offer(Num1);
        visited.add(Num1);

        int distance = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                int current = queue.poll();

                if (current == Num2) {
                    return distance;
                }

                // Generate neighbors by changing a single digit
                for (int j = 1; j <= 1000; j *= 10) {
                    for (int k = 0; k < 10; k++) {
                        int neighbor = current - (current / j % 10) * j + k * j;

                        // Ensure the neighbor is a four-digit prime with no leading zeros
                        if (!visited.contains(neighbor) && isPrime(neighbor) && neighbor >= 1000) {
                            queue.offer(neighbor);
                            visited.add(neighbor);
                        }
                    }
                }
            }

            distance++;
        }

        // If no path is found
        return -1;
    }
}



//{ Driver Code Starts.
class GFG{
    public static void main(String args[]) throws IOException{
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input_line[] = read.readLine().trim().split("\\s+");
            int num1=Integer.parseInt(input_line[0]);
            int num2=Integer.parseInt(input_line[1]);
            
            Solution ob = new Solution();
            System.out.println(ob.solve(num1,num2));
        }
    }
}
// } Driver Code Ends
