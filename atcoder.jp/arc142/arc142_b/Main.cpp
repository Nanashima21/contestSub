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
    if(n==2) {
        cout << 1 << " " << 2 << endl << 3 << " " << 4 << endl;
    } else {
        rep(i,n) {
            if(i==0) {
                rep(j,n) {
                    if(j) cout << " ";
                    cout << n*i+j+1;
                } cout << endl;
            } else {
                ll x=(i+1)*n,y=i*n+1;
                rep(j,n) {
                    if(j) cout << " ";
                    if(j%2==0) cout << x--;
                    else cout << y++;
                } cout << endl;
            }
        }
    }
    return 0;
}