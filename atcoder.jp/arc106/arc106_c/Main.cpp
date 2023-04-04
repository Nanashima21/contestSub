#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    if(n==1&&m==0) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    if(m>=n-1||m<0) {
        cout << -1 << endl;
        return 0;
    }
    ll l=1,r=(ll)1e9;
    for(int i=n-1;i>=m+1;i--) cout << l++ << " " << r-- << endl;
    for(int i=0;i<=m;i++,l+=2) cout << l << " " << l+1 << endl; 
    return 0;
}