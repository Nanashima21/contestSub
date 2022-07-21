#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int a,b;
    cin >> a >> b;
    if(a==1&&b==10) cout << "Yes" << endl;
    else if(a+1==b) cout << "Yes" << endl;
    else cout << "No" << endl;  
    return 0;
}