#include "../src/mii.h"

int main(void) {
    srand(time(0));
    uint16_t seed = rand() % UINT16_MAX;
    mii_gen3_nx_t m = random_mii_gen3_nx(seed, true, "mii.bin");
    return 0;
}