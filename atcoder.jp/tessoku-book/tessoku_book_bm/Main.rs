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
        a: [Usize1; n-1],
    };
    let mut g=vec![vec![]; n];
    for i in 0..n-1 {
        g[i+1].push(a[i]);
        g[a[i]].push(i+1);
    }
    let mut tot=vec![0; n];
    let mut flag=vec![false; n];
    flag[0]=true;
    dfs(&g,&mut tot,&mut flag,0);
    println!("{}",tot.iter().join(" "));
}

fn dfs(g: &Vec<Vec<usize>>, tot: &mut Vec<usize>, flag: &mut Vec<bool>, cv: usize) -> usize { 
    let mut cnt: usize=0;
    for &nv in g[cv].iter() {
        if flag[nv] {
            continue;
        }
        flag[nv]=true;
        cnt+=dfs(g,tot,flag,nv);
    }
    tot[cv]=cnt;
    return tot[cv]+1;
}
