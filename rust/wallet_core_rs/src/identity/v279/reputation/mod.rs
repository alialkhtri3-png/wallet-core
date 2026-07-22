pub fn reputation_level(score:u32)->String {

    match score {

        80..=100 => "Trusted".to_string(),

        50..=79 => "Neutral".to_string(),

        _ => "Low".to_string()
    }
}
