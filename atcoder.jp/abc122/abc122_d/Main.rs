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
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
    }
    let mut dp = vec![vec![vec![0usize; 4]; 4]; 4];
    dp[0][0][0] = 1;
    // T -> 0, A -> 1, G -> 2, C -> 3
    for _ in 0..n {
        let mut pd = vec![vec![vec![0usize; 4]; 4]; 4];
        for i in 0..4 {
            for j in 0..4 {
                for k in 0..4 {
                    for l in 0..4 {
                        match (i, j, k, l) {
                            (_, 1, 2, 3) 
                            | (1, _, 2, 3)
                            | (1, 2, _, 3)
                            | (_, 1, 3, 2)
                            | (_, 2, 1, 3) => (),
                            _ => pd[j][k][l] = (pd[j][k][l] + dp[i][j][k])%MOD,
                        }
                    }
                }
            }
        }
        dp = pd;
    }
    let mut ans  = 0;
    for i in 0..4 {
        for j in 0..4 {
            for k in 0..4 {
                ans = (ans + dp[i][j][k])%MOD;
            }
        }
    }
    println!("{}",ans);
}