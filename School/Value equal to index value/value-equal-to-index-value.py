#User function Template for python3
class Solution:

	def valueEqualToIndex(self,arr, n):
	    val = []
        for i,n in enumerate(arr,start=1):
            if i==n:
                val.append(n)
        return val


#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.valueEqualToIndex(arr, n)
        if len(ans) == 0:
            print("Not Found")
        else:
            for x in ans:
                print(x, end=" ")
            print()
        tc -= 1

# } Driver Code Ends