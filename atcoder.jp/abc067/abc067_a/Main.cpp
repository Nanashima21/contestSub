#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int a,b;
    cin >> a >> b;
    cout << ((a%3==0||b%3==0||(a+b)%3==0) ? "Possible" : "Impossible") << endl;
    return 0;
}