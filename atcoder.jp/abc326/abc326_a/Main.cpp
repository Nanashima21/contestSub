#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int x,y;
    cin >> x >> y;
    bool flag=false;
    if(x>y&&0<x-y&&x-y<4) flag=true;
    if(x<y&&0<y-x&&y-x<3) flag=true;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}