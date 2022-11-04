#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()			{std::sort(this->begin(), this->end());}
    void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
    auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define all(v)                   v.begin(), v.end()

#define F  first
#define S  second
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;


void solve(){
    int n;
    // int temp = n;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        cout << 1 << " " << 2;
        return;
    }
    int minop = n/2;
    if(n%2 == 0) cout << minop;
    else cout << minop + 1;
    cout << "\n";
    int l = 2;
    int r;
    if(n%2 == 0) r = n*3;
    else r = (n-1)*3; 
    for(int i = 0; i < n/2; i++){
        cout << l << " " << r << "\n";
        l+= 3;
        r-= 3;
    }
    if(n%2 != 0) cout << l << " " << n*3; //in case n is odd, one extra operation
}

int main(){
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}