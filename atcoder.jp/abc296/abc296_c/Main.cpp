#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    set<ll> se;
    bool flag=false;
    rep(i,n) {
        cin >> a[i];
        se.insert(a[i]);
    }
    rep(i,n) if(se.find(a[i]-x)!=se.end()) flag=true;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}