//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++
#define rep(i,n) for(int i=0;i<(n);++i)

class Solution {
  public:
  
        int findTargetSumWaysArray(vector<int>& nums, int N , int D )
    {
	    int sum = 0;
    
        int zero = 0;
    rep(i,N)
    {
        if(nums[i] == 0) zero++;
    }

	if (D < 0) {D = D * (-1); } // if difference is negative

	rep(i, N) sum = sum + nums[i]; // sum of vector

	if ((sum + D) % 2 == 0) // if partition is even 
	{
		sum = (sum + D) / 2;
		int t[N + 1][sum + 1];

		rep(i, N + 1)
		{
			t[i][0] = 1;
		}

		for (int j = 1 ; j < sum + 1 ; j++)
		{
			t[0][j] = 0;
		}


		for (int i = 1; i < N + 1 ; i++)
		{
			for (int j = 1 ; j < sum + 1 ; j++)
			{
				if (nums[i - 1] <= j && nums[i-1]!=0)
				{
					t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j]; //subset sum difference
				}
				else
				{
					t[i][j] = t[i - 1][j];
				}
			}
		}



		return pow(2,zero)*t[N][sum];


	}
        
	else // if partition is odd
	{
		return 0;
	}

}
  
    int findTargetSumWays(vector<int>&A ,int target) {
        int N = A.size();
	return findTargetSumWaysArray(A , N , target);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends