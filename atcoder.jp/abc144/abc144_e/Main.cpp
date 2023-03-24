#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(rall(a));
    sort(all(f));
    ll ng=-1,ok=INF;
    while(ok-ng>1) {
        ll mid=(ng+ok)/2;
        ll ma=0,nk=k;
        rep(i,n) {
            if(a[i]*f[i]<=mid) ma=max(ma,a[i]*f[i]);
            else { 
                ll sub=a[i]*f[i]-mid;
                ll x=sub/f[i]+(sub%f[i]!=0);
                ma=max(ma,a[i]*f[i]-f[i]*min(nk,x));
                nk=max(0LL,nk-x);
            }
        } 
        if(ma<=mid) ok=mid;
        else ng=mid;
    } 
    cout << ok << endl;
    return 0;
}