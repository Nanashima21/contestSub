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
        n: usize,
        w: usize,
        p: [(usize,usize); n],
    };
    let max = 1_000_100;
    let mut dp = vec![vec![INF; max]; n+1];
    dp[0][0]=0;
    for i in 1..=n {
        for j in 0..max {
            if dp[i-1][j] == INF {
                continue;
            }
            dp[i][j]=dp[i][j].min(dp[i-1][j]);
            dp[i][j+p[i-1].1]=dp[i][j+p[i-1].1].min(dp[i-1][j]+p[i-1].0);
        }
    }
    let mut ans = 0;
    for i in 0..max {
        if dp[n][i] <= w {
            ans=ans.max(i);
        }
    }
    println!("{}",ans);
}

