#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    int tot=0;
    rep(i,n) {
        cin >> a[i];
        tot+=a[i]-(i%2==1);
    }
    cout << (x>=tot ? "Yes" : "No") << endl;
    return 0;
}