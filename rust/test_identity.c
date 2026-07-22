#include <stdio.h>
#include "wallet_core_rs/identity.h"

int main() {

    char *status = tw_identity_engine_status();
    printf("Status: %s\n", status);
    tw_identity_string_free(status);

    printf("Score: %u\n", tw_identity_get_score());

    char *identity = tw_identity_analyze_wallet();
    printf("Identity: %s\n", identity);
    tw_identity_string_free(identity);

    char *rep = tw_identity_get_reputation();
    printf("Reputation: %s\n", rep);
    tw_identity_string_free(rep);

    char *vc = tw_identity_export_vc();
    printf("VC: %s\n", vc);
    tw_identity_string_free(vc);

    return 0;
}
