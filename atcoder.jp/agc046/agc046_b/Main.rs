#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
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
        a: usize,
        b: usize,
        c: usize,
        d: usize,
    }
    let mut dp = vec![vec![0; d+1]; c+1];
    for i in a..=c {
        for j in b..=d {
            if i == a && j == b {
                dp[i][j] = 1;
            } else if i == a {
                dp[i][j] = dp[i][j-1]*i;
            } else if j == b {
                dp[i][j] = dp[i-1][j]*j;
            } else {
                dp[i][j] = dp[i][j-1]*i%MOD + dp[i-1][j]*j%MOD + MOD - (i-1)*(j-1)%MOD*dp[i-1][j-1]%MOD;
            }
            dp[i][j] %= MOD;
        }
    } 
    println!("{}",dp[c][d]);
}