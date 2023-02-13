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
//const MOD: usize = 998_244_353;
const MOD: usize = 1_000_000_007;

#[fastout]
fn main() {
    input! {
        n: usize,
        p: [(isize,usize); n],
    }
    let mut lr: Vec<(isize,isize)> = vec![(INF,-INF); n+2];
    lr[0]=(0,0);
    lr[n+1]=(0,0);
    for &(x,c) in p.iter() {
        if x < lr[c].0 {
            lr[c].0 = x;
        }
        if x > lr[c].1 {
            lr[c].1 = x;
        }
    }
    //println!("{:?}",lr);
    let mut dp = vec![vec![INF; 2]; n+2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    let mut pre = 0;
    for i in 1..=n+1 {
        if lr[i].0 == INF || lr[i].1 == INF {
            continue;
        }
        
        if lr[i].0 <= lr[pre].0 && lr[pre].0 <= lr[i].1 {
            dp[i][0] = dp[i][0].min(dp[pre][0]+(lr[i].1-lr[pre].0+lr[i].1-lr[i].0));
            dp[i][1] = dp[i][1].min(dp[pre][0]+(lr[pre].0-lr[i].0+lr[i].1-lr[i].0));
        } else {
            if lr[i].0 > lr[pre].0 {
                dp[i][0] = dp[i][0].min(dp[pre][0]+(lr[i].1-lr[i].0)*2+lr[i].0-lr[pre].0);
                dp[i][1] = dp[i][1].min(dp[pre][0]+lr[i].1-lr[pre].0);
            } else {
                dp[i][1] = dp[i][1].min(dp[pre][0]+(lr[i].1-lr[i].0)*2+lr[pre].0-lr[i].1);
                dp[i][0] = dp[i][0].min(dp[pre][0]+lr[pre].0-lr[i].0);
            }
        }
        if lr[i].0 <= lr[pre].1 && lr[pre].1 <= lr[i].1 {
            dp[i][0] = dp[i][0].min(dp[pre][1]+(lr[i].1-lr[pre].1+lr[i].1-lr[i].0));
            dp[i][1] = dp[i][1].min(dp[pre][1]+(lr[pre].1-lr[i].0+lr[i].1-lr[i].0));
        } else {
            if lr[i].0 > lr[pre].1 {
                dp[i][0] = dp[i][0].min(dp[pre][1]+(lr[i].1-lr[i].0)*2+lr[i].0-lr[pre].1);
                dp[i][1] = dp[i][1].min(dp[pre][1]+lr[i].1-lr[pre].1);
            } else {
                dp[i][1] = dp[i][1].min(dp[pre][1]+(lr[i].1-lr[i].0)*2+lr[pre].1-lr[i].1);
                dp[i][0] = dp[i][0].min(dp[pre][1]+lr[pre].1-lr[i].0);
            }
        }

        //println!("{} ({},{})->({},{}): {} {}",i,lr[pre].0,lr[pre].1,lr[i].0,lr[i].1,dp[i][0],dp[i][1]);
        pre = i;
    }
    println!("{}",dp[pre][0].min(dp[pre][1]));
}
