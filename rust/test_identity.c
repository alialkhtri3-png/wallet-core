#include <stdio.h>
#include "wallet_core_rs/identity.h"

int main(){

    char *proof = tw_identity_generate_proof(
        "0xC9feC3B35382A27e46353005516C4f7364fc0f7A"
    );

    printf("V53 Identity Proof:\n%s\n", proof);

    tw_identity_string_free(proof);

    return 0;
}
