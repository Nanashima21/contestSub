#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    vector<ll> cnt(n);
    rep(i,n) {
        cin >> p[i];
        for(int j=-1;j<2;j++) cnt[(p[i]-i+j+n*2LL)%n]++;
    }
    cout << *max_element(all(cnt)) << endl;
    return 0;
}