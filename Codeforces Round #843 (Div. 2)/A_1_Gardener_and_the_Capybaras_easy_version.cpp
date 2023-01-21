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
    string s;
    cin >> s;
    int n = s.length();
    for(auto i = 1; i < n-1; i++){
        if(s[i] == 'a'){
            string a = s.substr(0, i);
            string b = "a";
            string c = s.substr(i+1, n-i);
            cout << a << " " << b << " " << c;
            return;
        }
    }
    if(s[0] == 'a' && s[n-1] == 'a'){
        string b = s.substr(1, n-2);
        cout << "a " << b << " a"; return;
    }
    if(n == 3 && s[1] == 'b'){
        cout << s[0] << " " << s[1] << " " << s[2]; return;
    }
    for(auto i = 1; i < n-2; i++){
        if(s[i] == 'b' && s[i] == s[i+1]){
            string b = s.substr(i, n-2);
            cout << s[0] << " " << b << " " << s[n-1];
            return;
        }
    }
    cout << ": (";
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