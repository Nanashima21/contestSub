#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

double a,b;
double p;

double f(double x) {
    return b*x+a/sqrt(x+1);
}

int main() {
    cin >> a >> b;
    double l=0,r=1e64;
    while(r-l>1e-3) {
        double m1=(l*2+r)/3.0;
        double m2=(l+r*2)/3.0;
        if(f(m1)<f(m2)) r=m2;
        else l=m1;
    } 
    printf("%.10f\n",min(f(floor(l)),f(ceil(l))));
    return 0;
}