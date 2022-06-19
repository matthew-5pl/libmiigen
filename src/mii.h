#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define CRC16            0x8005
#define MAX_UINT8_T      255

#ifdef __unix__
#define uint8_t u_int8_t;
#define uint16_t u_int16_t;
#endif

// Type representing a gen3 switch Mii. 
// From kaitai docs at https://raw.githubusercontent.com/HEYimHeroic/mii2studio/master/gen3_switch.ksy
typedef struct
{
    // Hair type. Ranges from 0 to 131. Not ordered the same as visible in editor.
    uint8_t hair_type;
    // Enable mole. 0 = no, 1 = yes.
    bool mole_enable;
    // Body height. Ranges from 0 to 127, short to tall. In the Mii editor, pressing right will add 1 to this value, and pressing left will subtract 1, allowing for precise editing.
    uint64_t body_height;
    // Flip hair. 0 = no, 1 = yes.
    bool hair_flip;
    // Body weight. Ranges from 0 to 127, small to large. In the Mii editor, pressing right will add 1 to this value, and pressing left will subtract 1, allowing for precise editing.
    uint64_t body_weight;
    // Toggle if the Mii is a Special Mii. Completely unused functionality. Does not allow editing the Mii, or using the Mii in games.
    bool special_type;
    // Hair color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint64_t hair_color;
    // Mii gender. 0 = male, 1 = female.
    bool gender;
    // Eye color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint64_t eye_color;
    // Eyebrow color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint8_t eyebrow_color;
    // Mouth color. The default colors are ordered the same as visible in editor, ranging from 19 to 23. The custom colors are not and range from 0 to 99.
    uint8_t mouth_color;
    // Facial hair color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint8_t facial_hair_color;
    // Glasses color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint8_t glasses_color;
    // Currently unknown.
    uint64_t region_move;
    // Eye type. Ranges from 0 to 59. Not ordered the same as visible in editor.
    uint64_t eye_type;
    // Font region. 0 = USA + PAL + JPN, 1 = CHN, 2 = KOR, 3 = TWN.
    uint64_t font_region;
    // Mouth type. Ranges from 0 to 35. Not ordered the same as visible in editor.
    uint64_t mouth_type;
    // Glasses size. Ranges from 0 to 7, small to big.
    uint64_t glasses_size;
    // Eye Y (vertical) position. Ranges from 18 to 0, low to high.
    uint64_t eye_vertical;
    // Mustache type. Ranges from 0 to 5.
    uint64_t facial_hair_mustache;
    // Eyebrow type. Ranges from 0 to 23. Not ordered the same as visible in editor.
    uint64_t eyebrow_type;
    // Beard type. Ranges from 0 to 5.
    uint64_t facial_hair_beard;
    // Nose type. Ranges from 0 to 17. Not ordered the same as visible in editor.
    uint64_t nose_type;
    // Mouth stretch. Ranges from 0 to 6, small to big.
    uint64_t mouth_stretch;
    // Nose Y (vertical) position. Ranges from 18 to 0, low to high.
    uint64_t nose_vertical;
    // Eyebrow stretch. Ranges from 0 to 6, small to big.
    uint64_t eyebrow_stretch;
    // Mouth Y (vertical) position. Ranges from 18 to 0, low to high.
    uint64_t mouth_vertical;
    // Eye rotation. Ranges from 0 to 7, down to up. Note that some eye types have a default rotation.
    uint64_t eye_rotation;
    // Mustache Y (vertical) position. Ranges from 22 to 0, low to high.
    uint64_t facial_hair_vertical;
    // Eye stretch. Ranges from 0 to 6, small to big.
    uint64_t eye_stretch;
    // Glasses Y (vertical) position. Ranges from 20 to 0, low to high.
    uint64_t glasses_vertical;
    // Eye size. Ranges from 0 to 7, small to big.
    uint64_t eye_size;
    // Mole X (horizontal) position. Ranges from 0 to 16, left to right.
    uint64_t mole_horizontal;
    // Mole Y (vertical) position. Ranges from 30 to 0, low to high.
    uint8_t mole_vertical;
    // Glasses type. Ranges from 0 to 19. Not ordered the same as visible in editor.
    uint8_t glasses_type;
    // Face shape. Ranges from 0 to 11. Not ordered the same as visible in editor.
    uint64_t face_type;
    // Favorite color. Ranges from 0 to 11.
    uint64_t favorite_color;
    // Face wrinkles. Ranges from 0 to 11.
    uint64_t face_wrinkles;
    // Skin color. Ranges from 0 to 9. Not ordered the same as visible in editor.
    uint64_t face_color;
    // Eye X (horizontal) distance. Ranges from 0 to 12, close to far.
    uint64_t eye_horizontal;
    // Face makeup. Ranges from 0 to 11.
    uint64_t face_makeup;
    // Eyebrow rotation. Ranges from 0 to 11, down to up. Note that some eye types have a default rotation.
    uint64_t eyebrow_rotation;
    // Eyebrow size. Ranges from 0 to 8, small to big.
    uint64_t eyebrow_size;
    // Eyebrow Y (vertical) position. Ranges from 15 to 0, low to high.
    uint64_t eyebrow_vertical;
    // Eyebrow X (horizontal) distance. Ranges from 0 to 12, close to far.
    uint64_t eyebrow_horizontal;
    // Mouth size. Ranges from 0 to 8, small to big.
    uint64_t mouth_size;
    // Nose size. Ranges from 0 to 8, small to big.
    uint64_t nose_size;
    // Mole size. Ranges from 0 to 8, small to big.
    uint64_t mole_size;
    // Mustache size. Ranges from 0 to 8, small to big.
    uint64_t facial_hair_size;
    // Mii name. Can be up to 10 characters long.
    char mii_name[20];
    // A checksum (CRC-16/XMODEM) on the Mii data (all previous data in the file).
    uint8_t checksum_mii[MAX_UINT8_T];
    // A checksum (CRC-16/XMODEM) on both the previous Mii data/checksum, and the device's console ID (stored separately). Seems to end up generating the same thing per-console, though.
    uint8_t checksum_console[MAX_UINT8_T];
} mii_gen3_nx_t;

// Shift seed
uint16_t shift_seed(uint16_t *seed);

// Generate a random Mii
mii_gen3_nx_t random_mii_gen3_nx(uint16_t seed, bool dump, char *fn);