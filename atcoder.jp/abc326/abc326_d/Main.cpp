#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n; string r,c;
    cin >> n >> r >> c;
    // if(r[0]!=c[0]) {
    //     cout << "No" << endl;
    //     return 0;
    // }
    vector<vector<char>> ans(n,vector<char> (n,'.'));
    string st="ABC.";
    bool flag=false;
    auto dfs = [&](auto dfs, int y, int x, vector<vector<char>> &p) -> void {
        if(flag) return;
        bool check=true;
        string cr,cc;
        rep(i,n) {
            cr+='.';
            cc+='.';
        }
        rep(i,n) {
            rep(j,n) if(cr[j]=='.'&&p[i][j]!='.') cr[j]=p[i][j]; 
            rep(j,n) if(cc[j]=='.'&&p[j][i]!='.') cc[j]=p[j][i]; 
        }
        rep(i,n) {
            if(cr[i]!='.'&&cr[i]!=c[i]) check=false;
            if(cc[i]!='.'&&cc[i]!=r[i]) check=false;
        }
        rep(i,y) {
            map<char,int> mpx; 
            rep(j,n) if(p[i][j]!='.') mpx[p[i][j]]++;
            if((int)mpx.size()!=3) check=false;
            for(auto u:mpx) if(u.second!=1) check=false;
        }
        if(y>=n-1) {
            rep(i,x) {
                map<char,int> mpy; 
                rep(j,n) if(p[j][i]!='.') mpy[p[j][i]]++;
                if((int)mpy.size()!=3) check=false;
                for(auto u:mpy) if(u.second!=1) check=false;
            }
        }
        if(!check) return;
        if(y==n) {
            flag=true;
            cout << "Yes" << endl;
            rep(i,n) {
                rep(j,n) cout << p[i][j];
                cout << endl;
            }
            return;
        }
        rep(i,4) {
            p[y][x]=st[i];
            if(x+1==n) dfs(dfs,y+1,0,p);
            else dfs(dfs,y,x+1,p);
        }
    };
    vector<vector<char>> p(n,vector<char> (n,'.'));
    dfs(dfs,0,0,p);
    if(!flag) cout << "No" << endl;
    return 0;
}