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
    int q;
    cin >> q;
    int d,k;
    string s = "a", t = "a";
    string x;
    ll s_len = 1, t_len = 1;
    char top = 'a';
    char pop = 'a';
    for(int i = 0; i < q; i++){
        cin >> d >> k >> x;
        if(d == 1){
            if(pop == 'a'){
                for(auto& elem: x){
                    if(elem != 'a'){
                        pop = elem;break;
                    }
                }
            }
            s_len+= k * x.length();
        }
        else{
            if(top == 'a'){
                for(auto& elem: x){
                    if(elem != 'a'){
                        top = elem;break;
                    }
                }
            }
             t_len+= k * x.length();
        }
        if(top != 'a'){
            cout << "YES\n";continue;
        }
            
        if(pop == 'a' && s_len < t_len) cout << "YES\n"; 
        else cout << "NO\n";        
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