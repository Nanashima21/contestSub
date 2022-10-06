#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    double a,b,x;
    cin >> a >> b >> x;
    if(a*a*b/2.0<x) {
        double c=a*a*b-x;
        double y=(2.0*c)/(a*a);
        printf("%.10f\n",90.0-atan(a/y)*(180/M_PI));
    } else {
        double y=(2.0*x)/(b*a);
        printf("%.10f\n",atan(b/y)*(180/M_PI));
    }
    return 0;
}