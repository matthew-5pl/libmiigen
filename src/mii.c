#include "mii.h"

uint8_t gen_crc16(const uint8_t *data, uint16_t size)
{
    uint8_t out = 0;
    int bits_read = 0, bit_flag;

    /* Sanity check: */
    if(data == NULL)
        return 0;

    while(size > 0)
    {
        bit_flag = out >> 15;

        /* Get next bit: */
        out <<= 1;
        out |= (*data >> bits_read) & 1; // item a) work from the least significant bits

        /* Increment bit counter: */
        bits_read++;
        if(bits_read > 7)
        {
            bits_read = 0;
            data++;
            size--;
        }

        /* Cycle check: */
        if(bit_flag)
            out ^= CRC16;

    }

    // item b) "push out" the last 16 bits
    int i;
    for (i = 0; i < 16; ++i) {
        bit_flag = out >> 15;
        out <<= 1;
        if(bit_flag)
            out ^= CRC16;
    }

    // item c) reverse the bits
    uint8_t crc = 0;
    i = 0x8000;
    int j = 0x0001;
    for (; i != 0; i >>=1, j <<= 1) {
        if (i & out) crc |= j;
    }

    return crc;
}

// Shift seed
uint16_t shift_seed(uint16_t *seed)
{
    if(*seed == 0)
    {
        *seed += rand() % UINT16_MAX;
    }
    else
    {
        printf("libmiigen: shifting seed %x...\n", *seed);
        *seed = time(0) % *seed;
        srand(*seed);
        printf("libmiigen: done %x.\n", *seed);
    }
    return *seed;
}

// Generate a random Mii.
mii_gen3_nx_t random_mii_gen3_nx(uint16_t seed, bool dump, char *fn)
{
    printf("libmiigen: begin generating a random mii\n");
    srand(seed);
    mii_gen3_nx_t mii;
    mii.hair_type = rand() % 131;
    shift_seed(&seed);
    mii.mole_enable = rand() % 1;
    shift_seed(&seed);
    mii.body_height = rand() % 127;
    shift_seed(&seed);
    mii.hair_flip = rand() % 1;
    shift_seed(&seed);
    mii.body_weight = rand() % 127;
    shift_seed(&seed);
    mii.special_type = rand() % 1;
    shift_seed(&seed);
    mii.hair_color = rand() % 99;
    shift_seed(&seed);
    mii.gender = rand() % 1;
    shift_seed(&seed);
    mii.eye_color = rand() % 99;
    shift_seed(&seed);
    mii.eyebrow_color = rand() % 99;
    shift_seed(&seed);
    mii.mouth_color = rand() % 99;
    shift_seed(&seed);
    mii.facial_hair_color = rand() % 100;
    shift_seed(&seed);
    mii.glasses_color = rand() % 100;
    shift_seed(&seed);
    mii.region_move = rand() % 1;
    shift_seed(&seed);
    mii.eye_type = rand() % 59;
    shift_seed(&seed);
    mii.font_region = rand() % 4;
    shift_seed(&seed);
    mii.mouth_type = rand() % 35;
    shift_seed(&seed);
    mii.glasses_size = rand() % 7;
    shift_seed(&seed);
    mii.eye_vertical = rand() % 18;
    shift_seed(&seed);
    mii.facial_hair_mustache = rand() % 5;
    shift_seed(&seed);
    mii.eyebrow_type = rand() % 23;
    shift_seed(&seed);
    mii.facial_hair_beard = rand() % 5;
    shift_seed(&seed);
    mii.nose_type = rand() % 17;
    shift_seed(&seed);
    mii.mouth_stretch = rand() % 6;
    shift_seed(&seed);
    mii.nose_vertical = rand() % 17;
    shift_seed(&seed);
    mii.eyebrow_stretch = rand() % 6;
    shift_seed(&seed);
    mii.mouth_vertical = rand() % 18;
    shift_seed(&seed);
    mii.eye_rotation = rand() % 7;
    shift_seed(&seed);
    mii.facial_hair_vertical = rand() % 22;
    shift_seed(&seed);
    mii.eye_stretch = rand() % 6;
    shift_seed(&seed);
    mii.mole_horizontal = rand() % 16;
    shift_seed(&seed);
    mii.mole_vertical = rand() % 30;
    shift_seed(&seed);
    mii.glasses_type = rand() % 19;
    shift_seed(&seed);
    mii.face_type = rand() % 11;
    shift_seed(&seed);
    mii.favorite_color = rand() % 11;
    shift_seed(&seed);
    mii.face_wrinkles = rand() % 11;
    shift_seed(&seed);
    mii.face_color = rand() % 9;
    shift_seed(&seed);
    mii.eye_horizontal = rand() % 12;
    shift_seed(&seed);
    mii.face_makeup = rand() % 11;
    shift_seed(&seed);
    mii.eyebrow_rotation = rand() % 11;
    shift_seed(&seed);
    mii.eyebrow_size = rand() % 8;
    shift_seed(&seed);
    mii.eyebrow_vertical = rand() % 15;
    shift_seed(&seed);
    mii.eyebrow_horizontal = rand() % 12;
    shift_seed(&seed);
    mii.mouth_size = rand() % 8;
    shift_seed(&seed);
    mii.nose_size = rand() % 8;
    shift_seed(&seed);
    mii.mole_size = rand() % 8;
    shift_seed(&seed);
    mii.facial_hair_size = rand() % 8;
    shift_seed(&seed);
    strcpy(mii.mii_name, "Example");
    mii.mii_id = rand() % UINT8_MAX;
    mii.checksum_mii = gen_crc16(&mii, sizeof(mii_gen3_nx_t));
    mii.checksum_console = gen_crc16(&mii, sizeof(mii_gen3_nx_t));
    printf("libmiigen: done generating mii%x.\n", &mii);
    if(dump)
    {
        printf("libmiigen: dumping mii to %s...\n", fn);
        FILE *f = fopen(fn, "wb");
        fwrite(&mii, sizeof(mii_gen3_nx_t), 1, f);
        fclose(f);
    }
    else
    {
        printf("libmiigen: skipping dump.\n");
    }
    return mii;
}