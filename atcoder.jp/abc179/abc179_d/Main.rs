#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
const MOD: isize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        k: usize,
        p: [(usize,usize); k],
    }
    let mut dp = vec![0isize; n];
    dp[0] = 1;
    dp[1] = -1;
    for i in 0..n {
        if i != 0 {
            dp[i] += dp[i-1];
            dp[i] %= MOD; 
        }
        for &(l,r) in p.iter() {
            if i + l < n {
                dp[i+l] += dp[i];
                dp[i+l] %= MOD; 
            }
            if i + r + 1 < n {
                dp[i+r+1] -= dp[i];
                dp[i+r+1] = (dp[i+r+1] + MOD)%MOD;
            }
        }
    } 
    println!("{}",dp[n-1]);
}

