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
        s: Chars,
    };
    let mut dp = vec![vec![0; n+1]; n+1];
    for j in 0..n {
        for k in 0..n {
            if s[n-j-1] == s[k] {
                dp[j+1][k+1]=dp[j+1][k+1].max(dp[j][k]+1);
            } else {
                    dp[j+1][k+1]=dp[j+1][k+1].max(dp[j][k]);
            }
            dp[j+1][k]=dp[j+1][k].max(dp[j][k]);
            dp[j][k+1]=dp[j][k+1].max(dp[j][k]);
        }
    }
    for j in 0..n {
        dp[j+1][n]=dp[j+1][n].max(dp[j][n]);
        dp[n][j+1]=dp[n][j+1].max(dp[n][j]);
    }     
    println!("{}",dp[n][n]);
}

