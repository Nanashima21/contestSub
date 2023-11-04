#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<vector<int>> a(9,vector<int> (9));
    rep(i,9) rep(j,9) cin >> a[i][j];
    bool flag=true;
    rep(i,9) {
        set<int> sx,sy;
        rep(j,9) sx.insert(a[i][j]);
        rep(j,9) sy.insert(a[j][i]);
        if((int)sx.size()!=9) flag=false;
        if((int)sy.size()!=9) flag=false;
    }
    rep(x,3) rep(y,3) {
        set<int> se;
        rep(i,3) rep(j,3) {
            int cx=x*3+i,cy=y*3+j;
            se.insert(a[cx][cy]);
        }
        if((int)se.size()!=9) flag=false;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}