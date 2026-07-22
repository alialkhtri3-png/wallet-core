pub mod did;
pub mod credential;
pub mod wallet;
pub mod api;

pub const VERSION: &str = "276.0.0";

pub struct SovereignIdentityInfrastructure {
    pub version: &'static str,
}

impl SovereignIdentityInfrastructure {
    pub fn new() -> Self {
        Self { version: VERSION }
    }

    pub fn status(&self) -> String {
        format!(
            "Sovereign Identity Infrastructure V{} online",
            self.version
        )
    }
}
