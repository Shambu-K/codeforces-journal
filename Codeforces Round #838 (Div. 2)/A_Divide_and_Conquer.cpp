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
    vi a(n);
    cin >> a;
    vi odd_elems;
    vi eve_elems;
    for(auto i = 0; i < n; i++){
        if(a[i] %2 != 0) odd_elems.push_back(a[i]);
        else eve_elems.push_back(a[i]);
    }
    if(odd_elems.size() % 2 == 0){
        cout << 0; return;
    }
    else{
        int size1 = odd_elems.size();
        int ans = INT_MAX;
        for(auto i = 0; i < size1; i++){
            int temp = 0;
            while(odd_elems[i] %2 != 0){
                odd_elems[i]/= 2;
                temp++;
            }
            ans = min(ans, temp);
        }
        int size2 = eve_elems.size();
        for(auto i = 0; i < size2; i++){
            int temp = 0;
            while(eve_elems[i] %2 == 0){
                eve_elems[i]/= 2;
                temp++;
            }
            ans = min(ans, temp);
        }
        cout << ans;
    }
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