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
        p: [(Usize1,Usize1,i64); m],
    };
    let mut g=vec![vec![]; n];
    for (u,v,d) in p {
        g[u].push((v,d));
        g[v].push((u,d));
    }
    let inf=1_000_000_000;
    let mut dist=vec![inf; n];
    let mut q=BinaryHeap::new();
    q.push((0,0));
    dist[0]=0;
    while let Some((mut cd,cv))=q.pop() {
        cd=-cd;
        if dist[cv]<cd {
            continue;
        }
        for i in 0..g[cv].len() {
            let (nv,d)=g[cv][i]; 
            let nd=cd+d;
            if nd>=dist[nv] {
                continue;
            }
            dist[nv]=cd+d;
            q.push((-nd,nv));
        } 
    }
    for i in 0..n {
        if dist[i]==inf {
            dist[i]=-1;
        }
    }
    println!("{}",dist.iter().join("\n"));
}
