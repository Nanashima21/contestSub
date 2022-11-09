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
    let mut que=VecDeque::new();
    for _ in 0..q {
        input! { t: usize }
        if t==1 {
            input! { x: String }
            que.push_back(x);
        } else if t==2 {
            println!("{}",que.front().unwrap());
        } else {
            que.pop_front();
        }
    }
}
