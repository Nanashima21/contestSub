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
        p: [[usize; n]; n],
    };
    let mut bit1 = FenwickTree::new(n+1,0);
    let mut bit2 = FenwickTree::new(n+1,0);
    let mut ans=0;
    let mut vec1 = vec![];
    let mut vec2 = vec![];
    for i in 0..n {
        for j in 0..n {
            if p[i][j] != 0 {
                vec1.push(p[i][j]);
            }
            if p[j][i] != 0 {
                vec2.push(p[j][i]);
            }
        }
    }
    for i in 0..n {
        ans+=bit1.sum(vec1[i],n+1);
        bit1.add(vec1[i],1);
        ans+=bit2.sum(vec2[i],n+1);
        bit2.add(vec2[i],1);
    }
    println!("{}",ans);
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