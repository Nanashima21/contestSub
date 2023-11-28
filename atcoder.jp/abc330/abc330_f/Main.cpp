#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll calc_cost(vector<ll> v,ll s) {
    vector<ll> v2;
    for(ll u:v) v2.push_back(u-s);
    vector<ll> cv;
    std::merge(all(v), all(v2), std::back_inserter(cv));
    ll center=(cv[(int)v.size()-1]+cv[(int)v.size()])/2;
    ll cost=0;
    for(ll u:v) {
        cost+=max(0LL,center-u);
        cost+=max(0LL,u-center-s);
    }
    return cost;
}

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    sort(all(x));
    sort(all(y));
    ll ng=-1,ok=INF/2;
    while(ok-ng>1) {
        ll mid=(ok+ng)/2;
        ll cx=calc_cost(x,mid);
        ll cy=calc_cost(y,mid);
        if(cx+cy<=k) ok=mid;
        else ng=mid;
    }
    cout << ok << endl;
    return 0;
}