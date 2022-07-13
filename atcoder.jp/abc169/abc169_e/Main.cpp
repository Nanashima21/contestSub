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
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    if(n%2==0) {
        cout << (b[n/2]+b[n/2-1])-(a[n/2]+a[n/2-1])+1 << endl;
    } else {
        cout << b[n/2]-a[n/2]+1 << endl;
    }
    return 0;
}