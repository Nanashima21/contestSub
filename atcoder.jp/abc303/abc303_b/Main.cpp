#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int> > flag(n,vector<int> (n,0));
    rep(i,m) {
        vector<int> a(n);
        rep(j,n) cin >> a[j];
        rep(j,n-1) {
            flag[a[j]-1][a[j+1]-1]++;
            flag[a[j+1]-1][a[j]-1]++;
        } 
    }
    int cnt=0;
    rep(i,n) rep(j,n) {
        if(i==j) continue;
        if(flag[i][j]==0) cnt++;
    }
    cout << cnt/2 << endl;
    return 0;
}