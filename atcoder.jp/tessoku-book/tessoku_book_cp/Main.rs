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
        h: [isize; n],
    };
    let mut dp = vec![INF; n];
    dp[0]=0;
    for i in 0..n {
        if i+1 < n {
            dp[i+1]=dp[i+1].min(dp[i]+(h[i]-h[i+1]).abs());
        } 
        if i+2 < n {
            dp[i+2]=dp[i+2].min(dp[i]+(h[i]-h[i+2]).abs());
        }
    }
    let mut now = n-1;
    let mut cst = dp[n-1];
    let mut ans = vec![];
    ans.push(now+1);
    while now != 0 {
        if now > 1 && cst-dp[now-2] == (h[now]-h[now-2]).abs() {
            cst=dp[now-2];
            now-=2;
            ans.push(now+1);
        }
        if now > 0 && cst-dp[now-1] == (h[now]-h[now-1]).abs() {
            cst=dp[now-1];
            now-=1;
            ans.push(now+1);
        }
    }
    println!("{}",ans.len());
    ans.reverse();
    println!("{}",ans.iter().join(" "));
}

