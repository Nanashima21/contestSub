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
        mut n: usize,
    };
    let mut mp = HashMap::new();
    let mut p10 = vec![1usize; 16];
    mp.insert(1,0);
    for i in 0..15 {
        for j in 2..=10 {
            //println!("{} {} {} {}",j*p10,mp[&(j*p10-p10)],mp[&(p10)],j*p10-p10);
            mp.insert(j*p10[i],mp[&(j*p10[i]-p10[i])]+mp[&(p10[i])]+j*p10[i]-p10[i]);
        }
        p10[i+1]=p10[i]*10;
    }
    let mut tot = 0;
    let mut ans = 0;
    if n%10 == 0 {
        ans+=f(n);
    }
    let x = n.to_string().len();
    for i in (0..x).rev() {
        let num = n/p10[i]*p10[i];
        if num == 0 {
            continue;
        }
        if i == 0 {
            ans+=mp[&(num+1)]+(num+1)*tot;
        } else {
            ans+=mp[&num]+num*tot;
        }
        //println!("{} {} {} {} {}",i,mp[&(num)],num,tot,ans);
        tot+=n/p10[i];
        n-=num;
    }
    println!("{}",ans);
}

fn f(n: usize) -> usize {
    let mut x = n;
    let mut ret = 0;
    while x > 0 {
        ret=ret+x%10;
        x/=10;
    }
    ret
}

/*
[
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 
 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 
 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 
 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 
 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 
 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 
 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 
 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 
 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 
 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
]
*/