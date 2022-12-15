#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<vector<int>> g;
vector<int> col,ng;

int main() {
    int n;
    cin >> n;
    map<pair<int,int>,int> mp;
    g.resize(n,vector<int> ());
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        mp[{a,b}]=i;
        mp[{b,a}]=i;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    col.resize(n-1);
    ng.resize(n);
    queue<pair<int,int>> q;
    q.push({0,-1});
    int num=1;
    while(!q.empty()) {
        int cv=q.front().first;
        int par=q.front().second;
        num=1;
        q.pop();
        for(auto nv:g[cv]) {
            if(nv==par) continue;
            if(ng[cv]==num) num++;
            col[mp[{cv,nv}]]=num;
            ng[nv]=num;
            num++;
            q.push({nv,cv});
        }
    } 
    cout << *max_element(all(col)) << endl;
    for(auto u:col) cout << u << endl;
    return 0;
}