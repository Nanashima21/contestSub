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
        n: usize,
        mut a: [usize; n],
    }
    let mut ans = 0;
    for i in 0..n-1 {
        ans += a[i]/2;
        if a[i]%2 == 1 && a[i+1] > 0  {
            a[i+1] -= 1;
            ans += 1;
        } 
    }
    ans += a[n-1]/2;
    println!("{}",ans);
}

