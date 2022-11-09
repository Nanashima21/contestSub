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
    let mut stk=vec![];
    let mut ans=vec![-1; n];
    for i in 0..n {
        while !stk.is_empty() {
            let (mut k,mut v)=stk.last().unwrap();
            if v>a[i] {
                ans[i]=(k as i32)+1;
                break;
            } else {
                stk.pop();
            }
        }
        stk.push((i,a[i]));
    }
    println!("{}",ans.iter().join(" "));
}
