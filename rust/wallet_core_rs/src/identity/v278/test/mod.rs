#[cfg(test)]
mod tests {

    use crate::identity::v278::ProductionIdentityEngine;

    #[test]
    fn production_identity_engine_online() {

        let engine = ProductionIdentityEngine::new();

        assert!(
            engine.status().contains("online")
        );

        assert_eq!(
            engine.version,
            "278.0.0"
        );
    }
}
