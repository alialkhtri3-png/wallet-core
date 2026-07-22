#[derive(Debug)]
pub struct Credential {
    pub issuer: String,
    pub subject: String,
}

impl Credential {
    pub fn new(issuer: &str, subject: &str) -> Self {
        Self {
            issuer: issuer.into(),
            subject: subject.into(),
        }
    }
}

pub fn verify(subject: &str) -> bool {
    !subject.is_empty()
}
