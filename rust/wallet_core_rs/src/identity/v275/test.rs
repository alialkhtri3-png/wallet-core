#[cfg(test)]
mod tests {
    use crate::identity::v275::SovereignIdentityEngine;

    #[test]
    fn sovereign_identity_engine_online() {
        let engine = SovereignIdentityEngine::new();

        assert!(engine.status().contains("Multi-Chain Identity Engine"));

        assert_eq!(
            engine.version,
            "275.0.0"
        );
    }
}
