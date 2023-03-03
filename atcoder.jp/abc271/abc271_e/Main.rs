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
        m: usize,
        k: usize,
        p: [(Usize1,Usize1,usize); m],
        e: [Usize1; k],
    }
    let mut dist = vec![INF; n];
    dist[0] = 0;
    for &ei in e.iter() {
        let (u, v, d) = p[ei];
        if dist[u] == INF {
            continue;
        }
        dist[v] = dist[v].min(dist[u] + d);
    }
    if dist[n-1] == INF {
        println!("-1");
    } else {
        println!("{}",dist[n-1]);
    }
}