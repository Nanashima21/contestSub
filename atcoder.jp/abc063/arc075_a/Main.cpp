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
    vector<ll> s(n);
    ll tot=0;
    rep(i,n) {
        cin >> s[i];
        tot+=s[i];
    }
    if(tot%10!=0) cout << tot << endl;
    else {
        sort(all(s));
        rep(i,n) {
            if(s[i]%10!=0) {
                cout << tot-s[i] << endl;
                return 0;
            }
        }
        cout << 0 << endl;
    } 
    return 0;
}