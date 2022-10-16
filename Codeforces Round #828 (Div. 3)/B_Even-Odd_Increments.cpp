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
    int n,q;
    cin >> n >> q;
    long long  sum = 0;
    int eve_count = 0, odd_count = 0;
    vi a(n);
    for(auto i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]% 2 == 0) eve_count++;
        else odd_count++;
        sum += a[i];
    }
    int type, x;
    for(auto i = 0; i < q; i++){
        cin >> type >> x;
        if(type == 1){
            sum+= odd_count*x;
            if(x % 2 != 0){
                eve_count = eve_count+odd_count;
                odd_count = 0;
            }  
        }
        else {
            sum+= eve_count*x;
            if(x % 2 != 0){
                odd_count = odd_count + eve_count;
                eve_count = 0;
            } 
        }
         

        cout << sum << "\n";

    }
}

int main(){
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        // cout << nl;
    }
    
    return 0;
}