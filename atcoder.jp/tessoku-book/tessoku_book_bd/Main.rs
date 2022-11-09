#![allow(unused_imports)]
#![allow(dead_code)]
use itertools::Itertools;
use superslice::Ext;
use proconio::{fastout, input};
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
    input! {
        n: usize,
        q: usize,
        s: Chars,
    };
    let m: i64=998_244_353;
    let mut h=vec![0i64; n+1];
    for i in 1..=n {
        h[i]=(100i64*h[i-1]%m+((s[i-1] as i64)-('a' as i64)+1i64))%m;
    }
    let mut pow100=vec![1i64; n+1];
    for i in 1..=n {
        pow100[i]=(100i64*pow100[i-1])%m;
    } 
    let hash_val = |l: usize, r: usize| -> i64 {
        let ret=(h[r]-(h[l-1]*pow100[r-l+1]%m)+m)%m;
        ret
    };
    for _ in 0..q {
        input! { v: [usize; 4] };
        println!("{}",if hash_val(v[0],v[1])==hash_val(v[2],v[3]) { "Yes" } else { "No" });
    }
}
