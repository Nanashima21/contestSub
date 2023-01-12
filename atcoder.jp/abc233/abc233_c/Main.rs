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
        x: usize,
        a: [[usize]; n],
    };
    let ans=dfs(1,0,x,&a);
    println!("{}",ans);
}

fn dfs(tot: usize, i: usize, x: usize, a: &Vec<Vec<usize>>) -> usize {
    let mut ret = 0usize;
    if i == a.len() {
        return if tot == x {1} else {0};
    }
    for &ai in a[i].iter() {
        if tot * ai > x {
            continue;
        }
        ret += dfs(tot*ai,i+1,x,a);
    }
    ret
}