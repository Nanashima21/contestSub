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
        g[u].push(v);
        g[v].push(u);
    }
    let mut flag=vec![false; n];
    flag[0]=true;
    dfs(&g,&mut flag,0);
    if flag.iter().all(|&x| x) {
        println!("The graph is connected.");
    } else {
        println!("The graph is not connected.");
    }
}

fn dfs(g: &Vec<Vec<usize>>, flag: &mut Vec<bool>, cv: usize) {
    for &nv in g[cv].iter() {
        if flag[nv] {
            continue;
        }
        flag[nv]=true;
        dfs(g,flag,nv);
    }
}
