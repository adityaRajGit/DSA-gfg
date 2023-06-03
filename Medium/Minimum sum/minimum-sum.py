#User function Template for python3

class Solution:
    def solve(self, arr, n):
        arr.sort()
        a = 0
        b = 0
        for i in range(0,n):
            if i%2:
                a = a*10 + arr[i]
            else:
                b = b*10 + arr[i]
        return a+b


#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.solve(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends