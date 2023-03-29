//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    vector<int> c(nums.begin(),nums.end());
	    sort(c.begin(),c.end());
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++)
	    {
	        mp[nums[i]]=i;
	    }
	    
	    int pos=0;
	    int cnt=0;
	    for(int i=0;i<n;i++)
	    {
	        if(nums[i]!=c[i])
	        {
	            auto it=mp.find(c[i]);
	            pos = it->second;
	            swap(nums[i],nums[pos]);
	            cnt++;
	            mp[nums[pos]]=pos;
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends