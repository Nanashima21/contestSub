#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

int N,D,Q,temp;
vector<vector<int> > v;
vector<set<int> > putted;
vector<int> vec(1, 0), box_idx;

int query_cnt = 0;

void output(bool flag) {
    if (!flag) cout << "#c "; 
    for (int i = 0; i < N; i++) cout << box_idx[i] << " ";
    cout << endl;
}

void debug(vector<int> out) {
    cerr << " [";  
    for (int i = 0; i < (int)out.size(); i++) {
        if (i) cerr << ",";
        cerr << out[i];
    }
    cerr << "] " << endl;
}

string query1(int x, int y) {
    query_cnt++;
    cout << 1 << " " << 1 << " " << x << " " << y << endl;
    string in;
    cin >> in;
    return in;
}

string query2(int xidx, int yidx) {
    query_cnt++;
    cout << (int)putted[xidx].size() << " " << (int)putted[yidx].size();
    for (int x : putted[xidx]) cout << " " << x;
    for (int y : putted[yidx]) cout << " " << y;
    cout << endl;
    string in;
    cin >> in;
    return in;
}

void insert_item(int wi) {
    int sz = (int)vec.size();
    int l = -1, r = sz;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (query_cnt == Q) break;
        // cerr << l << " " << mid << " " << r;
        // debug();
        string res = query1(v[vec[mid]][0], wi);
        if (res == "=") v[vec[mid]].push_back(wi);
        else if (res == ">") r = mid;
        else l = mid;
    } 
    vector<int> stk;
    for (int i = sz - 1; i >= r; i--) {
        stk.push_back(vec.back());
        vec.pop_back();
    }
    vec.push_back(wi);
    v[wi].push_back(wi);
    while((int)stk.size() > 0) {
        vec.push_back(stk.back());
        stk.pop_back();
    }
}

void insert_box(int bi, vector<int> &bv) {
    int sz = (int)bv.size();
    int l = -1, r = sz;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (query_cnt == Q) break;
        string res = query2(bv[mid], bi);
        if (res == ">" || res == "=") r = mid;
        else l = mid;
    } 
    vector<int> stk;
    for (int i = sz - 1; i >= r; i--) {
        stk.push_back(bv.back());
        bv.pop_back();
    }
    bv.push_back(bi);
    while((int)stk.size() > 0) {
        bv.push_back(stk.back());
        stk.pop_back();
    }
}

vector<int> compare_box() {
    vector<int> bv(1, 0);
    for (int i = 1; i < D; i++) insert_box(i, bv);
    return bv;
}

int pick_item(int box_idx) {
    vector<pair<int, int> > iv;
    for (int u : putted[box_idx]) {
        for (int j = 0; j < (int)vec.size(); j++) {
            for (int i = 0; i < (int)v[vec[j]].size(); i++) {
                if (v[vec[j]][i] == u) iv.push_back(make_pair(j, u));
            }
        }
    }
    sort(iv.begin(), iv.end());
    // return iv[max(0, (int)iv.size() / 4 - (query_cnt - temp) / D)].second;
    return iv[(int)iv.size() / 2 + (int)iv.size() / 3].second;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    srand(time(NULL));

    cin >> N >> D >> Q;
    
    v.assign(N, vector<int> ());
    v[0].push_back(0);

    int cur_idx = 1;

    while ((int)vec.size() == 1) {
        string res = query1(0, cur_idx);
        if (res == "="){
            v[0].push_back(cur_idx);
        } else if (res == ">") {
            vec.pop_back();
            vec.push_back(1);
            vec.push_back(0);
            v[1].push_back(1);
        } else {
            vec.push_back(1);
            v[1].push_back(1);
        }
        cur_idx++;
    }
    
    for (; cur_idx < N && query_cnt < Q; cur_idx++) insert_item(cur_idx);

    // debug(vec);
    // cerr << "here " << query_cnt << endl;;

    box_idx.assign(N, 0);

    output(false);
    
    reverse(vec.begin(), vec.end());
    int idx = 0;
    bool flag = true;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            box_idx[vec[v[i][j]]] = idx;
            // cerr << vec[v[i][j]] << " " << idx << endl;
            if (flag) {
                idx++;
                if (D != 2) {
                    if (idx == D) {
                        idx = D - 1;
                        flag = false;
                    }
                } else {
                    if (idx == D - 1) flag = false;
                }
            } else {
                idx--;
                if (idx == 0) flag = true;
            }
        }
    }
    putted.resize(D);

    for (int i = 0; i < N; i++) {
        putted[box_idx[i]].insert(i); 
    }

    output(false);

    temp = query_cnt;

    while(Q > query_cnt) {
        vector<int> cb = compare_box();
        if (Q <= query_cnt) break;
        int l = 0, r = D - 1;
        while (l < r) {
            int lidx = cb[l], ridx = cb[r];
            if ((int)putted[ridx].size() != 1) { 
                int rb = pick_item(ridx);
                box_idx[rb] = cb[l];
                putted[lidx].insert(rb);
                putted[ridx].erase(rb);
            }
            l++; r--;
        } 
        // debug(cb);
        output(false);
    }

    output(true);

    // vector<pair<int,int> > vv;
    // vector<int> vvv;
    // for (int i = 0; i < N; i++) {
    //     int a;
    //     cin >> a;
    //     vv.push_back(make_pair(a,i));
    // }
    // sort(vv.begin(), vv.end());
    // for (int i = 0; i < N; i++) vvv.push_back(vv[i].second);
    // debug(vvv);
    return 0;
}