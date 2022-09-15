#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int k,n;
    cin >> n >> k;
    vector<int> a(n);
    int idx=0;
    rep(i,n) {
        cin >> a[i];
        if(a[i]==1) idx=i;
    }
    int ans=100100100;
    for(int i=0;i<=n-k;i++) {
        if(i<=idx&&idx<i+k) {
            ans=min(ans,i/(k-1)+(i%(k-1)!=0)+(n-(i+k))/(k-1)+((n-(i+k))%(k-1)!=0)+1);
        }
    }
    cout << ans << endl;
    return 0;
}