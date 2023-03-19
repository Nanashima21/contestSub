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
        p: [(Usize1,Usize1); n-1],
    }
    let mut g = vec![vec![]; n];
    for &(u,v) in p.iter() {
        g[u].push(v);
        g[v].push(u);
    }
    let mut dq = VecDeque::new();
    dq.push_back(0);
    let mut dist = vec![INF; n];
    dist[0] = 0;
    while let Some(cv) = dq.pop_front() {
        for &nv in g[cv].iter() {
            if dist[nv] != INF {
                continue;
            }
            dist[nv] = dist[cv] + 1;
            dq.push_back(nv);
        }
    }
    let mut path = vec![];
    let mut now = n-1;
    while now != 0 {
        path.push(now);
        for &nv in g[now].iter() {
            if dist[nv]+1 == dist[now] {
                now = nv;
                break;
            }
        }
    }
    path.push(0);
    //println!("{:?}",path);
    let mut tot = vec![];
    for i in 0..path.len() {
        let mut cnt = 1;
        let mut flag = vec![false; n];
        flag[path[i]] = true;
        for &nv in g[path[i]].iter() {
            if i != 0 && nv == path[i-1] {
                continue;
            } 
            if i != path.len()-1 && nv == path[i+1] {
                continue;
            } 
            cnt += 1;
            flag[nv] = true;
            dq.push_back(nv);
        }

        while let Some(cv) = dq.pop_front() {
            for &nv in g[cv].iter() {
                if flag[nv] {
                    continue;
                }
                cnt += 1;
                flag[nv] = true;
                dq.push_back(nv);
            }
        } 
        tot.push(cnt);
    }
    //println!("{:?}",tot);
    
    let mut l = 0;
    let mut r = path.len()-1;
    let mut ltot = 0;
    let mut rtot = 0;
    for j in 0..path.len() {
        //println!("{}",j);
        match j%2 {
            0 => {
                rtot += tot[r];
                r -= 1;
            },
            _ => {
                ltot += tot[l];
                l += 1;
            },
        }
        if l > r {
            break;
        }
    }
    println!("{}",if ltot >= rtot {"Snuke"} else {"Fennec"})
}