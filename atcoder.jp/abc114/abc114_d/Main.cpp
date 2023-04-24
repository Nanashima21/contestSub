#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

bool isprime(ll x) {
    if(x<2) return 0;
    else if(x==2) return 1;
    if(x%2==0) return 0;
    for(ll i=3;i*i<=x;i+=2) if(x%i==0) return 0;
    return 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> p;
    for(int i=2;i<=n;i++) if(isprime(i)) p.push_back(i);
    int m=(int)p.size();
    vector<ll> pcnt(m,0);
    for(int i=2;i<=n;i++) {
        int idx=0,x=i;
        while(x>1) {
            if(x%p[idx]==0) {
                x/=p[idx];
                pcnt[idx]++;
            } else idx++;
        }
    }
    int ans=0;
    for(int i=0;i<m;i++) if(pcnt[i]>73) ans++;
    for(int i=0;i<m;i++) {
        for(int j=i+1;j<m;j++) {
            if(pcnt[i]>1&&pcnt[j]>23) ans++;
            if(pcnt[j]>1&&pcnt[i]>23) ans++;
            if(pcnt[i]>3&&pcnt[j]>13) ans++;
            if(pcnt[j]>3&&pcnt[i]>13) ans++;
        }
    } 
    for(int i=0;i<m;i++) {
        for(int j=i+1;j<m;j++) {
            for(int k=j+1;k<m;k++) {
                if(pcnt[i]>1&&pcnt[j]>3&&pcnt[k]>3) ans++;
                if(pcnt[i]>3&&pcnt[j]>1&&pcnt[k]>3) ans++;
                if(pcnt[i]>3&&pcnt[j]>3&&pcnt[k]>1) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}