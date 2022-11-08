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
        q: usize,
    };
    let mut v=(1..=n).collect::<Vec<usize>>();
    let mut flag=true;
    let mut ans=Vec::new();
    for _ in 0..q {
        input! { t: usize, };
        if t==1 {
            input! { x: Usize1, y: usize, };
            if flag { v[x]=y; }
            else { v[n-x-1]=y }
        } else if t==2 {
            flag=!flag;
        } else {
            input! { x: Usize1, };
            ans.push(if flag { v[x] } else { v[n-x-1] });
        }
    }
    println!("{}",ans.iter().join("\n"));
}
