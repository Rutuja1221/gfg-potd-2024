class Solution:
    def splitArray(self, arr, N, K):
        low, high = max(arr), sum(arr)
        
        while low < high:
            mid = (low + high) // 2
            count, curr_sum = 1, 0

            for num in arr:
                curr_sum += num

                if curr_sum > mid:
                    count += 1
                    curr_sum = num

            if count <= K:
                high = mid
            else:
                low = mid + 1

        return low






#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N,K=map(int,input().split())
        arr=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.splitArray(arr,N,K))
# } Driver Code Ends