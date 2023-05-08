//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int arr1[], int arr2[], int n) {
            int m = n;
       int i = 0;
       int j = 0;
       int count = 0;
       int idx = (n+m) / 2;
       int sum = 0;
       while(i<n && j<n) {
           if(arr1[i] <= arr2[j]) {
               count++;
               if (count == idx) sum += arr1[i];
               if (count == idx + 1) {sum += arr1[i]; break;}
               i++;
           } else {
               count++;
               if (count == idx) sum += arr2[j];
               if (count == idx + 1) {sum += arr2[j]; break;}
               j++;
           }
       }
       while(i<n && count <= idx+1) {
           count++;
           if (count == idx) sum += arr1[i];
           if (count == idx + 1) {sum += arr1[i]; break;}
           i++;
       }
       while(j<m && count <= idx+1) {
           count++;
           if (count == idx) sum += arr2[j];
           if (count == idx + 1) {sum += arr2[j]; break;}
           j++;
       }
       return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends