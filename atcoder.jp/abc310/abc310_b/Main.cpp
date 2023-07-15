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
    vector<int> p(n),c(n);
    vector<vector<bool>> flag(n,vector<bool> (200));
    rep(i,n) {
        cin >> p[i] >> c[i];
        rep(j,c[i]) {
            int f;
            cin >> f;
            flag[i][f]=true;
        }
    }
    bool check=false;
    rep(i,n) rep(j,n) {
        if(p[i]<p[j]) continue;
        bool f=true,g=false;
        rep(k,150) {
            if(flag[i][k]&&!flag[j][k]) f=false;
            if(flag[j][k]&&!flag[i][k]) g=true;
        } 
        if(!f) continue;
        if(p[i]<=p[j]&&!g) continue;
        check=true;

    }
    cout << (check ? "Yes" : "No") << endl;
    return 0;
}