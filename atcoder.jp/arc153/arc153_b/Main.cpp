#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int q;
    cin >> q;
    int idxh=0,idxw=0;
    rep(i,q) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(idxh<=a) idxh=a-idxh;
        else idxh=h-idxh+a;
        if(idxw<=b) idxw=b-idxw;
        else idxw=w-idxw+b;
    }
    vector<vector<char>> ans(h,vector<char> (w,'a'));
    if(q%2==0) {
        rep(i,h) {
            rep(j,w) {
                int cx=(i+idxh)%h,cy=(j+idxw)%w;
                ans[cx][cy]=s[i][j];
            } 
        }
    } else {
        rep(i,h) {
            rep(j,w) {
                int cx=(-i+idxh+h)%h,cy=(-j+idxw+w)%w;
                ans[cx][cy]=s[i][j];
            } 
        }
    }
    rep(i,h) {
        rep(j,w) {
            cout << ans[i][j];
        } cout << endl;
    }
    return 0;
}