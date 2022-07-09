#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m,x,t,d;
    cin >> n >> m >> x >> t >> d;
    if(x<=m&&m<=n) cout << t << endl;
    else cout << max(0,t-(x-m)*d) << endl;
    return 0;
}