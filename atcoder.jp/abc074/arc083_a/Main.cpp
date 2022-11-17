#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<double> totw;
    for(int i=0;i<=3030;i++) {
        for(int j=0;j<=3030;j++) {
            if(f>=i*a*100+j*b*100) totw.push_back(i*a*100+j*b*100);
        }
    }
    sort(all(totw));
    vector<double> tots;
    for(int i=0;i<=3030;i++) {
        for(int j=0;j<=3030;j++) {
            if(f>=i*c+j*d) tots.push_back(i*c+j*d);
        }
    }
    sort(all(tots));
    double ma=0.0;
    int sw=a*100,s=0;
    for(int i=0;i<(int)totw.size();i++) {
        double x=e*(totw[i]/100.0);
        int it=upper_bound(all(tots),x)-tots.begin()-1;
        int it2=upper_bound(all(tots),f-totw[i])-tots.begin()-1;
        if(totw[i]+tots[it]<=f) {
            double y=(100.0*tots[it])/(totw[i]+tots[it]);
            if(ma<y) {
                ma=y;
                sw=totw[i]+tots[it];
                s=tots[it];
            }
        } else {
            double y=(100.0*tots[it2])/(totw[i]+tots[it2]);
            if(ma<y) {
                ma=y;
                sw=totw[i]+tots[it2];
                s=tots[it2];
            }
        }
    }
    cout << sw << " " << s << endl;
    return 0; 
}