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
    int m;
    char matrix[2][m];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m; i++)
            cin >> matrix[i][j];
    }
    int vis[2][m];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m; i++)
            vis[i][j] = 0;
    }
    int i = 0, j = 0;
    if(matrix[i][j] == 'W') i++;
    while(true){
        if(matrix[i][j] == 'B'){
            vis[i][j] = 1;
            if(i == 0){
                if(matrix[i+1][j] == 'B'){
                    i++;continue;
                }
                if(j<m && matrix[i][j+1] == 'B'){
                    j++; continue;
                }
            }
            if(i==1){
                if(matrix[i-1][j] == 'B'){
                    i--;continue;
                }
                if(j<m && matrix[i][j+1] == 'B'){
                    j++; continue;
                }

            }
        }
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