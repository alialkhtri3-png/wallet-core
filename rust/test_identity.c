#include <stdio.h>
#include "wallet_core_rs/identity.h"

int main(){

    char *report = tw_identity_zk_proof_generate(
        "0xC9feC3B35382A27e46353005516C4f7364fc0f7A"
    );

    printf("V63 Zero Knowledge Identity Proof:\n%s\n", report);

    tw_identity_string_free(report);

    return 0;
}
