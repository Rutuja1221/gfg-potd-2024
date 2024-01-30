class Solution:
    def numberSequence(self, m, n):
        MOD = 10**9 + 7
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        # Base case: There is one way to create a sequence of length 1 with any value less than or equal to m
        for i in range(1, m + 1):
            dp[1][i] = 1

        # Filling up the dp table
        for i in range(2, n + 1):
            for j in range(1, m + 1):
                # For each value, consider the sum of all possibilities from the previous value
                for k in range(j * 2, m + 1):
                    dp[i][k] = (dp[i][k] + dp[i - 1][j]) % MOD

        # Sum up all possibilities for sequences of length n
        result = sum(dp[n]) % MOD

        return result




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        arr = input().split()
        m = int(arr[0])
        n = int(arr[1])
        
        ob = Solution()
        print(ob.numberSequence(m, n))
# } Driver Code Ends