#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(unused)]
const INF: isize = std::isize::MAX/4;
//const MOD: usize = 998_244_353;
const MOD: isize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        w: isize,
        l: isize,
        r: isize,
        mut x: [isize; n],
    };
    x.push(0);
    x.push(w);
    x.sort();
    let mut bit: FenwickTree<isize> = FenwickTree::new(n+2,0);
    bit.add(0,1);
    for i in 1..=n+1 {
        let cl=x[i]-r;
        let cr=x[i]-l;
        if cr < 0 {
            continue;
        }
        let idxl=x.lower_bound(&cl);
        let idxr=x.upper_bound(&cr)-1;
        let tot= (bit.sum(idxl,idxr+1)+MOD)%MOD;
        if i != n+1 {
            bit.add(i,tot);
        } else {
            println!("{}",tot);
        }
    }
}

pub struct FenwickTree<T> {
    n: usize,
    array: Vec<T>,
    e: T,
}

impl<T: Clone + std::ops::AddAssign<T>> FenwickTree<T> {
    pub fn new(n: usize, e: T) -> Self {
        FenwickTree {
            n,
            array: vec![e.clone(); n],
            e,
        }
    }
    //[0,idx)
    pub fn accum(&self, mut idx: usize) -> T {
        let mut sum = self.e.clone();
        while idx > 0 {
            sum += self.array[idx-1].clone();
            idx &= idx - 1;
        }
        sum
    }
    pub fn add<U: Clone>(&mut self, mut idx: usize, val: U)
    where
        T: std::ops::AddAssign<U>,
    {
        let n = self.n;
        idx += 1;
        while idx <= n {
            self.array[idx-1] += val.clone();
            idx += idx & idx.wrapping_neg();
        }
    }
    // [l,r)
    pub fn sum(&self, l: usize, r: usize) -> T
    where
        T: std::ops::Sub<Output = T>,
    {
        self.accum(r) - self.accum(l)
    }
}