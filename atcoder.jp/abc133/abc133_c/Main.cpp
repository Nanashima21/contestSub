#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll l,r;
    cin >> l >> r;
    ll mi=INF;
    if(r-l>=2019) mi=0; 
    l%=2019; r%=2019;
    if(l>=r) mi=0;
    else {
        for(int i=l;i<r;i++) {
            for(int j=i+1;j<=r;j++) {
                mi=min(mi,(i*j*1LL)%2019);
            }
        }
    }
    cout << mi << endl;
    return 0;
}