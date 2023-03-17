#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        k: isize,
        e: [(Usize1,Usize1); n-1],
    }
    let mut g = vec![vec![]; n];
    for &(u,v) in e.iter() {
        g[u].push(v);
        g[v].push(u);
    }
    let mut dq = VecDeque::new();
    dq.push_back((0, k-1));
    let mut flag = vec![false; n];
    flag[0] = true;
    let mut ans = k as usize;
    while let Some((cv, mut num)) = dq.pop_front() {
        for &nv in g[cv].iter() {
            if flag[nv] {
                continue;
            } 
            flag[nv] = true;
            ans *= num as usize;
            ans %= MOD;
            num -= 1;
            dq.push_back((nv, k-2));
        } 
    }
    println!("{}",ans);
}