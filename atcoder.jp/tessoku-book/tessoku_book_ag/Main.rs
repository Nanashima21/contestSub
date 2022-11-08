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
        a: [usize; n],
    };
    let mut xsum=0;
    for i in &a {
        xsum^=i;
    }
    println!("{}",if xsum==0 { "Second" } else { "First" });
}
