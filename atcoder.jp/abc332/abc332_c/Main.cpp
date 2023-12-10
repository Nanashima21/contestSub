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
    string s;
    cin >> s;
    ll l=-1,r=1001;
    while(r-l>1) {
        ll mid=(l+r)/2;
        bool flag=false;
        rep(i,mid+1) {
            ll muj=m+i,log=mid-i;
            bool check=true;
            rep(j,n) {
                if(s[j]=='0') {
                    muj=m+i; log=mid-i;
                } else if(s[j]=='1') {
                    if(muj<=0) {
                        if(log<=0) check=false;
                        log--;
                    } else muj--;
                } else {
                    if(log<=0) check=false;
                    log--;
                }
            }
            flag|=check;
        }
        if(!flag) l=mid;
        else r=mid;
    } 
    cout << r << endl;
    return 0;
}