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

fn main() {
    input! {
        n: usize,
        m: usize,
        a: [usize; n],
        b: [usize; m],
    }
    let mut dp = vec![vec![INF; m+1]; n+1];
    for i in 0..=n {
        dp[i][0] = i;
    }
    for i in 0..=m {
        dp[0][i] = i;
    }
    for i in 1..=n {
        for j in 1..=m {
            dp[i][j] = dp[i][j].min(dp[i-1][j] + 1); 
            dp[i][j] = dp[i][j].min(dp[i][j-1] + 1); 
            dp[i][j] = dp[i][j].min(dp[i-1][j-1] + if a[i-1] == b[j-1] {0} else {1});
        }
    }
    println!("{}",dp[n][m]);
}