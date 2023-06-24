#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int ha,wa;
    cin >> ha >> wa;
    vector<string> a(ha);
    rep(i,ha) cin >> a[i];
    int hb,wb;
    cin >> hb >> wb;
    vector<string> b(hb);
    rep(i,hb) cin >> b[i];
    int hx,wx;
    cin >> hx >> wx;
    vector<string> x(hx);
    rep(i,hx) cin >> x[i];

    rep(ax,20) rep(ay,20) rep(bx,20) rep(by,20) {
        vector<vector<char>> v(30,vector<char> (30,'.'));
        rep(i,ha) rep(j,wa) if(a[i][j]=='#') v[i+ax][j+ay]='#';
        rep(i,hb) rep(j,wb) if(b[i][j]=='#') v[i+bx][j+by]='#';
        bool flag=true;
        rep(i,hx) rep(j,wx) {
            if(x[i][j]!=v[i+10][j+10]) flag=false; 
            if(x[i][j]=='#'&&v[i+10][j+10]=='#') v[i+10][j+10]='.';
        }
        rep(i,30) rep(j,30) if(v[i][j]=='#') flag=false;
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    } 
    cout << "No" << endl;
    return 0;
}