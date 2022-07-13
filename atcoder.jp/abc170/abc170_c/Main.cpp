#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int x,n;
    cin >> x >> n;
    vector<ll> p(n);
    map<int,bool> mp;
    rep(i,n) {
        cin >> p[i];
        mp[p[i]]=true;
    }
    int ans=0,mi=100100100;
    for(int i=-1000;i<=1000;i++) {
        if(mp[i]) continue;
        if(mi>abs(i-x)) {
            ans=i;
            mi=abs(i-x);
        }
    }
    cout << ans << endl;
    return 0;
}