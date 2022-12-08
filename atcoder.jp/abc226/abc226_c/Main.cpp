#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<ll> t,tot;
vector<vector<int>> v;
vector<bool> flag;

void dfs(int pos) {
    ll res=t[pos];
    for(auto nv:v[pos]) {
        if(flag[nv]) continue;
        flag[nv]=true;
        dfs(nv);
        res+=tot[nv];
    }
    tot[pos]=res;
}

int main() {
    int n;
    cin >> n;
    t.resize(n);
    v.resize(n,vector<int> ());
    rep(i,n) {
        cin >> t[i];
        int k;
        cin >> k;
        rep(j,k) {
            int a;
            cin >> a;
            a--;
            v[i].push_back(a);
        }
    }
    tot.resize(n,0);
    flag.resize(n,false);
    flag[n-1]=true;
    dfs(n-1);
    cout << tot[n-1] << endl;
    return 0;
}