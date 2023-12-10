#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll k,g,m;
    cin >> k >> g >> m;
    ll tg=0,tm=0;
    while(k--) {
        if(tg==g) {
            tg=0;
        } else if(tm==0) {
            tm=m;
        } else {
            ll x=g-tg;
            if(x<=tm) {
                tg=g;
                tm-=x;
            } else {
                tg+=tm;
                tm=0;
            }
        }
    }
    cout << tg << " " << tm << endl;
    return 0;
}