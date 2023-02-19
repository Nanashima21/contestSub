#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: usize = std::usize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        t: usize,
    }
    for _ in 0..t {
        input! {
            n: usize,
            d: usize,
            mut k: usize,
        }
        k -= 1;
        let m = n/gcd(n,d);
        println!("{}",d*k%n+k/m);
    }
}

fn gcd(x: usize, y: usize) -> usize {
    if y==0 {
        return x;
    }
    gcd(y,x%y)
}
 
fn lcm(x: usize, y: usize) -> usize {
    x*y/gcd(x,y)
}