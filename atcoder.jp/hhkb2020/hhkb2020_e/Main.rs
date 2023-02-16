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

#[fastout]
fn main() {
    input! {
        h: usize,
        w: usize,
        s: [Chars; h],
    }
    let mut cnt = 0;
    for x in 0..h {
        for y in 0..w {
            cnt += (s[x][y] == '.') as i64;
        }
    }
    
    let mut l = vec![vec![0; w]; h];
    let mut r = vec![vec![0; w]; h];
    let mut u = vec![vec![0; w]; h];
    let mut d = vec![vec![0; w]; h];
    
    for x in 0..h {
        for y in 0..w {
            if y == 0 {
                l[x][y] = (s[x][y] == '.') as usize; 
                r[x][w-y-1] = (s[x][w-y-1] == '.') as usize; 
            } else {
                if s[x][y] == '.' {
                    l[x][y] += l[x][y-1] + 1;
                }
                if s[x][w-y-1] == '.' {
                    r[x][w-y-1] += r[x][w-y] + 1;
                }
            }
        }
    }

    for y in 0..w {
        for x in 0..h {
            if x == 0 {
                u[x][y] = (s[x][y] == '.') as usize; 
                d[h-x-1][y] = (s[h-x-1][y] == '.') as usize; 
            } else {
                if s[x][y] == '.' {
                    u[x][y] += u[x-1][y] + 1;
                }
                if s[h-x-1][y] == '.' {
                    d[h-x-1][y] += d[h-x][y] + 1;
                }
            }
        }
    }

    //println!("{:?}",l);
    //println!("{:?}",r);
    //println!("{:?}",u);
    //println!("{:?}",d);
    
    let mut ans = mod_pow(2,cnt,MOD as i32) * cnt;
    ans %= MOD as i64;
    
    for x in 0..h {
        for y in 0..w {
            if s[x][y] == '.' {
                let z = (l[x][y] + r[x][y] + u[x][y] + d[x][y]) as i64 - 3;
                ans = safe_mod(ans + MOD as i64 - mod_pow(2, cnt-z, MOD as i32), MOD as i64);
            }
        }
    }
    
    println!("{}",ans);
}

pub fn safe_mod(mut x: i64, m: i64) -> i64 {
    x %= m;
    if x < 0 {
        x += m;
    }
    x
}

pub fn mod_pow(x: i64, mut n: i64, m: i32) -> i64 {
    if m == 1 {
        return 0;
    }
    let _m = m as u32;
    let mut r: u64 = 1;
    let mut y: u64 = safe_mod(x, m as i64) as u64;
    while n!=0 {
        if (n & 1) > 0 {
            r = (r * y) % (_m as u64);
        }
        y = (y * y) % (_m as u64);
        n >>= 1;
    }
    r as i64
}
