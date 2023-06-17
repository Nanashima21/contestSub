#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<int> a(64);
    rep(i,64) cin >> a[i];
    unsigned long long ans=0;
    rep(i,64) if(a[i]==1) ans+=1LL<<(i*1LL);
    cout << ans << endl;
    return 0;
}