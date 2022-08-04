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
    ll ma=1000,pre=a[0],rem=1000,num=0;
    bool flag=true;
    rep(i,n) {
        if(flag) {
            if(pre>=a[i]) pre=min(pre,a[i]);
            else {
                num=rem/pre;
                rem%=pre;
                flag=false;
                pre=a[i];
            } 
        } else {
            if(pre<=a[i]) pre=max(pre,a[i]);
            else {
                rem+=num*pre;
                num=0;
                ma=max(ma,rem);
                flag=true;
                pre=a[i];
            }
        }
    }
    rem+=num*pre;
    ma=max(ma,rem);
    cout << ma << endl;
    return 0;
}