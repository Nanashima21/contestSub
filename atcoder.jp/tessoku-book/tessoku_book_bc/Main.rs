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
    let mut st=BTreeSet::new();
    for _ in 0..q {
        input! { t: usize, x: i64 }
        if t==1 {
            st.insert(x);
        } else if t==2 {
            st.remove(&x);
        } else {
            println!("{}",st.range(x..).next().unwrap_or(&-1));
        }
    }
}
