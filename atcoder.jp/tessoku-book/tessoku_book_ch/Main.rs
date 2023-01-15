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
        t: [(usize,usize,usize,usize); n],
    };
    let mut tot = vec![vec![0i64; 1_510]; 1_510];
    let mut ans = 0i64;
    for &(a,b,c,d) in t.iter() {
        tot[a][b]+=1;
        tot[c][b]-=1;
        tot[a][d]-=1;
        tot[c][d]+=1;
    } 
    for i in 0..=1500 {
        for j in 0..=1500 {
            tot[i+1][j]+=tot[i][j];
        }
    }
    for i in 0..=1500 {
        for j in 0..=1500 {
            tot[j][i+1]+=tot[j][i];
        }
    }
    for i in 0..1500 {
        for j in 0..1500 {
            if tot[i][j] > 0 {
                ans+=1;
            } 
        }
    }
    println!("{}",ans);
}

