#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};
#[fastout]
fn main() {
    input! {
        h: usize,
        w: usize,
        s: [Chars; h],
    };
    let mut dp: Vec<Vec<i64>>=vec![vec![0; w]; h];
    dp[0][0]=1;
    for i in 0..h {
        for j in 0..w {
            if s[i][j]=='#' {
                continue;
            }
            if i==h-1 && j==w-1 {
                continue;
            } else if i==h-1 {
                dp[i][j+1]+=dp[i][j];
            } else if j==w-1 {
                dp[i+1][j]+=dp[i][j];
            } else {
                dp[i+1][j]+=dp[i][j];
                dp[i][j+1]+=dp[i][j];
            }
        }
    }
    println!("{}",dp[h-1][w-1]);
}