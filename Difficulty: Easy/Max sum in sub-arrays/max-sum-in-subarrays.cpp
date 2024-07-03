//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends


class Solution {
  public:
    long long pairWithMaxSum(long long arr[], long long N) {
        // Your code goes here
        long long maxsum=0,sum=0;
        if(N == 1)return arr[0];
        for(int i=0;i<N-1;i++){
            sum=arr[i]+arr[i+1];
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};


//{ Driver Code Starts.
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.pairWithMaxSum(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends