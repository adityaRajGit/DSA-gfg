//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) 
    {
          int sum=0;
        for(auto i: arr) sum+=i;
        if((d+sum)%2 != 0) return 0;
        int t=(d+sum)/2;
        //REDUCED: find count of subset with sum equal to t
        vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<n+1; i++) {
            for(int j=0; j<t+1; j++) {
                if(arr[i-1] <= j) 
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]])%1000000007;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][t]; // this will be answer
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends