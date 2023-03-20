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
        _l: usize,
        n1: usize,
        n2: usize,
        v1: [(usize,usize); n1],
        v2: [(usize,usize); n2],
    }
    let mut dq1 = VecDeque::new();
    let mut dq2 = VecDeque::new();
    for i in 0..n1 {
        dq1.push_back(v1[i]);
    } 
    for i in 0..n2 {
        dq2.push_back(v2[i]);
    } 
    let mut ans = 0;
    while let Some((x1,l1)) = dq1.pop_front() {
        if let Some((x2,l2)) = dq2.pop_front() {
            if x1 == x2 {
                ans += l1.min(l2);
            } 
            if l1 > l2 {
                dq1.push_front((x1,l1-l2));
            } 
            if l1 < l2 {
                dq2.push_front((x2,l2-l1));
            }
        }
    }
    println!("{}",ans);
}