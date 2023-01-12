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
        m: usize,
        p: [(Usize1,Usize1,isize,isize); m],
    };
    let mut g = vec![vec![]; n];
    for (a,b,c,d) in p {
        g[a].push((b,c,d));
        g[b].push((a,c,d));
    }
    let mut dist = vec![INF; n];
    let mut pq: BinaryHeap<(isize,usize)> = BinaryHeap::new();
    dist[0]=0;
    pq.push((0,0));
    while let Some((mut cd,cv)) = pq.pop() {
        cd = -cd;
        if dist[cv]<cd {
            continue;
        }
        for &(nv,c,_d) in g[cv].iter() {
            let nd=cd+c;
            if dist[nv]>nd {
                dist[nv]=nd;
                pq.push((-nd,nv));
            }
        }
    }
    let mut dq = VecDeque::new();
    let mut cnt = vec![0; n];
    dq.push_back(n-1);
    while let Some(cv) = dq.pop_front() {
        for &(nv,c,d) in g[cv].iter() {
            if dist[nv] == dist[cv] - c {
                cnt[nv]=cnt[cv]+d;
                dq.push_back(nv);
            }
        } 
    }
    println!("{} {}",dist[n-1],cnt[0]);
}