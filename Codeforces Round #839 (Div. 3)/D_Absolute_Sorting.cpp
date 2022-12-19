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
    vll a(n);
    cin >> a;
    vll temp1 = a, temp2 = a;
    sort(all(temp1));
    sort(temp2.rbegin(), temp2.rend());
    if(temp1 == a){
        cout << 0; return;
    }
    else if(temp2 == a){
        cout << a[0]; return;
    }
    else{
        int mount_count = 0;
        for(int i = 1; i < n-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]) mount_count++;
            if(a[i] < a[i-1] && a[i] < a[i+1]) mount_count++;
        }
        if(mount_count > 1){
            cout << -1; return;
        }
        for(auto i = 1; i < n-1; i++){
            int l = a[i-1], m = a[i], r = a[i+1];
            if(m > l && m > r){
                if((l+m)%2 == 0 && m/2 > r){
                    cout << (l+m)/2; return;
                }
            }
            if(m < l && m < r){
                if((l+m)%2 == 0 && m*2 < r){
                    cout << (l+m)/2; return;
                }
        }
    }
    set<int> hehe;
    for(auto i = 0; i < n; i++){
        hehe.insert(a[i]);
    }
    if(hehe.size() == 2){
        ll sum = 0;
        for(auto it = hehe.begin(); it != hehe.end(); it++)
            sum+= *it;
        if(sum%2 == 0){
            cout << sum/2;
            return;
        }
    }
    cout << -1;
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