//use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [usize; n],
        d: usize,
        p: [(usize,usize); d],
    };
    let mut vl=vec![0; n];
    let mut vr=vec![0; n];
    vl[0]=a[0]; vr[n-1]=a[n-1];
    for i in 1..n {
        vl[i]=vl[i-1].max(a[i]);
    }
    for i in (0..n-1).rev() {
        vr[i]=vr[i+1].max(a[i]);
    }
    for (l,r) in p {
        println!("{}",vl[l-2].max(vr[r]));
    }
}
