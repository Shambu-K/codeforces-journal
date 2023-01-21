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
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int z1 = 0, o1 = 0, z2 = 0, o2 = 0;
    for(auto i = 0; i < n; i++){
        if(a[i] == '0') z1++;
        else o1++;
    }
    for(auto i = 0; i < n; i++){
        if(b[i] == '0') z2++;
        else o2++;
    }
    int set1 = min(z1, o2);
    int set2 = min(z2, o1);
    int ans = set1+set2;
    for(auto i = 0; i < ans; i++)
        cout << '1';
    for(auto i = 0; i < n-ans; i++)
        cout << '0';
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