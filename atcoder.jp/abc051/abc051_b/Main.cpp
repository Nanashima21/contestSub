#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int k,s;
    cin >> k >> s;
    int cnt=0;
    for(int i=0;i<=k;i++) {
        for(int j=0;j<=k;j++) {
            int l=s-i-j;
            if(0<=l&&l<=k) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}