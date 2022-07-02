#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int k;
    cin >> k;
    int h=21;
    cout << h+k/60 << ":";
    if(k%60<10) cout << 0 << k%60 << endl;
    else cout << k%60 << endl;
    return 0;
}