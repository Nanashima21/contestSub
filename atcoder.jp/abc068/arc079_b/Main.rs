#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        k: usize,
    }
    let mut m = k%50;
    let mut ans = vec![(k+49)/50 + 49; 50];
    let mut idx = 0;
    while m != 0 && m < 50 {
        ans[idx] -= 50;
        for i in idx+1..50 {
            ans[i] += 1;
        }
        m += 1;
        idx += 1;
    }
    println!("50");
    println!("{}",ans.iter().join(" "));
}

