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

bool check(){
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    int ans = n;
    vector<int> frnds[n+1];
    for(auto i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        frnds[a].push_back(b);
        frnds[b].push_back(a);
    }
    for(auto i = 0; i < n+1; i++)
        sort(all(frnds[i]));
    int add = 0;
    for(auto i = 1; i <= n-1; i++){
        auto j = i+1;
        int node = n+1;
        for(j = i+1; j <= n; j++){
            if(frnds[j][0] < j){
                node = j;break;
            } 
        }
        add+= node-1-i;
    }
    cout << ans+add;
     
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