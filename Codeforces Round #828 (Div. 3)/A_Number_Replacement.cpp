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
    for(auto i = 0; i < n; i++)
        cin >> a[i];
    string s;
    cin >> s;
    vi temp_a = a;
    string temp_s = s;
    sort(all(temp_a));
    int flag1 = 1, flag2 = 1;
    for(auto i = 0; i < n - 1; i++){
        if(temp_a[i] == temp_a[i+1]) flag1 = 0;
        if(temp_s[i] != temp_s[i+1]) flag2 = 0;
    }
    if(flag1 == 1 || flag2 == 1){
        cout << "YES";return;
    }
    vector<char> test(100,' ');
    for(auto i = 0; i < n; i++){
        if(test[a[i]] == ' ') test[a[i]] = s[i];
        else{
            if(test[a[i]] != s[i]){
                cout << "NO"; return;
            }
        }
    }
    cout << "YES";



    


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