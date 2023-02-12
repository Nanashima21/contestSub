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
        t: usize,
    }
    for _ in 0..t {
        input! {
            n: usize,
            m: usize,
            c: [usize; n],
            e: [(Usize1,Usize1); m],
        }
        let mut g = vec![vec![]; n];
        for &(u,v) in e.iter() {
            g[u].push(v);
            g[v].push(u);
        } 
        let mut dist: Vec<Vec<i32>> = vec![vec![-1; n]; n];
        dist[0][n-1]=0;
        let mut q = VecDeque::new();
        q.push_back((0,n-1));
        while let Some((x,y)) = q.pop_front() {
            for &nx in g[x].iter() {
                for &ny in g[y].iter() {
                    if dist[nx][ny] != -1 {
                        continue;
                    }
                    if c[nx] != c[ny] {
                        dist[nx][ny]=dist[x][y]+1;
                        q.push_back((nx,ny));
                    }
                }
            }
        }
        println!("{}",dist[n-1][0]);
    }
}
