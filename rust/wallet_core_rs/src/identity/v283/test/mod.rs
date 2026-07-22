#[cfg(test)]
mod tests {
    use crate::identity::v283::OnchainIntelligenceRuntime;

    #[test]
    fn runtime_online() {
        let engine = OnchainIntelligenceRuntime::new();

        assert!(engine.status().contains("online"));
        assert_eq!(engine.version, "283.0.0");
    }
}
