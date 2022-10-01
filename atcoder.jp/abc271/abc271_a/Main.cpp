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
    int x=n/16,y=n%16;
    if(x>=10) cout << char('A'+x-10);
    else cout << x;
    if(y>=10) cout << char('A'+y-10);
    else cout << y;
    cout << endl;
    return 0;
}