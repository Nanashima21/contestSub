#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int x,y,z;
    cin >> x >> y >> z;
    if(x>0) {
        if(y>0) {
            if(y<x) {
                if(z<y) {
                    if(z>0) cout << x << endl;
                    else cout << x-2*z;
                } else cout << -1 << endl;
            } else cout << x << endl;
        } else cout << x << endl;
    } else if(x<0) {
        if(y<0) {
            if(y>x) {
                if(z>y) {
                    if(z<0) cout << -x << endl;
                    else cout << -x+2*z;
                } else cout << -1 << endl;
            } else cout << -x << endl;
        } else cout << -x << endl;
    }
    return 0;
}