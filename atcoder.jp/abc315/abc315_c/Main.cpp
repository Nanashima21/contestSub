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
    vector<vector<ll>> v(n+1 ,vector<ll> ());
    rep(i,n) {
        ll f,s;
        cin >> f >> s;
        v[f].push_back(s);
    }
    vector<ll> vec;
    ll ma=0;
    rep(i,n+1) {
        sort(rall(v[i]));
        if((int)v[i].size()>=2) {
            ma=max(ma,v[i][0]+v[i][1]/2);
            vec.push_back(v[i][0]);
        } else if((int)v[i].size()==1) {
            vec.push_back(v[i][0]);
        }
    }
    sort(rall(vec));
    if((int)vec.size()>=2) ma=max(ma,vec[0]+vec[1]);
    cout << ma << endl;
    return 0;
}