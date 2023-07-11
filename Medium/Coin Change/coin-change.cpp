//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {
            long long int tb[m+1][n+1];
        for(int i=0;i<=m;i++){
            tb[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            tb[0][i] = 0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(S[i-1]<=j){
                    tb[i][j] = tb[i][j-S[i-1]]+tb[i-1][j];
                }
                else{
                    tb[i][j] = tb[i-1][j];
                }
            }
        }
        return tb[m][n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends