pub mod runtime;
pub mod orchestrator;
pub mod policy;
pub mod events;
pub mod ai;
pub mod execution;
pub mod state;
pub mod graph;
pub mod did;
pub mod credential;
pub mod api;
pub mod test;

pub const VERSION: &str = "285.0.0";

pub struct IdentityOperatingSystem {
    pub version: &'static str,
}

impl IdentityOperatingSystem {
    pub fn new() -> Self {
        Self { version: VERSION }
    }

    pub fn status(&self) -> String {
        format!("Sovereign Identity Operating System V{} online", self.version)
    }
}
