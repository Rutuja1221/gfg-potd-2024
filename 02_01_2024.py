class Solution:
    def maxSumWithK(self, a, n, k):
        prefix_sum = [0] * (n + 1)

        # Calculate prefix sum
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + a[i - 1]

        max_sum = float('-inf')
        min_prefix_sum = 0

        # Iterate through subarrays of size at least k
        for i in range(k, n + 1):
            current_sum = prefix_sum[i] - min_prefix_sum
            max_sum = max(max_sum, current_sum)
            min_prefix_sum = min(min_prefix_sum, prefix_sum[i - k + 1])

        return max_sum

    



#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        k = int(input())
        
        ob = Solution()
        print(ob.maxSumWithK(a, n, k))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends