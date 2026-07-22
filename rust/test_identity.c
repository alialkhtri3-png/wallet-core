#include <stdio.h>
#include "wallet_core_rs/identity.h"

int main(){

    char *report = tw_identity_event_stream(
        "0xC9feC3B35382A27e46353005516C4f7364fc0f7A"
    );

    printf("V72 Identity Event Streaming:\n%s\n", report);

    tw_identity_string_free(report);

    return 0;
}
