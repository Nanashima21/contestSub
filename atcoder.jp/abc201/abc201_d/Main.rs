#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
#![allow(unused_assignments)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        h: usize,
        w: usize,
        s: [Chars; h],
    }
    let mut dp = vec![vec![0; w]; h];
    for i in (0..h).rev() {
        for j in (0..w).rev() {
            if i == h-1 && j == w-1 {
                continue;
            } else if i == h-1 {
                match (i+j)%2 {
                    0 => dp[i][j] = dp[i][j+1] + if s[i][j+1] == '+' {1} else {-1},
                    _ => dp[i][j] = dp[i][j+1] - if s[i][j+1] == '+' {1} else {-1},
                }
            } else if j == w-1 {
                match (i+j)%2 {
                    0 => dp[i][j] = dp[i+1][j] + if s[i+1][j] == '+' {1} else {-1},
                    _ => dp[i][j] = dp[i+1][j] - if s[i+1][j] == '+' {1} else {-1},
                }
            } else {
                match (i+j)%2 {
                    0 => {
                        dp[i][j] = (dp[i][j+1] + if s[i][j+1] == '+' {1} else {-1})
                        .max(dp[i+1][j] + if s[i+1][j] == '+' {1} else {-1});
                    },
                    _ => {
                        dp[i][j] = (dp[i][j+1] - if s[i][j+1] == '+' {1} else {-1})
                        .min(dp[i+1][j] - if s[i+1][j] == '+' {1} else {-1});
                    },
                }
            }
            
        }
    }
    //println!("{:?}",dp);
    let ma = dp[0][0];
    let ans = if ma < 0 {"Aoki"} else if ma > 0 {"Takahashi"} else {"Draw"};
    println!("{}",ans);
}

