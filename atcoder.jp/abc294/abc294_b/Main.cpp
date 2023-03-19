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
    vector<vector<ll>> a(h,vector<ll> (w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) {
        rep(j,w) {
            if(a[i][j]==0) cout << ".";
            else cout << char('A'+a[i][j]-1);
        }
        cout << endl;
    }
    return 0;
}