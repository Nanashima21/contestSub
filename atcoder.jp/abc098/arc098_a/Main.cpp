#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n; string s;
    cin >> n >> s;
    vector<ll> l(n),r(n);
    if(s[0]=='W') l[0]++;
    if(s[n-1]=='E') r[n-1]++;
    for(int i=1;i<n;i++) {
        l[i]=l[i-1];
        if(s[i]=='W') l[i]++;
    }
    for(int i=n-2;i>=0;i--) {
        r[i]=r[i+1];
        if(s[i]=='E') r[i]++;
    }
    ll ans=min(l[n-1],r[0]);
    for(int i=1;i<n-1;i++) {
        ans=min(ans,l[i-1]+r[i+1]);
    }
    cout << ans << endl;
    return 0;
}