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
    map<pair<int,int>,ll> mp; 
    rep(i,n) { 
        double a;
        cin >> a;
        ll num=llround(a*1e9);
        int cnt2=0,cnt5=0;
        while(num%2==0) {
            cnt2++;
            num/=2;
        }
        while(num%5==0) {
            cnt5++;
            num/=5;
        }
        mp[{cnt2,cnt5}]++;
    }
    ll ans=0;
    for(auto u1:mp) for(auto u2:mp) {
        pair<int,int> p1=u1.first,p2=u2.first;
        if(p1.first+p2.first>=18 && p1.second+p2.second>=18) {
            if(u1<u2) ans+=u1.second*u2.second;
            if(u1==u2) ans+=u1.second*(u1.second-1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}