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
    vector<vector<int>> g(n,vector<int> ());
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    } 
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(0);
    vector<bool> flag(n,false);
    flag[0]=true;
    vector<int> ans;
    while(!pq.empty()) {
        int cv=pq.top();
        ans.push_back(cv+1);
        pq.pop();
        for(auto nv:g[cv]) {
            if(flag[nv]) continue;
            flag[nv]=true;
            pq.push(nv);
        }
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}