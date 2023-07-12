//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
     int solve(string &s1,string &s2,int m,int n,vector<vector<int>>&dp,int &ans)
   {
       if(m<0 or n<0)
       {
           return 0;
       }
       if(dp[m][n]!=-1)
       {
           return dp[m][n];
       }
       int take=0;
       int t=0;
       int t1=0;
       if(s1[m]==s2[n])
       {
            take=1+solve(s1,s2,m-1,n-1,dp,ans);
           // return dp[m][n]= 1+solve(s1,s2,m-1,n-1,dp);
           // ans=max(ans,take);
           // dp[m][n]=take;
           // return take;
       }
       // else
       // {
           t=solve(s1,s2,m-1,n,dp,ans);
           t1=solve(s1,s2,m,n-1,dp,ans);
           ans=max(ans,take);
           return dp[m][n]=take ;
       // }
   }
   int longestCommonSubstr (string s1, string s2, int n, int m)
   {
       // your code here
       int ans=INT_MIN;
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       int res= solve(s1,s2,n-1,m-1,dp,ans);
       return ans;
   }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends