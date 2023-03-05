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
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        l: usize,
        a: [usize; n],
    }
    let mut dist = vec![];
    for &ai in a.iter() {
        dist.push((ai,0));
        dist.push((l-ai,1));
    }
    dist.sort();
    let mut ans = INF;
    for i in 1..dist.len() {
        if dist[i-1].1 != dist[i].1 {
            ans = ans.min(2*(l + dist[i].0 - dist[i-1].0));
        }
    }
    println!("{}",ans);
}

