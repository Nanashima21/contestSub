#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

struct binary_indexed_tree {
private:
    int N;
    vector<double> bit;
public:
    binary_indexed_tree(int n): N(n) { bit.resize(N+1,0); }
    double addition(double x, double y) { return (x+y); }
    void add(int x,double a) {
        for(x++;x<=N;x+=(x&-x)) bit[x] = addition(bit[x],a);
    }
    double sum(int x) { //[0,x]
        double ret=0;
        for(x++;x>0;x-=(x&-x)) ret = addition(ret,bit[x]);
        return ret;
    }
};

double calc(double r,double h) {
    return M_PI*r*r*h/3.0;
}

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> x(n),r(n),h(n);
    rep(i,n) cin >> x[i] >> r[i] >> h[i];
    binary_indexed_tree bit(20020);
    rep(i,n) {
        for(int j=x[i];j<=x[i]+h[i]-1;j++) {
            double vol1=calc(r[i]*(x[i]+h[i]-j)/(h[i]*1.0),x[i]+h[i]-j);
            double vol2=calc(r[i]*(x[i]+h[i]-j-1.0)/(h[i]*1.0),x[i]+h[i]-j-1.0);
            bit.add(j,vol1-vol2);
        }
    }
    rep(i,q) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        printf("%.10f\n",bit.sum(b)-bit.sum(a));
    }
    return 0;
}