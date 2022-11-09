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
        n: usize,
        m: usize,
        p: [(Usize1,Usize1); m],
    };
    let mut g=vec![vec![]; n];
    for (u,v) in p {
        g[u].push(v+1);
        g[v].push(u+1);
    }
    for i in 0..n {
        println!("{}: {{{}}}",i+1,g[i].iter().join(", "));
    }
}
