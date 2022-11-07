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
    let inf=1_000_000_000;
    let mut b=vec![inf; n];
    let mut ans=0;
    for i in 0..n {
        let it=b.lower_bound(&a[i]);
        b[it]=a[i];
        ans=ans.max(it+1);
    }
    println!("{}",ans);
}