#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    ll ng=*max_element(all(l))-1,ok=INF;
    while(ok-ng>1) {
        ll mid=(ok+ng)/2;
        ll tot=0,cnt=1;
        for(int i=0;i<n;i++) {
            if(tot==0) {
                tot=l[i];
            } else {
                if(tot+l[i]+1>mid) {
                    cnt++; tot=l[i];
                } else if(tot+l[i]+1==mid) {
                    tot=0;
                    if(i!=n-1) cnt++;
                } else {
                    tot+=l[i]+1;
                }
            }
        }
        if(cnt>m) ng=mid; 
        else ok=mid;
    }
    cout << ok << endl;
    return 0;
}