#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q,x;
    cin >> n >> q >> x;
    vector<ll> w(n);
    ll tot=0;
    rep(i,n) {
        cin >> w[i];
        tot+=w[i];
    }
    ll rd=x/tot,rem=x%tot;
    vector<int> to(n);
    ll num=rd*n;
    rep(i,n) {
        while(rem>0) {
            rem-=w[(i+num)%n];
            num++;
        }
        to[i]=num;
        rem+=w[i];
        num--;
    }
    vector<vector<ll>> db(60,vector<ll> (n));
    rep(i,n) db[0][i]=(i+to[i])%n;
    rep(i,59) rep(j,n) db[i+1][j]=db[i][db[i][j]];
    while(q--) {
        ll k;
        cin >> k;
        k--;
        int idx=0;
        for(int i=59;i>=0;i--) if(k>>i&1) idx=db[i][idx];
        cout << to[idx] << '\n';
    }
    return 0;
}