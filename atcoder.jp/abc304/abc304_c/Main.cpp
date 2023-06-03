#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll f(ll a,ll b,ll c,ll d) {
    return (a-b)*(a-b)+(c-d)*(c-d);
}

int main() {
    ll n,d;
    cin >> n >> d;
    vector<ll> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<bool> flag(n,false);
    flag[0]=true;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int i=q.front();
        q.pop();
        rep(j,n) {
            if(i==j) continue;
            if(flag[j]) continue;
            if(f(x[i],x[j],y[i],y[j])<=(d*d)) {
                flag[j]=true;
                q.push(j);
            }
        }
    }
    rep(i,n) cout << (flag[i] ? "Yes" : "No") << endl;
    return 0;
}