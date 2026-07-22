pub fn identity_report(wallet:&str,score:u32)->String {

    format!(
        "{{\"wallet\":\"{}\",\"identity_score\":{}}}",
        wallet,
        score
    )
}
