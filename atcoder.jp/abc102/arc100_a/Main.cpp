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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]-=i+1;
    sort(all(a));
    ll b=0;
    if(n%2==1) b=a[n/2];
    else b=(a[n/2-1]+a[n/2])/2;
    ll tot=0;
    rep(i,n) tot+=abs(a[i]-b);
    cout << tot << endl;
    return 0;
}