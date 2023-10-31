#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

string solve(ll dis, vector<ll> &v) {
    int m=(int)v.size();
    vector<ll> l,r;
    map<ll,ll> mpl,mpr;
    for(int bit=0;bit<(1<<(m/2));bit++) {
        ll tot=0;
        rep(i,m/2) {
            if(bit>>i&1) tot+=v[i];                
            else tot-=v[i];
        }
        l.push_back(tot);
        mpl[tot]=bit;
    }
    for(int bit=0;bit<(1<<(m-m/2));bit++) {
        ll tot=0;
        rep(i,m-m/2) {
            if(bit>>i&1) tot+=v[m/2+i]; 
            else tot-=v[m/2+i];
        }
        r.push_back(tot);
        mpr[tot]=bit;
    }
    sort(all(l)); 
    sort(all(r));
    rep(i,(int)l.size()) {
        if(binary_search(all(r),dis-l[i])) {
            string strl,strr;
            rep(j,m/2) strl+=to_string(mpl[l[i]]>>j&1);
            rep(j,m-m/2) strr+=to_string(mpr[dis-l[i]]>>j&1);
            return strl+strr;
        }
    }
    return "";
}

int main() {
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> vx,vy;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        if(i%2==1) vx.push_back(a[i]);
        else vy.push_back(a[i]);
    }
    string strx=solve(x,vx);
    string stry=solve(y,vy);
    // cout << strx << ' ' << stry << endl;
    if(strx==""||stry=="") cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int idx=0,dir=0;
        string ans;
        while(idx<2*n) {
            if(idx%2==0&&idx/2<(int)stry.size()) {
                if(stry[idx/2]=='0') {
                    if(dir==0) ans+='R';
                    else ans+='L';
                    dir=3;
                } else {
                    if(dir!=0) ans+='R';
                    else ans+='L';
                    dir=1;
                }
            }
            idx++;
            if(idx%2==1&&idx/2<(int)strx.size()) {
                if(strx[idx/2]=='0') {
                    if(dir!=1) ans+='R';
                    else ans+='L';
                    dir=2;
                } else {
                    if(dir==1) ans+='R';
                    else ans+='L';
                    dir=0;
                }
            }
            idx++;
        }
        cout << ans << endl;
        // dir=0;
        // ll cx=0,cy=0;
        // rep(i,n) {
        //     if(ans[i]=='L') dir=(dir+1)%4;
        //     else dir=(dir+3)%4;
        //     if(dir==0) cx+=a[i];
        //     if(dir==1) cy+=a[i];
        //     if(dir==2) cx-=a[i];
        //     if(dir==3) cy-=a[i];
        // }
        // cout << cx << ' ' << cy << endl;
    }
    return 0;
}