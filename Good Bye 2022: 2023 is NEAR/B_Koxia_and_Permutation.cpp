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
    int n, k;
    cin >> n >> k;

    if(n == 1){
        cout << 1; return;
    }
    if(n == 2){
        cout << "1 2"; return;
    }
    if(n == 3){
        cout << "3 1 2"; return;
    }
    cout << n << " " << 1 << " ";
    map<int, int> vals;
    vals[1]++;
    vals[2]++;
    vals[n]++;
    vals[n-1]++;
    int i = n-2;
    while(i > 2){
        if(vals[i] == 0) cout << i << " ", vals[i]++;   
        if(vals[n+1-i] == 0){
            cout << n+1-i << " ";
            vals[n+1-i]++;
            i--;
        }
        else break;
    }
    cout << 2 << " " << n-1;

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