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
    let mut dist=vec![-1; n];
    let bfs = |g: &Vec<Vec<usize>>, dist: &mut Vec<i32>, st: usize| {
        let mut q=VecDeque::new();
        q.push_back(st);
        dist[st]=0;
        while let Some(cv)=q.pop_front() {
            for i in 0..g[cv].len() {
                if dist[g[cv][i]]!=-1 {
                    continue;
                }
                dist[g[cv][i]]=dist[cv]+1;
                q.push_back(g[cv][i]);
            } 
        }
    };
    bfs(&g,&mut dist,0);
    println!("{}",dist.iter().join("\n"));
}
