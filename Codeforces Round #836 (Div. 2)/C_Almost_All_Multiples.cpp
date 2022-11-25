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

bool checkPrime(int number) { 
    if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i=3; (i*i) <= number; i+=2) {
        if (number % i == 0 ) return false;
    }
    return true;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vi a(n+1, 0);
    a[1] = x;
    a[n] = 1;
    if(checkPrime(n) && a[1] != n){
        cout << -1;
        return;
    }
    else{
        for(auto i = 1; i <= n; i++)
            a[i] = i;
        a[1] = x;
        a[x] = n;
        a[n] = 1;
        for(auto i = 2; i <= n-1; i++){
            int j = i;
            while(j < n){
                if(a[i]%j == 0 && a[j]%i == 0 && a[j]<=a[i]) swap(a[i], a[j]);
                j+= i;
            }
        }
        for(auto i = 1; i < n; i++){
            if(a[i]%i != 0){
                cout << -1; return;
            }
        }
        for(auto i = 1; i <= n; i++)
            cout << a[i] << " ";
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