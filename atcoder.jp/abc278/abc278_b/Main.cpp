#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,m;
    cin >> h >> m;
    int y=m;
    for(int i=h;;i++) {
        int x=i%24;
        while(y<60) {
            int nx=x/10*10+y/10;
            int ny=x%10*10+y%10;
            if(0<=nx&&nx<=23&&0<=ny&&ny<=59) {
                cout << x << " " << y << endl;
                return 0;
            }
            y++;
        }
        y=0;
    }
    return 0;
}