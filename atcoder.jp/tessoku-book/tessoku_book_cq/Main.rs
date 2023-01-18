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
        s: isize,
        a: [isize; n],
    };
    let max = 600_600;
    let mut dp = vec![vec![false; max]; n+1];
    dp[0][0]=true;
    for i in 1..=n {
        for j in 0..max {
            if dp[i-1][j] {
                dp[i][j]|=dp[i-1][j];
                dp[i][j+a[i-1] as usize]|=dp[i-1][j];
            }
        }
    }
    let mut idx = n;
    let mut now = s;
    let mut ans = vec![];
    while idx != 0 {
        if now-a[idx-1] >= 0 && dp[idx][(now-a[idx-1]) as usize] {
            ans.push(idx);
            now-=a[idx-1];
        }
        idx-=1;
    }
    ans.reverse();
    if now != 0 {   
        println!("-1");
    } else {
        println!("{}",ans.len());
        println!("{}",ans.iter().join(" "));
    }
}

