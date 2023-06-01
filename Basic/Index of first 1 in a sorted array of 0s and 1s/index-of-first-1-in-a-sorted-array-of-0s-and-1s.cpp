//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int firstIndex(int a[], int n) 
    {
        if(n==1 && a[0]==0){
            return -1;
        }
        if(a[0]==1){
            return 0;
        }
        
        if(a[1]==1){
            return 1;
        }
        
        int start=0,end=n-1,ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(a[mid]==1)
            {
                ans=mid;
                end=mid-1;
            }
            else if(a[mid]<1)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}
// } Driver Code Ends