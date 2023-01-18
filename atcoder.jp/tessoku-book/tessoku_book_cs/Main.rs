#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        s: Chars,
        t: Chars,
    };
    let sl = s.len();
    let tl = t.len();
    let mut dp = vec![vec![INF; tl+1]; sl+1];
    dp[0][0]=0;
    let mut si = -1;
    while si < (sl as isize) {
        let mut ti = -1;
        while ti < (tl as isize) {
            if si == -1 && ti == -1 {
                ti+=1;
                continue;
            } 
            if si == -1 {
                let j = ti as usize;
                dp[0][j+1]=dp[0][j+1].min(dp[0][j]+1);
            } else if ti == -1 {
                let i = si as usize;
                dp[i+1][0]=dp[i+1][0].min(dp[i][0]+1);
            } else {
                let i = si as usize;
                let j = ti as usize;
                if s[i] == t[j] {
                    dp[i+1][j+1]=dp[i+1][j+1].min(dp[i][j]);
                } else {
                    dp[i+1][j+1]=dp[i+1][j+1].min(dp[i][j]+1);
                }
                dp[i+1][j+1]=dp[i+1][j+1].min(dp[i][j+1]+1);
                dp[i+1][j+1]=dp[i+1][j+1].min(dp[i+1][j]+1);
            }
            ti+=1;
        }
        si+=1;
    }
    println!("{}",dp[sl][tl]);
}

