#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
    input! {
        n: usize,
        m: usize,
        a: [[usize; n]; m],
    };
    let mut dp=vec![vec![1_000; 1<<n]; m+1];
    dp[0][0]=0;
    for i in 1..=m {
        for bit in 0..1<<n {
            if dp[i-1][bit]==1_000 {
                continue;
            }
            dp[i][bit]=dp[i][bit].min(dp[i-1][bit]);
            let mut t=0;
            for j in 0..n {
                t+=a[i-1][j]<<j;
            }
            dp[i][bit|t]=dp[i][bit|t].min(dp[i-1][bit]+1);
        }
    }
    if dp[m][(1<<n)-1]==1_000 {
        dp[m][(1<<n)-1]=-1;
    }
    println!("{}",dp[m][(1<<n)-1]);
}