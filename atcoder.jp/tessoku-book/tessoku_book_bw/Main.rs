#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        mut p: [(usize,usize); n],
    };
    let max = 1_500;
    let mut dp = vec![vec![-1; max]; n+1];
    dp[0][0]=0;
    p.sort_by(|a,b| (a.1).partial_cmp(&(b.1)).unwrap());
    for i in 0..n {
        for j in 0..max {
            if dp[i][j] != -1 {
                dp[i+1][j]=dp[i+1][j].max(dp[i][j]);
                if j+p[i].0 <= p[i].1 {
                    dp[i+1][j+p[i].0]=dp[i+1][j+p[i].0].max(dp[i][j]+1);
                }
            }
        }
    }
    let mut ans = 0;
    for i in 0..max {
        ans=ans.max(dp[n][i]);
    }
    println!("{}",ans);
}

