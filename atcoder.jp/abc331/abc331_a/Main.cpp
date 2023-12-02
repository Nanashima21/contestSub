#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int M,D,y,m,d;
    cin >> M >> D >> y >> m >> d;
    if(M==m&&D==d) cout << y+1 << " " << 1 << " " << 1 << endl;
    else if(D==d) cout << y << " " << m+1 << " " << 1 << endl;
    else cout << y << " " << m << " " << d+1 << endl;
    return 0;
}