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
    let max = 200_200;
    let mut bit = FenwickTree::new(max, 0);
    let mut bit2 = FenwickTree::new(max, 0);
    let mut ans: Vec<usize> = Vec::with_capacity(n);
    ans.push(a[0]);
    bit.add(a[0],1);
    bit2.add(a[0],a[0]);
    let mut tot = a[0];
    for i in 1..n {
        tot+=bit.sum(0,a[i]+1)%MOD*a[i]%MOD*2%MOD;
        tot%=MOD;
        tot+=(bit2.sum(a[i]+1,max)+MOD)%MOD*2%MOD;
        tot%=MOD;
        tot+=a[i];
        tot%=MOD;
        ans.push(tot*modpow(modpow(i+1,2),MOD-2)%MOD);
        bit.add(a[i],1);
        bit2.add(a[i],a[i]);
    } 
    println!("{}",ans.iter().join("\n"));
}

fn modpow(mut n: usize, mut r: usize) -> usize {
    let mut num=1;
    while r>0 {
        if r&1==1 {
            num=num*n%MOD;
        }
        n=n*n%MOD;
        r/=2;
    }
    num
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
    pub fn sum(&self, l: usize, r: usize) -> T
    where
        T: std::ops::Sub<Output = T>,
    {
        self.accum(r) - self.accum(l)
    }
}
