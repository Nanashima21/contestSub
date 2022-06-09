#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string x;
    cin >> x;
    int n=x.size();
    int cnts=0,cntt=0,cnt=0;
    rep(i,n) {
        if(x[i]=='S') cnts++;
        else {
            cntt++;
            if(cntt>cnts) {
                cnt++;
                cntt--;
            }
        }
    }
    cout << cnt*2 << endl;
    return 0;
}