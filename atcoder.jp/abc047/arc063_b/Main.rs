#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(clippy::collapsible_if)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
const MOD: usize = 998_244_353;
//const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        _t: usize,
        a: [usize; n],
    }
    let mut mi = a[0];
    let mut ma = 0;
    let mut mp = HashMap::new();
    mp.insert(a[0], 0);
    for i in 1..n {
        mp.insert(a[i], i);
        if a[i] >= mi {
            ma = ma.max(a[i] - mi);
        }
        mi = mi.min(a[i]);
    }
    let mut ans = 0;
    for i in 0..n {
        if let Some(j) = mp.get(&(a[i]+ma)) {
            if &i < j {
                ans += 1;
            } 
        }
    }
    println!("{}",ans);
}

