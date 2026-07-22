pub mod agent;
pub mod events;
pub mod monitor;
pub mod decision;
pub mod did;
pub mod credential;
pub mod graph;
pub mod api;
pub mod test;

pub const VERSION: &str = "284.0.0";

pub struct AutonomousIdentityAgent {
    pub version: &'static str,
}

impl AutonomousIdentityAgent {
    pub fn new() -> Self {
        Self { version: VERSION }
    }

    pub fn status(&self) -> String {
        format!("Sovereign Autonomous Identity Agent V{} online", self.version)
    }
}
