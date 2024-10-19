//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
     int n = str.size();
        int lastDigit = str[n - 1] - '0'; 
        
        if (lastDigit > 5) {
            int carry = 1;
            str[n - 1] = '0';
            
           
            for (int i = n - 2; i >= 0 && carry; i--) {
                int digit = str[i] - '0';
                digit += carry;
                
                if (digit == 10) {
                    str[i] = '0'; 
                } else {
                    str[i] = '0' + digit;
                    carry = 0; 
                }
            }
            
            if (carry) {
                str = "1" + str;
            }
        } else {
            str[n - 1] = '0';
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends