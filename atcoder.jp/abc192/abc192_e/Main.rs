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
        x: Usize1,
        y: Usize1,
        p: [(Usize1,Usize1,isize,isize); m],
    };
    let mut g=vec![vec![]; n];
    for (a,b,t,k) in p {
        g[a].push((b,t,k));
        g[b].push((a,t,k));
    }
    let mut time=vec![INF; n];
    let mut pq: BinaryHeap<(isize,usize)> =BinaryHeap::new();
    pq.push((0,x));
    time[x]=0;
    while let Some((mut ct,cv))=pq.pop() {
        ct=-ct;
        if time[cv]<ct {
            continue;
        }
        for &(nv,t,k) in g[cv].iter() {
            let mut nt=ct+t;
            if ct%k!=0 {
                nt+=k-ct%k;
            }
            if time[nv]>nt {
                time[nv]=nt;
                pq.push((-nt,nv));
            }
        }
    }
    println!("{}",if time[y]==INF {-1} else {time[y]});
}