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
const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        r: usize,
    };
    println!("{}",ModComb::new(n).comb(n,r));
}

pub struct ModComb {
    fact: Vec<usize>,
    inv_fact: Vec<usize>,
}
impl ModComb {
    pub fn new(n: usize) -> ModComb {
        let mut fact = vec![1; n+1];
        let mut inv_fact = vec![1; n+1];
        fact[0] = 1;
        for i in 1..=n {
            fact[i]= i * fact[i-1] % MOD;
        }
        inv_fact[n] = ModComb::modpow(fact[n], MOD-2);
        for i in (1..n).rev() {
            inv_fact[i] = inv_fact[i+1] * (i+1) % MOD; 
        }
        ModComb {
            fact,
            inv_fact,
        }
    }
    pub fn perm(&self, n: usize, k: usize) -> usize {
        assert!(n >= k);
        self.fact[n] % MOD * self.inv_fact[n-k] % MOD
    }
    pub fn comb(&self, n: usize, k: usize) -> usize {
        assert!(n >= k);
        self.fact[n] * self.inv_fact[k] % MOD * self.inv_fact[n-k] % MOD
    }
    pub fn modpow(mut n: usize, mut r: usize) -> usize {
        let mut ret = 1;
        while r > 0 {
            if r & 1 == 1 {
                ret=ret*n%MOD;
            }
            n=n*n%MOD;
            r/=2;
        }
        ret
    }
    pub fn modinv(&self, x: usize) -> usize {
        ModComb::modpow(x, MOD-2)
    } 
}