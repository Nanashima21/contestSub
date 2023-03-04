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
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

fn main() {
    input! {
        n: usize,
        m: usize,
        a: [usize; n],
    }
    let mut mp = HashMap::new();
    mp.insert(0usize,1usize);
    let mut tot = vec![0; n+1];
    let mut ans = 0;
    for i in 1..=n {
        tot[i] += tot[i-1] + a[i-1];
        if let Some(num) = mp.get(&(tot[i]%m)) {
            ans += num;
        }
        *mp.entry(tot[i]%m).or_insert(0) += 1;
    }
    //println!("{:?}",mp);
    println!("{}",ans);
}