#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<int> v(6);
    rep(i,6) cin >> v[i];
    int cnt=0;
    for(int i=1;i<=30;i++) {
        for(int j=1;j<=30;j++) {
            for(int k=1;k<=30;k++) {
                for(int l=1;l<=30;l++) {
                    int a=v[0]-(i+j);
                    int b=v[1]-(k+l);
                    int c=v[3]-(i+k);
                    int d=v[4]-(j+l);
                    if(a>=1&&b>=1&&c>=1&&d>=1) {
                        int e=v[2]-(c+d);
                        int f=v[5]-(a+b);
                        if(e>=1&&e==f) cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}