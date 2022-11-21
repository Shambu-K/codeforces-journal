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
    vi s(n);
    cin >> s;
    vi lmost = s, rmost = s;
    int i  = 0;
    while(true){
        if(lmost[i] == 0){
            lmost[i] = 1; break;
        } 
        i++;
    }
    int j = n-1;
    while(true){
        if(rmost[j] == 1){
            rmost[j] = 0; break;
        } 
        j--;
    }
    
    if(n==1){
        std::cout << 0; return;
    }
    if(n==2){
        std::cout << 1; return;
    }
    int ans = 0;
    vi zero_count(n, 0);
    for(int i = n-2; i >= 0; i--){
        if(lmost[i+1] == 0) zero_count[i] = 1+zero_count[i+1];
        else zero_count[i] = zero_count[i+1];
    }
    int sum = 0;
    for(auto i = 0; i < n; i++){
        if(lmost[i] == 1) sum+= zero_count[i];
    }
    ans = max(ans, sum);
    int sum2 = 0;
    vi dup(n, 0);
    for(int i = n-2; i >= 0; i--){
        if(rmost[i+1] == 0) dup[i] = dup[i+1]+1;
        else dup[i] = dup[i+1]; 
    }
    for(auto i = 0; i < n; i++){
        if(rmost[i] == 1) sum2+= dup[i];
    }    
    ans = max(sum2, ans);
    std::cout << ans;
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