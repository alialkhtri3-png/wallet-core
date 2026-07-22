#[cfg(test)]
mod tests {
    use crate::identity::v281::*;

    #[test]
    fn protocol_online() {
        assert_eq!(VERSION,"281.0.0");
    }
}
