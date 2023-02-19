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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans=INF;
    vector<ll> v;
    v.push_back(-1);
    v.push_back(1);
    v.push_back(a[0]);
    v.push_back(-a[0]);
    for(ll j:v) {
        if(j==0) continue;
        vector<ll> tot(n,0);
        ll cnt=abs(a[0]-j);
        tot[0]=j;
        for(int i=1;i<n;i++) tot[i]+=tot[i-1]+a[i];
        ll d=0;
        for(int i=1;i<n;i++) {
            tot[i]+=d;
            if(tot[i]>0&&tot[i-1]<0) continue;
            if(tot[i]<0&&tot[i-1]>0) continue;
            if(tot[i-1]<0) {
                d+=-tot[i]+1;
                cnt+=-tot[i]+1;
                tot[i]=1;
            } else {
                d-=tot[i]+1;
                cnt+=tot[i]+1;
                tot[i]=-1;
            }
        }
        ans=min(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}