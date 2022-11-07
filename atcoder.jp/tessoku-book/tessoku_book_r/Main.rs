use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        s: usize,
        a: [usize; n],
    };
    let mut dp=vec![false; 1_000_000];
    dp[0]=true;
    for i in &a {
        for j in (0..1_000_000).rev() {
            if dp[j]&&i+j<1_000_000 {
                dp[i+j]=true;
            }
        }
    }
    println!("{}",if dp[s] { "Yes" } else { "No" });
}