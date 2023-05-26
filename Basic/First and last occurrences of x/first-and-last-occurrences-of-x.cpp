//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans={-1,-1};
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        while(start<=end)   //1st Occurence
        {
            mid=start+(end-start)/2;
            
            if(arr[mid]==x)
            {ans[0]=mid;end=mid-1;}
            else if(arr[mid]>x)
                end=mid-1;
            else
                start=mid+1;
        }
        start=0,end=n-1;
        while(start<=end)    //last occurence
        {
            mid=start+(end-start)/2;
            if(arr[mid]==x)
            {ans[1]=mid;start=mid+1;}
            else if(arr[mid]>x)
                end=mid-1;
            else
                start=mid+1;
        }
        return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends