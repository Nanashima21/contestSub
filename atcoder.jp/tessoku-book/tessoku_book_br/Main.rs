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
        a: [usize; n],
        p: [(Usize1,Usize1,Usize1); m], 
    };
    let x=f(&a);
    let mut cnt=vec![INF; 1<<n];
    let mut dq=VecDeque::new();
    dq.push_back(x);
    cnt[x]=0;
    while let Some(cv)=dq.pop_front() {
        for &(a,b,c) in p.iter() {
            let mut nv=cv;
            nv^=1<<a;
            nv^=1<<b;
            nv^=1<<c;
            if cnt[nv]==INF {
                cnt[nv]=cnt[cv]+1;
                dq.push_back(nv);
            }
        } 
    }
    println!("{}",if cnt[(1<<n)-1]==INF {-1} else {cnt[(1<<n)-1]})
}

fn f(a: &Vec<usize>) -> usize {
    let mut ret=0;
    for i in 0..a.len() {
       ret += if a[i]==1 {1<<i} else {0}
    } 
    ret
}