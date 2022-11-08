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
        d: usize,
        n: usize,
        p: [(Usize1,Usize1,usize); n],
    };
    let mut v=vec![24; d];
    for (l,r,h) in p {
        for i in l..=r {
            v[i]=v[i].min(h);
        }
    }
    let mut tot=0;
    for i in 0..d {
        tot+=v[i];
    }
    println!("{}",tot);
}
