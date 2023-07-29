#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n-8) rep(j,m-8) {
        bool flag=true;
        rep(x,4) rep(y,4) {
            if(x==3||y==3) {
                if(s[i+x][j+y]=='#') flag=false;
            } else {
                if(s[i+x][j+y]=='.') flag=false; 
            }
        }
        rep(x,4) rep(y,4) {
            if(x==0||y==0) {
                if(s[i+x+5][j+y+5]=='#') flag=false;
            } else {
                if(s[i+x+5][j+y+5]=='.') flag=false; 
            }
        }
        if(flag) cout << i+1 << " " << j+1 << endl;
    }
    return 0;
}