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
        a: [isize; n],
    };
    let mut b = vec![0; n+1];
    for i in 0..n {
        b[i+1]=b[i]+a[i/2]; 
    }
    let mut dp = vec![vec![-INF; n+1]; n+1];
    dp[1][0]=0;
    for i in 1..n {
        for j in 0..=n {
            if dp[i][j] < 0 {
                continue;
            }
            dp[i+1][j+1]=dp[i+1][j+1].max(dp[i][j]);
            dp[i+1][0]=dp[i+1][0].max(dp[i][j]+b[j]);
        }
    }
    let mut ans = 0;
    for i in 0..=n {
        ans=ans.max(dp[n][i]+b[i]);
    }
    println!("{}",ans);
}

