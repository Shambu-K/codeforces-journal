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
    cin >> m;
    char matrix[2][m];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m; i++){
            cin >> matrix[i][j];
        }
    }
    int vis[2][m];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m; i++)
            vis[i][j] = 0;
    }
    int x = 0, y = 0;
    if(matrix[0][0] == 'W') x++;
    if(matrix[0][m-1] == 'B' && matrix[1][m-1] == 'B'){
        while(vis[0][m-1] != 1 || vis[1][m-1] != 1){
            vis[x][y] = 1;
            if(x == 0){
                //go down or right
                //going down
                if(vis[x+1][y] == 0 && matrix[x+1][y] == 'B') x++;
                //going right
                else if(y < m-1 && matrix[x][y+1] == 'B') y++;
                else break;
            }
            else{
                //go up or right
                //going up
                if(vis[x-1][y] == 0 && matrix[x-1][y] == 'B') x--;
                //going right
                else if(y<m-1 && matrix[x][y+1] == 'B') y++;
                else break;
                
            }
        }

    }
    else{
        int a = 0;
        if(matrix[a][m-1] != 'B') a++;
        while(vis[a][m-1] != 1){
            vis[x][y] = 1;
            if(x == 0){
                //go down or right
                //going down
                if(vis[x+1][y] == 0 && matrix[x+1][y] == 'B') x++;
                //going right
                else if(y < m-1 && matrix[x][y+1] == 'B') y++;
                else break;
            }
            else{
                //go up or right
                //going up
                if(vis[x-1][y] == 0 && matrix[x-1][y] == 'B') x--;
                //going right
                else if(y<m-1 && matrix[x][y+1] == 'B') y++;
                else break;
                
            }
        }
    }
    int check = 0;
    for(auto i = 0; i < 2; i++){
        for(auto j = 0; j < m; j++)
            if(vis[i][j] == 0) check++;
    }
    if(check > 0) cout << "YES";
    else cout << "NO";   
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