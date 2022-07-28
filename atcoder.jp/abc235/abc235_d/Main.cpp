#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll f(string s) {
    ll res=0;
    rep(i,(int)s.size()) res=res*10+(s[i]-'0');
    return res;
}

int main() {
    ll a,n;
    cin >> a >> n;
    const ll inf=1e6;
    vector<ll> dis(inf,-1);
    dis[1]=0;
    queue<ll> q;
    q.push(1);
    while(!q.empty()) {
        ll v=q.front();
        q.pop();
        if(v>=inf) continue;
        if(v*a<inf&&dis[v*a]==-1) {
            dis[v*a]=dis[v]+1;
            q.push(v*a);
        }
        if(v>=10&&v%10!=0) {
            string s=to_string(v);
            char c=s.back();
            s=c+s.substr(0,(int)s.size()-1);
            ll nv=f(s);
            if(nv<inf&&dis[nv]==-1) {
                dis[nv]=dis[v]+1;
                q.push(nv);
            }
        }
    }
    cout << dis[n] << endl;
    return 0;
}