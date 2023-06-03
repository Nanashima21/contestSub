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
    if(n<=999) cout << n << endl;
    else if(n<=9999) cout << n/10*10 << endl;
    else if(n<=99999) cout << n/100*100 << endl;
    else if(n<=999999) cout << n/1000*1000 << endl;
    else if(n<=9999999) cout << n/10000*10000 << endl;
    else if(n<=99999999) cout << n/100000*100000 << endl;
    else if(n<=999999999) cout << n/1000000*1000000 << endl;
    else if(n<=9999999999) cout << n/10000000*10000000 << endl;
    else if(n<=99999999999) cout << n/100000000*100000000 << endl;
    else if(n<=99999999999) cout << n/1000000000*1000000000 << endl;
    return 0;
}