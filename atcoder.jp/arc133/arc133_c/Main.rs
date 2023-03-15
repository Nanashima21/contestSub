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
        h: usize,
        w: usize,
        k: usize,
        mut a: [usize; h],
        mut b: [usize; w],
    }
    let mut suma = 0;
    let mut sumb = 0;
    for i in 0..h {
        a[i] = ((k-1)*w-a[i])%k;
        suma += a[i];
    }
    for i in 0..w {
        b[i] = ((k-1)*h-b[i])%k;
        sumb += b[i];
    }
    if suma%k != sumb%k {
        println!("-1");
    } else {
        println!("{}",h*w*(k-1)-suma.max(sumb));
    }
}