pub fn issue_credential(subject: &str) -> String {
    format!("VC issued for {}", subject)
}
