#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll t,n;
    cin >> t >> n;
    ll a=0;
    vector<bool> flag(101+t);
    while(a<=100+t) {
        ll x=((100+t)*a)/100;
        flag[x]=true;
        a++;
    }
    ll cnt=0;
    vector<ll> v;
    rep(i,101+t) if(!flag[i]) {
        v.push_back(i);
        cnt++;
    }
    n--;
    cout << v[n%cnt]+(100+t)*(n/cnt) << endl;
    return 0;
}