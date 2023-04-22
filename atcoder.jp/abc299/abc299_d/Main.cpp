#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    ll l=1,r=n;
    while(r-l>1) {
        ll mid=(l+r)/2;
        cout << "? " << mid << endl;
        ll in;
        cin >> in;
        if(in==0) l=mid;
        else r=mid;
    }
    cout << "! " << l << endl;
    return 0;
}