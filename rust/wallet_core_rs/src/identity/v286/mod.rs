pub mod cloud;
pub mod workers;
pub mod memory;
pub mod network;
pub mod resolver;
pub mod credentials;
pub mod agents;
pub mod sync;
pub mod api;
pub mod test;

pub const VERSION: &str = "286.0.0";

pub struct SovereignIdentityCloudRuntime {
    pub version: &'static str,
}

impl SovereignIdentityCloudRuntime {
    pub fn new() -> Self {
        Self { version: VERSION }
    }

    pub fn status(&self) -> String {
        format!("Sovereign Identity Cloud Runtime V{} online", self.version)
    }
}
