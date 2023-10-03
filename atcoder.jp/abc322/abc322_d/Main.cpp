#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const int n = 4;

struct PuzzlePiece {
    int h,w;
    vector<string> s;
    PuzzlePiece(vector<string> _s): s(_s) {
        assert((int)_s.size() > 0);
        h = (int)_s.size();
        w = (int)_s[0].size();
    }
    vector<string> trimming() {
        vector<bool> flagh(h, false), flagw(w, false);
        for (int i = 0; i < h ; i++) {
            bool check = false;
            for (int j = 0; j < w; j++) {
                if (s[i][j] == '#') check = true;
            }
            flagh[i] = check;
        }
        for (int i = 0; i < w ; i++) {
            bool check = false;
            for (int j = 0; j < h; j++) {
                if (s[j][i] == '#') check = true;
            }
            flagw[i] = check;
        }
        vector<string> ns;
        for (int i = 0; i < h; i++) {
            string str;
            for (int j = 0; j < w; j++) {
                if (flagh[i] && flagw[j]) str += s[i][j]; 
            }
            if (str != "") ns.push_back(str);
        }
        return ns;
    }
    vector<string> rotate() {
        for(int l=0; l < n/2; l++){
            int first=l;
            int last=n-1-l;
            for(int i=first;i<last;i++){
                int j=last-i+first;
                int tmp=s[first][i];
                s[first][i]=s[j][first];
                s[j][first]=s[last][j];
                s[last][j]=s[i][last];
                s[i][last]=tmp;
            }
        }
        return s;
    }
    void output() {
        for (int i = 0 ; i < h; i++) cout << s[i] << endl; 
    }
};

const int num[] = {1,2,4};

int main() {
    vector<string> s1(4),s2(4),s3(4);
    rep(i,4) cin >> s1[i];
    rep(i,4) cin >> s2[i];
    rep(i,4) cin >> s3[i];
    vector<PuzzlePiece> pp;
    pp.push_back(s1);
    pp.push_back(s2);
    pp.push_back(s3);
    vector<vector<PuzzlePiece>> ppp(4,vector<PuzzlePiece>());
    rep(i,3) rep(j,4) {
        ppp[i].push_back(PuzzlePiece(pp[i].trimming()));
        pp[i] = pp[i].rotate();
    }
    
    bool flag=false;
    vector<vector<int>> cnt(8, vector<int> (8,0)); 
    auto dfs = [&](auto dfs, int id=0) -> void {
        if (id==3) {
            bool check=true;
            rep(i,4) rep(j,4) {
                if(cnt[i][j] == 1) continue;
                if(cnt[i][j] == 2) continue;
                if(cnt[i][j] == 4) continue;
                check = false;
            }
            flag|=check;
        } else {
            rep(i,4) rep(j,4) rep(k,4) {
                int h=ppp[id][k].h;
                int w=ppp[id][k].w;
                vector<string> s=ppp[id][k].s;
                rep(y,h) rep(x,w) if(s[y][x] == '#') cnt[i+y][j+x] += num[id];
                bool check=true;
                rep(y,8) rep(x,8) if((y>3 || x>3) && cnt[y][x]!=0) check=false;
                if(check) dfs(dfs,id+1);
                rep(y,h) rep(x,w) if(s[y][x] == '#') cnt[i+y][j+x] -= num[id];
            }
        }
    };
    dfs(dfs);
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}