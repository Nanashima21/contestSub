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
        q: usize,
        query: [(usize,usize,usize); q],
    };
    let mut seg = Segtree::new(n,0,|a,b| a.max(b));
    let mut ans = vec![];
    for &(t,a,b) in query.iter() {
        match t {
            1 => seg.set(a-1,b),
            2 => ans.push(seg.query(a-1,b-1)),
            _ => panic!(),
        }
    }
    println!("{}",ans.iter().join("\n"));
}

pub struct Segtree<F, T> {
    n: usize,
    array: Vec<T>,
    e: T,
    func: F,
}

impl< F: Fn(T, T) -> T, T: Copy + Eq + std::fmt::Debug> Segtree<F, T> {
    pub fn new(_n: usize, e: T, func: F) -> Self {
        let n = _n.next_power_of_two();
        Segtree {
            n,
            array: vec![e; n * 2],
            e,
            func,
        }
    }
    pub fn set(&mut self, mut idx: usize, val: T) {
        idx += self.n - 1;
        self.array[idx] = val;
        while idx > 0 {
            idx = (idx-1)/2;
            self.array[idx] = (self.func)(self.array[idx*2+1], self.array[idx*2+2]);
        }
    }
    //[a,b)
    pub fn query(&self, a: usize, b: usize) -> T {
        self._query(a, b, 0, 0, self.n)
    }
    fn _query(&self, a: usize, b: usize, k: usize, l: usize, r: usize) -> T {
        if r <= a || b <= l {
            self.e
        } else if a <= l && r <= b {
            self.array[k]
        } else {
            let vl: T = self._query(a, b, k*2+1, l, (l+r)/2);
            let vr: T = self._query(a, b, k*2+2, (l+r)/2, r);
            (self.func)(vl, vr)
        }
    }
    pub fn get(&self, idx: usize) -> T {
        self.array[idx+self.n-1]
    }
}