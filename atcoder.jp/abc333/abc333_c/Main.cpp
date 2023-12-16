#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> v;
    v.push_back(1);
    rep(i,13) v.push_back(v.back()*10+1);
    vector<ll> vec;
    int m=(int)v.size();
    set<ll> se;
    rep(i,m) rep(j,m) rep(k,m) {
        se.insert(v[i]+v[j]+v[k]);
    } 
    for(auto u:se) vec.push_back(u);
    cout << vec[n-1] << endl;
    return 0;
}