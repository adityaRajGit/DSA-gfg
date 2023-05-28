//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int v[], int n, int x) {
	    int first_occurrences=-1;

       int start1=0;

        int end1=n-1;

        while (start1<=end1){

            int mid= start1+((end1-start1)/2);

            if(v[mid]==x){

               end1=mid-1;

               first_occurrences=mid;

            }

            else if(v[mid]>x){

                end1=mid-1;

            }

            else

            start1=mid+1;

       

        }

        

        int last_occurrences=-1;

        int start2=0;

        int end2=n-1;

        while (start2<=end2){

            int mid= start2+((end2-start2)/2);

            if(v[mid]==x){

               start2=mid+1;

               last_occurrences=mid;

            }

            else if(v[mid]>x){

                end2=mid-1;

            }

            else

            start2=mid+1;

       

        }

        if(last_occurrences !=-1 || first_occurrences !=-1 )

        return last_occurrences-first_occurrences+1;

        else 

        return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends