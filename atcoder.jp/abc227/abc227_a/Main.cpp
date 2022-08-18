#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,k,a;
    cin >> n >> k >> a;
    for(int i=0;i<k-1;i++) {
        if(a==n) a=1;
        else a++;
    }
    cout << a << endl;
    return 0;
}