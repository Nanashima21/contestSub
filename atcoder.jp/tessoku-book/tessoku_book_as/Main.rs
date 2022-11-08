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
        c: char,
        a: Chars,
    };
    let mut tot=0;
    for c in &a {
        match c {
            'W' => continue,
            'R' => tot+=1,
            'B' => tot+=2,
            _ => panic!(),
        }
    }
    let mut flag=false;
    if tot%3==0 && c=='W' { flag=true }
    if tot%3==1 && c=='R' { flag=true }
    if tot%3==2 && c=='B' { flag=true }
    println!("{}",if flag { "Yes" } else { "No" });
}
