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
    vector<pl> b(n,{0,0});
    rep(i,n) cin >> a[i];
    int q,cnt=0;
    ll cur=-1;
    cin >> q;
    while(q--) {
        int t,i; ll x;  
        cin >> t;
        if(t==1) {
            cin >> x;
            cnt++;
            cur=x;
        } else if(t==2) {
            cin >> i >> x;
            i--;
            if(b[i].second!=cnt) {
                a[i]=cur;
                b[i]={x,cnt};
            } else b[i].first+=x;
        } else {
            cin >> i;
            i--;
            if(b[i].second!=cnt) {
                a[i]=cur;
                b[i]={0,cnt};
            }
            cout << a[i]+b[i].first << '\n';
        }
    }
    return 0;
}