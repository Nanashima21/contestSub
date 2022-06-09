#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<vector<int>> c(3,vector<int> (3));
    rep(i,3) rep(j,3) cin >> c[i][j];
    bool flag=true;
    rep(i,3) {
        for(int j=i+1;j<3;j++) {
            int x=c[i][0]-c[j][0];
            rep(k,3) {
                if(c[i][k]-c[j][k]!=x) flag=false;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}