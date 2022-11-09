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
        q: usize,
    };
    let mut pq=BinaryHeap::new();
    for _ in 0..q {
        input! { t: usize }
        if t==1 {
            input! { x: i32 }
            pq.push(-x);
        } else if t==2 {
            println!("{}",-pq.peek().unwrap());
        } else {
            pq.pop();
        }
    }
}
