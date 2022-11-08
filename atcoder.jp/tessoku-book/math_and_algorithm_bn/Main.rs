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
        mut p: [(usize,usize); n],
    };
    p.sort_by_key(|x| x.1);
    let mut cnt=0;
    let mut lt=0;
    for (l,r) in p {
        if l>=lt {
            lt=r;
            cnt+=1;
        }
    }
    println!("{}",cnt);
}
