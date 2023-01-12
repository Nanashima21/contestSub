#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        a: [usize; n],
    };
    let mut cnt=0;
    let mut now=a[0];
    let mut flag=0;
    for i in 1..n {
        if flag==0 {
            if now>a[i] {
                flag=-1;
                now=a[i];
            } else if now<a[i] {
                flag=1;
                now=a[i];
            }
        } else if flag==1 {
            if now>a[i] {
                flag=0;
                cnt+=1;
            } 
            now=a[i];
        } else {
            if now<a[i] {
                flag=0;
                cnt+=1;
            }
            now=a[i];
        }
    }
    println!("{}",cnt+1);
}

