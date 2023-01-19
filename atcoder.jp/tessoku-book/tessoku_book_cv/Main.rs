#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        p: [(f64,f64); n],
    };
    let max = 100_000_000_f64;
    let mut dp = vec![vec![max; n]; 1<<n];
    for i in 1..n {
        let (cx,cy)=p[0];
        let (nx,ny)=p[i];
        dp[1<<i][i]=(cx-nx).hypot(cy-ny);
    }
    for i in 0..1<<n {
        for j in 0..n {
            if i>>j & 1 == 1 {
                for k in 0..n {
                    if i>>k & 1 == 0 {
                        let (cx,cy)=p[j];
                        let (nx,ny)=p[k];
                        dp[i|(1<<k)][k]=dp[i|(1<<k)][k].min(dp[i][j]+(cx-nx).hypot(cy-ny));
                    }
                }
            }
        }
    }
    println!("{}",dp[(1<<n)-1][0]);
}
