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
        x: usize,
        y: usize,
        a: [usize; n],
    };
    let inf =100_010;
    let mut grundy=vec![0; inf];
    for i in 0..inf {
        let mut flag=vec![true; 3];
        if i>=x && grundy[i-x]<=2 {
            flag[grundy[i-x]]=false;
        }
        if i>=y && grundy[i-y]<=2 {
            flag[grundy[i-y]]=false;
        }
        for j in 0..3 {
            if flag[j] {
                grundy[i]=j;
                break;
            }
        }
    }
    let mut xsum=0;
    for i in 0..n {
        xsum^=grundy[a[i]];
    }
    println!("{}",if xsum==0 { "Second" } else { "First" });
}
