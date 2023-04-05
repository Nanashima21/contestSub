#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int> (n-1));
    vector<queue<int>> q(n);
    rep(i,n) rep(j,n-1) {
        cin >> a[i][j];
        a[i][j]--;
        q[i].push(a[i][j]);
    }
    set<pair<int,int>> se1;
    rep(i,n) {
        int j=q[i].front();
        if(q[j].front()==i) se1.insert({min(i,j),max(i,j)});
    }
    int ans=0;
    while(!se1.empty()) {
        ans++;
        set<pair<int,int>> se2;
        for(auto u:se1) {
            int a=u.first;
            int b=u.second;
            q[a].pop();
            q[b].pop();
            if(!q[a].empty()) {
                int v=q[a].front();
                if(!q[v].empty()&&q[v].front()==a) se2.insert({min(a,v),max(a,v)});
            }
            if(!q[b].empty()) {
                int v=q[b].front();
                if(!q[v].empty()&&q[v].front()==b) se2.insert({min(b,v),max(b,v)});
            }
        }
        swap(se1,se2);
    }
    rep(i,n) if(!q[i].empty()) ans=-1;
    cout << ans << endl;
    return 0;
}