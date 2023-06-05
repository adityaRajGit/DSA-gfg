//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        int prev2 = 0;
        int prev1 = 1;
        
        for(int i=2;i<=n;i++){
            int curr = (prev2 + prev1) % 1000000007;
            prev2  = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends