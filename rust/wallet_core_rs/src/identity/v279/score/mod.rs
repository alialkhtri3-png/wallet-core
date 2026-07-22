pub fn identity_score(activity:u32)->u32 {
    if activity > 100 {
        100
    } else {
        activity
    }
}
