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
        m: usize,
        k: usize,
    }
    let mut ans = 0;
    let tw = TwelvefoldWay::new(n);
    for i in 0..=k {
        let x = (m * TwelvefoldWay::modpow(m-1, n-i-1))%MOD;
        let y = tw.bab6(n, n-i);
        //println!("{} {}",x,y);
        ans += (x * y)%MOD;
        ans %= MOD;
    }
    println!("{}",ans);
}

pub struct TwelvefoldWay {
    fact: Vec<usize>,
    inv_fact: Vec<usize>,
}

impl TwelvefoldWay {
    pub fn new(n: usize) -> Self {
        assert!(n <= 1e9 as usize);
        let mut fact = vec![1; n+1];
        let mut inv_fact = vec![1; n+1];
        fact[0] = 1;
        for i in 1..=n {
            fact[i] = i * fact[i-1] % MOD;
        }
        inv_fact[n] = TwelvefoldWay::modpow(fact[n], MOD-2);
        for i in (1..n).rev() {
            inv_fact[i] = inv_fact[i+1] * (i+1) % MOD; 
        }
        TwelvefoldWay {
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
                ret = ret * n % MOD;
            }
            n = n * n % MOD;
            r /= 2;
        }
        ret
    }
    pub fn modinv(x: usize) -> usize {
        TwelvefoldWay::modpow(x, MOD-2)
    } 
    // 1. n個の玉を区別, x個の箱を区別, 配り方に制限なし
    pub fn bab1(n: usize, x: usize) -> usize {
        TwelvefoldWay::modpow(x, n)
    }
    // 2. n個の玉を区別, x個の箱を区別, 箱には1個以内(単射)
    pub fn bab2(&self, n: usize, x: usize) -> usize {
        if n > x { 0 } else { self.perm(x, n) }
    }
    // 3. n個の玉を区別, x個の箱を区別, 箱には1個以上(全射) O(xlogn)
    pub fn bab3(&self, n: usize, x: usize) -> usize {
        let mut ret = 0;
        for i in 0..=x {
            if (x-i) % 2 == 0 {
                ret += self.comb(x, i) * TwelvefoldWay::modpow(i, n) % MOD;
            } else {
                ret += MOD - self.comb(x, i) * TwelvefoldWay::modpow(i, n) % MOD;
            }
            ret %= MOD;
        }
        ret
    }
    // 4. n個の玉を区別しない, x個の箱を区別, 配り方に制限なし
    pub fn bab4(&self, n: usize, x: usize) -> usize {
        self.comb(n+x-1, n)
    }
    // 5. n個の玉を区別しない, x個の箱を区別, 箱には1個以内(単射)
    pub fn bab5(&self, n: usize, x: usize) -> usize {
        if n > x { 0 } else { self.comb(x, n) }
    }
    // 6. n個の玉を区別しない, x個の箱を区別, 箱には1個以上(全射)
    pub fn bab6(&self, n: usize, x: usize) -> usize {
        if n < x { 0 } else { self.comb(n-1, n-x) }
    }
    // 7. n個の玉を区別, x個の箱を区別しない, 配り方に制限なし O(x^2logn)
    pub fn bab7(&self, n: usize, x: usize) -> usize {
        let mut ret = 0; 
        for i in 0..=x {
            ret += self.bab3(n, i) * self.inv_fact[i] % MOD;
            ret %= MOD;
        }
        ret
    }
    // 8. n個の玉を区別, x個の箱を区別しない, 箱には1個以内(単射)
    pub fn bab8(n: usize, x: usize) -> usize {
        (n <= x) as usize
    }
    // 9. n個の玉を区別, x個の箱を区別しない, 箱には1個以上(全射)
    pub fn bab9(&self, n: usize, x: usize) -> usize {
        self.bab3(n, x) * self.inv_fact[x] % MOD
    }
    // 10. n個の玉を区別しない, x個の箱を区別しない, 配り方に制限なし O(nx)
    pub fn bab10(n: usize, x: usize) -> usize {
        let mut dp = vec![vec![0; x+1]; n+1];
        dp[0][0] = 1;
        for i in 0..=n {
            for j in 1..=x {
                if i as isize - j as isize >= 0 {
                    dp[i][j] = (dp[i][j-1] + dp[i-j][j]) % MOD;
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        dp[n][x]
    }
    // 11. n個の玉を区別しない, x個の箱を区別しない, 箱には1個以内(単射)
    pub fn bab11(n: usize, x: usize) -> usize {
        TwelvefoldWay::bab8(n, x)
    }
    // 12. n個の玉を区別しない, x個の箱を区別しない, 箱には1個以上(全射)
    pub fn bab12(n: usize, x: usize) -> usize {
        if n < x { 0 } else { TwelvefoldWay::bab10(n-x, x) }
    }
}
