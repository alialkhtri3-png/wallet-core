pub mod did;
pub mod credential;
pub mod verifier;

pub const VERSION: &str = "274.2.0";

#[derive(Debug)]
pub struct IdentityCore {
    pub version: String,
}

impl IdentityCore {
    pub fn new() -> Self {
        Self {
            version: VERSION.to_string(),
        }
    }

    pub fn status(&self) -> String {
        format!("Sovereign Identity Core {} online", self.version)
    }
}
