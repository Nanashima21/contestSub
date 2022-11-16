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
    double exv=3.5;
    rep(i,n-1) {
        double tot=0,cnt=0;
        for(int j=ceil(exv);j<=6;j++) {
            tot+=j;
            cnt++;
        }
        exv=tot/6.0+(6.0-cnt)/6.0*exv;
    }
    printf("%.10f\n",exv);
    return 0;
}