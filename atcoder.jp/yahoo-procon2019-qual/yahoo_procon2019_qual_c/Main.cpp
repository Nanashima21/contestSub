#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll k,a,b;
    cin >> k >> a >> b;
    cout << max((b-a)*((k-a+1)/2)+((k-a+1)%2==1)+a,k+1) << endl;
    return 0;
}