#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        p: [(usize,usize); n],
    };
    let (mut a,mut b) = p[0];
    for &(na,nb) in p.iter() {
        if na >= a && nb >= b {
            a=na;
            b=nb;
            continue;
        }
        let (mut a1,mut b1) = (a,0);
        let (mut a2,mut b2) = (0,b);
        if a%na != 0 {
            a1=a+na-a%na;
        }
        while b1 < nb || b1 < b {
            b1+=a1/na*nb;
        }
        if b%nb !=0 {
            b2=b+nb-b%nb;
        }
        while a2 < na || a2 < a {
            a2+=b2/nb*na;
        }
        if a1/na == b1/nb {
            a=a1;
            b=b1; 
        } 
        if a2/na == b2/nb {
            a=a2;
            b=b2; 
        }
    }
    println!("{}",a+b);
}


