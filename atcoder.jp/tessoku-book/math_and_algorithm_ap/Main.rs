#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
    };
    let mut dp = vec![0; n];
    dp[0]=1;
    dp[1]=1;
    for i in 2..n {
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    println!("{}",dp[n-1]);
}

