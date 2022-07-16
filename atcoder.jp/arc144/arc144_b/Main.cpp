#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    ll tot=0;
    rep(i,n) {
        cin >> v[i];
        tot+=v[i];
    }
    ll m=0,pre=-1;
    vector<bool> flag(n,false);
    sort(all(v));
    while(true) {
        ll subcnt=0,ltot=0,lcnt=0;
        vector<ll> rtot(n,0);
        tot=0;
        rep(i,n) tot+=v[i];
        m=tot/n;
        rep(i,n) {
            if(v[i]>=m&&!flag[i]) {
                ll cnt=(v[i]-m)/b;
                v[i]-=cnt*b;
                subcnt+=cnt;
            } else {
                ltot+=v[i];
                rtot[i]=ltot;
            }
        }
        int idx=0;
        rep(i,n) {
            rtot[i]+=subcnt*a;
            if(rtot[i]/(i+1)<=v[i]) break; 
            idx++;
        }
        rep(i,idx) {
            ll x=(rtot[idx-1]/(idx)-v[i])/a;
            if(x>1) flag[i]=true;
            v[i]+=min(subcnt,x)*a;
            subcnt-=min(subcnt,x);
        }
        rep(i,n) if(!flag[n-i-1]) {
            v[n-i-1]+=subcnt*b;
            break;
        }
        if(pre==m) break;
        pre=m;
    }
    multiset<ll> se;
    rep(i,n) se.insert(v[i]);
    while(true) {
        ll l=*se.begin();
        ll r=*se.rbegin();
        if(r-l>b) {
            se.erase(se.find(l));
            se.erase(se.find(r));
            se.insert(r-b);
            se.insert(l+a);
        } else break;
    }
    cout << *se.begin() << endl;
    return 0;
}