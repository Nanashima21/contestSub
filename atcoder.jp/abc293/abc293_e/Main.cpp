#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b, ll m) {
    int n=(int)a.size();
    vector<vector<ll>> ret(n,vector<ll> (n));
    rep(i,n) rep(j,n) rep(k,n) {
        ret[i][j]+=a[i][k]*b[k][j];
        ret[i][j]%=m;
    }
    return ret;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> a, ll b, ll m) {
    int n=(int)a.size();
    vector<vector<ll>> ret(n,vector<ll> (n));
    rep(i,n) ret[i][i]=1;
    while(b) {
        if(b&1) ret=mat_mul(ret,a,m);
        a=mat_mul(a,a,m);
        b>>=1;
    }
    return ret;
}

int main() {
    ll a,x,m;
    cin >> a >> x >> m;
    vector<vector<ll>> f={{a,1},{0,1}};
    auto g=mat_pow(f,x,m);
    cout << g[0][1] << endl;
    return 0;
}