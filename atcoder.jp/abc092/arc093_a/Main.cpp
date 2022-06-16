#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll tot=abs(a[0])+abs(a.back());
    for(int i=1;i<n;i++) tot+=abs(a[i]-a[i-1]);
    for(int i=0;i<n;i++) {
        if(i==0) {
            if((a[i]>=0&&a[i+1]<0)||(a[i+1]>=0&&a[i]<0)) cout << tot-abs(a[i])*2 << endl; 
            else if(0<=a[i]&&a[i]<=a[i+1]) cout << tot << endl;
            else if(a[i]<=0&&a[i+1]<=a[i]) cout << tot << endl;
            else cout << tot-abs(a[i]-a[i+1])*2 << endl;
        } else if(i==n-1) {
            if((a[i]>=0&&a[i-1]<0)||(a[i-1]>=0&&a[i]<0)) cout << tot-abs(a[i])*2 << endl; 
            else if(0<=a[i]&&a[i]<=a[i-1]) cout << tot << endl;
            else if(a[i]<=0&&a[i-1]<=a[i]) cout << tot << endl;
            else cout << tot-abs(a[i]-a[i-1])*2 << endl;
        } else {
            if(a[i-1]<=a[i]&&a[i]<=a[i+1]) cout << tot << endl;
            else if(a[i+1]<=a[i]&&a[i]<=a[i-1]) cout << tot << endl;
            else cout << tot-min(abs(a[i]-a[i+1]),abs(a[i]-a[i-1]))*2 << endl;
        }
    }
    return 0;
}