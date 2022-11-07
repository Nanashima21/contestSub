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
        p: [(char,i32); n],
    };
    let mut ans=Vec::with_capacity(n);
    let mut tot: i32=0;
    for (op,x) in p {
        match op {
            '+'=>tot+=x,
            '-'=>tot-=x,
            '*'=>tot*=x,
            _ => panic!(),
        }
        tot%=10_000;
        ans.push((tot+10_000)%10_000);
    }
    println!("{}",ans.iter().join("\n"));
}

