#[derive(Debug)]
pub struct Credential {
    pub issuer: String,
    pub subject: String,
}

impl Credential {
    pub fn new(issuer: &str, subject: &str) -> Self {
        Self {
            issuer: issuer.to_string(),
            subject: subject.to_string(),
        }
    }
}
