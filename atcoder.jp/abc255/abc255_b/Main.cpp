#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,k;
    cin >> n >> k;
    vector<ll> a(k);
    rep(i,k) {
        cin >> a[i];
        a[i]--;
    }
    vector<ll> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    double l=0.0,r=1000000.0;
    while(r-l>1e-6) {
        double mid=(l+r)/2.0;
        vector<bool> flag(n,false);
        rep(i,k) {
            rep(j,n) {
                ll d=(x[a[i]]-x[j])*(x[a[i]]-x[j])+(y[a[i]]-y[j])*(y[a[i]]-y[j]);
                double dist=sqrt(d);
                if(mid>=dist) flag[j]=true;
            }
        }
        bool check=true;
        rep(i,n) if(!flag[i]) check=false;
        if(check) r=mid;
        else l=mid;
    }
    printf("%.16f\n",l);
    return 0;
}