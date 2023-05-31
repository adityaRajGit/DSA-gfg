//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    int binsearch(int arr[],int l,int r,int x)
    {
        if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at
        // one of the middle 3 positions
        if (arr[mid] == x)
            return mid;
        if (mid > l && arr[mid - 1] == x)
            return (mid - 1);
        if (mid < r && arr[mid + 1] == x)
            return (mid + 1);
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binsearch(arr, l, mid - 2, x);
 
        // Else the element can only be present
        // in right subarray
        return binsearch(arr, mid + 2, r, x);
    }
 
    // We reach here when element is not present in array
    return -1;
    }
    
    vector <int> nearlySorted(int arr[], int n, int K)
    {
        vector<int>v;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
            if(q.size()>K)
            {
                v.push_back(q.top());
                q.pop();
            }
        }
        while(!q.empty())
        {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends