#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int n,k;
string s;

int main() {
    cin >> n >> k >> s;
    int cntx=0;
    rep(i,n) if(s[i]=='X') cntx++;
    if(cntx<k) {
        k=n-k;
        rep(i,n) {
            if(s[i]=='X') s[i]='Y';
            else s[i]='X';
        }
    }
    vector<int> v;
    int i=0,j=0,ans=0;
    bool flag=true;
    while(i<n) {
        if(s[i]=='Y') {
            flag=false;
            if(i>0&&s[i-1]=='Y') ans++;
            i++;
            continue;
        }
        j=i;
        while(j<n&&s[j]=='X') j++;
        if(i>0&&j<n) v.push_back(j-i);
        i=j;
    }
    if(flag) ans=max(0,k-1);
    else {
        ans+=k;
        sort(all(v));
        rep(i,(int)v.size()) {
            if(v[i]<=k) {
                k-=v[i];
                ans++;
            } 
        }
    }
    cout << ans << endl;
    return 0;
}