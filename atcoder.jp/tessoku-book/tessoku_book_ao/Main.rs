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
        s: Chars,
    };
    let mut flag=false;
    for i in 1..n-1 {
        if s[i-1]==s[i] && s[i]==s[i+1] {
            flag=true;
        }
    }
    println!("{}",if flag { "Yes" } else { "No" });
}
