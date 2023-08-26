#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,h,x;
    cin >> n >> h >> x;
    int ans=0,ma=100100;
    rep(i,n) {
        int p;
        cin >> p;
        if(h+p>=x) {
            if(ma>h+p) {
                ma=h+p;
                ans=i;
            }
        }
    }
    cout << ans+1 << endl;
    return 0;
}