// C++ program to find Sum
// of GCD over all subarrays
  
#include <bits/stdc++.h>
using namespace std;
  
//int a[100001];
int SparseTable[100001][100001];
  
// Build Sparse Table
void buildSparseTable(vector<long long>& a, int n)
{
    for (int i = 0; i < n; i++) {
        SparseTable[i][0] = a[i];
    }
    // Building the Sparse Table for GCD[L, R] Queries
    for (int j = 1; j <= 19; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            SparseTable[i][j] = __gcd(SparseTable[i][j - 1], 
                    SparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}
  
// Utility Function to calculate GCD in range [L,R]
int queryForGCD(int L, int R)
{
    int returnValue;
      
    // Calculating where the answer is 
    // stored in our Sparse Table
    int j = int(log2(R - L + 1));
      
    returnValue = __gcd(SparseTable[L][j], 
                    SparseTable[R - (1 << j) + 1][j]);
                      
    return returnValue;
}
  
// Utility Function to find next-farther 
// position where gcd is same 
int nextPosition(int tempGCD, int startPointer, 
                            int prevEndPointer, int n)
{
    int high = n - 1;
    int low = prevEndPointer;
    int mid = prevEndPointer;
    int nextPos = prevEndPointer;
      
    // BinarySearch for Next Position 
    // for EndPointer
    while (high >= low) {
          
        mid = ((high + low) >> 1);
          
        if (queryForGCD(startPointer, mid) == tempGCD) {
            nextPos = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
      
    return nextPos + 1;
}
  
// Utility function to calculate 
// sum of gcd 
long long calculateSum(vector<long long>& a, int n)
{
    buildSparseTable(a, n);
      
    long long endPointer, startPointer, prevEndPointer, tempGCD;
      
    long long tempAns = 0;
      
    for (auto i = 0; i < n; i++) {
        // Initializing all the values
        endPointer = i;
        startPointer = i;
        prevEndPointer = i;
        tempGCD = a[i];
        while (endPointer < n) {
  
            // Finding the next position for endPointer
            endPointer = nextPosition(tempGCD, startPointer, 
                                            prevEndPointer, n);
  
            // Adding the suitable sum to our answer
            long long tempSum = ((endPointer - prevEndPointer) * tempGCD);
            tempSum*= tempSum%998244353;
            tempSum*= tempSum%998244353;
            tempSum*= tempSum%998244353;
            tempAns += (tempSum)%998244353;
  
            // Changing prevEndPointer
            prevEndPointer = endPointer;
  
            if (endPointer < n) {
                // Recalculating tempGCD
                tempGCD = __gcd(tempGCD, a[endPointer]);
            }
        }
    }
    return tempAns;
}

void solve(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(auto i = 0; i < n; i++)
        cin >> a[i];
    long long ans = calculateSum(a, n);
    cout << ans << "\n";
}
  
// Driver Code
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
      
      
    return 0;
}