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
    vector<int> p(n),idx(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
        idx[p[i]]=i;
    }
    vector<int> nxt(n,-1);
    rep(i,n-1) if(idx[i]<idx[i+1]) nxt[i]=i+1;
    vector<bool> flag(n,false);
    int ma=1;
    rep(i,n) {
        if(flag[i]) continue;
        queue<int> q;
        q.push(i);
        int cnt=1;
        while(!q.empty()) {
            int cv=q.front();
            q.pop();
            if(flag[cv]) continue;
            flag[cv]=true;
            if(nxt[cv]==-1) break;
            q.push(nxt[cv]);
            cnt++;
        }
        ma=max(ma,cnt);
    } 
    cout << n-ma << endl;
    return 0;
}