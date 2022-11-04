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
    cin >> n;
    vi ans(n);
    if(n < 4){
        for(int i = 1; i <= n; i++){
            cout << i << " ";
        }
        return;
    }
    if(n % 2 == 0){
        int i = 1;
        int temp = n;
        while(i < n){
            ans[i] = temp;
            temp--;
            i = i+2;
        }
        i = 0;
        while(i < n){
            ans[i] = temp;
            temp--;
            i = i+2;
        }
    }
    else{
        int i = 0;
        int temp = n;
        while(i < n){
            ans[i] = temp;
            temp--;
            i = i+2;
        }
        i = 1;
        while(i < n){
            ans[i] = temp;
            temp--;
            i = i+2;
        }
    }
    for(auto i = 0; i < n; i++)
        cout << ans[i] << " ";
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