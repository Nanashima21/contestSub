#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

string ans;

int main() {
    ll n;
    cin >> n;
    while(n>0) {
        if(n%26==0) {
            ans+='z';
            n--;
        } else ans+=char(n%26+'a'-1);
        n/=26;
    }
    reverse(all(ans));
    cout << ans << endl;
    return 0;
}