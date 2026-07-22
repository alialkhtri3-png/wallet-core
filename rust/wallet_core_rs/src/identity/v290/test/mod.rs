#[cfg(test)]
mod tests {
    use crate::identity::v290::SovereignIdentityEconomy;

    #[test]
    fn economy_layer_online() {
        let economy = SovereignIdentityEconomy::new();
        assert!(economy.status().contains("online"));
        assert_eq!(economy.version, "290.0.0");
    }
}
