#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a,s;
        cin >> a >> s;
        bool flag=false;
        if(a<=s&&((a&(s-a))==a)) flag=true;
        cout << (flag ? "Yes" : "No") << '\n'; 
    }
    return 0;
}