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
        p: [(usize,usize); n],
        q: usize,
        t: [(usize,usize,usize,usize); q],
    };
    let mut tot = vec![vec![0; 1_510]; 1_510];
    for &(x,y) in p.iter() {
        tot[x][y]+=1;
    }
    for i in 0..=1500 {
        for j in 0..=1500 {
            tot[i+1][j]+=tot[i][j];
        }
    } 
    for i in 0..=1500 {
        for j in 0..=1500 {
            tot[i][j+1]+=tot[i][j];
        }
    } 
    for &(a,b,c,d) in t.iter() {
        println!("{}",tot[a-1][b-1]-tot[c][b-1]-tot[a-1][d]+tot[c][d]);
    }
}

