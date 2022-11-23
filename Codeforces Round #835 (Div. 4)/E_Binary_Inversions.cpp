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
 
 
ll calculateCount(vi &s){
    ll count = 0, ans = 0;
    int n = s.size();
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 0) count++;
        else ans+= count;
    }
    return ans;
 
}
void solve(){
    int n;
    cin >> n;
    vi s(n);
    cin >> s;
    ll ans = calculateCount(s);
    for(auto i = 0; i < n; i++){
        if(s[i] == 0){
            s[i] = 1;
            ll val1 = calculateCount(s);
            ans = max(val1, ans);
            s[i] = 0;
            break;
        }
    }
    for(auto i = n-1; i >= 0; i--){
        if(s[i] == 1){
            s[i] = 0;
            ll val2 = calculateCount(s);
            ans = max(val2, ans);
            s[i] = 1;
            break;
        }
    }
    cout << ans;
}
 
int main(){
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        std::cout << nl;
    }
    
    return 0;
}