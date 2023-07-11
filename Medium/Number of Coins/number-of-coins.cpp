//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int recur(int sum,int i,int coins[],int M,vector<vector<int>>&dp)
	{
	    if(sum<0 or i==M)
	        return 1e8;
	    if(sum==0)
	        return 0;
	    if(dp[i][sum]!=-1)
	        return dp[i][sum];
	    int pick=recur(sum-coins[i],i,coins,M,dp)+1;
	    int not_pick=recur(sum,i+1,coins,M,dp);
	    return dp[i][sum]=min(pick,not_pick);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    if(recur(V,0,coins,M,dp)>=1e8)
	    return -1;
	    return recur(V,0,coins,M,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends