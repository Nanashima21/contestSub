#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int> ());
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
    }
    int cnt=0;
    rep(i,n) {
        queue<int> q;
        q.push(i);
        vector<bool> flag(n,false);
        flag[i]=true;
        cnt++;
        while(!q.empty()) {
            int cv=q.front();
            q.pop();
            for(auto u:v[cv]) {
                if(flag[u]) continue;
                flag[u]=true;
                q.push(u);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}