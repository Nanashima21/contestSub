#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll t1,t2,a1,a2,b1,b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll s1=t1*(a1-b1),s2=t2*(a2-b2);
    if(s1>0) {
        s1=-s1;
        s2=-s2; 
    }
    if(s1+s2==0) cout << "infinity" << endl;
    else if(s1+s2<0) cout << 0 << endl;
    else cout << (-s1)/(s1+s2)*2+((-s1)%(s1+s2)!=0) << endl;
    return 0;
}