#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    double a,b,d;
    cin >> a >> b >> d;
    double r=sqrt(a*a+b*b);
    double theta=atan2(b,a);
    theta*=180/(M_PI);
    theta=theta+d;
    theta*=M_PI/180.0;
    printf("%.16f %.16f\n",r*cos(theta),r*sin(theta));
    return 0;
}