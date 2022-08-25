#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int n,m,q;
vector<int> a,b,c,d;
ll ma=0;

void dfs(vector<int> &v,int cnt) {
    if(cnt==n) {
        ll tot=0;
        rep(i,q) if(v[b[i]]-v[a[i]]==c[i]) tot+=d[i];
        ma=max(ma,tot);
    } else {
        for(int i=v.back();i<=m;i++) {
            v.push_back(i);
            dfs(v,cnt+1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    rep(i,q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }
    for(int i=1;i<=m;i++) {
        vector<int> v(1,i);
        dfs(v,1);
    }
    cout << ma << endl;
    return 0;
}