#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    ll all=0;
    map<ll,ll> mp;
    rep(i,n) {
        cin >> a[i];
        all+=a[i];
        mp[a[i]]++;
        mp[a[i]+m]++;
    }
    vector<ll> v;
    for(auto u:mp) v.push_back(u.first);
    ll ma=0,tot=0;
    int l=0,r=-1;
    while(v[l]<m) {
        if(l>r) {
            r=l;
            tot+=v[l]*mp[v[l]];
        }
        while(true) {
            if(r<(int)v.size()-1&&v[r]+1==v[r+1]) {
                r++;
                tot+=(v[r]%m)*mp[v[r]];
            } else break;
        }
        ma=max(ma,tot);
        tot-=v[l]*mp[v[l]];
        l++;
    } 
    cout << max(0LL,all-ma) << endl;
    return 0;
}