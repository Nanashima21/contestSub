#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int> (n,0));
    vector<vector<int>> b(n,vector<int> (n,0));
    rep(i,n) rep(j,n) cin >> a[i][j];
    rep(i,n) rep(j,n) cin >> b[i][j];
    bool flag=false;
    rep(_,4) {
        vector<vector<int>> v(n,vector<int> (n,0));
        rep(i,n) rep(j,n) v[n-j-1][i]=a[i][j];
        bool check=true;
        rep(i,n) rep(j,n) {
            if(v[i][j]&&!b[i][j]) check=false;
        }
        if(check) flag=true;
        a=v;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}