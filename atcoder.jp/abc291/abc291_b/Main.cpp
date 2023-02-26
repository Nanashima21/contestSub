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
    vector<int> v(5*n);
    rep(i,5*n) cin >> v[i];
    ll tot=0,cnt=0;
    sort(all(v));
    for(int i=n;i<5*n-n;i++) {
        tot+=v[i];
        cnt++;
    }
    printf("%.10f\n",(double)(tot*1.0)/cnt);
    return 0;
}