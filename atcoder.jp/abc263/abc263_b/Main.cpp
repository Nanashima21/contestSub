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
    vector<ll> p(n+1);
    for(int i=2;i<=n;i++) cin >> p[i];
    int x=n,cnt=0;
    while(x!=1) {
        x=p[x];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}