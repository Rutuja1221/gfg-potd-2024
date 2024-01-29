//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];

        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }

        return mat;
    }

    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }

    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            String St[] = br.readLine().split(" ");
            int N = Integer.parseInt(St[0]);
            int K = Integer.parseInt(St[1]);
           
            int[] arr = IntArray.input(br, N);
            
            Solution obj = new Solution();
            ArrayList<ArrayList<Integer>> res = obj.kTop(arr, N, K);
            
            IntMatrix.print(res);
            
        }
    }
}

// } Driver Code Ends




class Solution {
    public static ArrayList<ArrayList<Integer>> kTop(int[] arr, int N, int K) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> {
            int freqA = freqMap.get(a);
            int freqB = freqMap.get(b);
            if (freqA == freqB) {
                return Integer.compare(a, b);
            }
            return Integer.compare(freqB, freqA);
        });

        for (int i = 0; i < N; i++) {
            int num = arr[i];
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
            maxHeap.clear();
            maxHeap.addAll(freqMap.keySet());

            ArrayList<Integer> currentTopK = new ArrayList<>();
            int count = 0;
            while (!maxHeap.isEmpty() && count < K) {
                int currentNum = maxHeap.poll();
                currentTopK.add(currentNum);
                count++;
            }
            result.add(currentTopK);
        }

        return result;
    }
}

        