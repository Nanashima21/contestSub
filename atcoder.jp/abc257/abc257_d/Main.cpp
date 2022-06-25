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
    vector<ll> x(n),y(n),p(n);
    rep(i,n) cin >> x[i] >> y[i] >> p[i];
    ll l=-1,r=5e9;
    while(r-l>1) {
        ll mid=(l+r)/2;
        bool check=true;
        rep(i,n) {
            queue<int> q;
            q.push(i);
            vector<bool> flag(n,false);
            flag[i]=true;
            while(!q.empty()) {
                int c=q.front();
                q.pop();
                rep(j,n) {
                    if(flag[j]) continue;
                    if(mid*p[c]>=abs(x[c]-x[j])+abs(y[c]-y[j])) {
                        flag[j]=true;
                        q.push(j);
                    }
                }
            }
            check=true;
            rep(j,n) if(!flag[j]) check=false;
            if(check) break;
        }
        if(check) r=mid;
        else l=mid;
    } 
    cout << r << endl;
    return 0;
}