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
        l: usize,
        p: [(usize,char); n],
    };
    let mut ans=0;
    for (a,b) in p {
        if b=='E' {
            ans=ans.max(l-a);
        } else {
            ans=ans.max(a);
        }
    }
    
    println!("{}",ans);
}
