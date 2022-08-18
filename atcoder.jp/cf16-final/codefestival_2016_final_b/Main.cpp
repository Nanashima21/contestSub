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
    if(n<=2) {
        cout << n << endl;
        return 0;
    } 
    for(int i=0;i<n;i++) {
        ll tot=i*(i+1)/2;
        if(tot>=n) {
            for(int j=1;j<=i;j++) {
                if(j==tot-n) continue;
                cout << j << endl;
            }
            return 0;
        } 
    }
    return 0;
}