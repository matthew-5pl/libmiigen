#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <uchar.h>

#define CRC16            0x8005
#define BYTE(x)          x*8

#ifdef __unix__
#define uint8_t u_int8_t;
#define uint16_t u_int16_t;
#endif

// Type representing a gen3 switch Mii. 
// From kaitai docs at https://raw.githubusercontent.com/HEYimHeroic/mii2studio/master/gen3_switch.ksy
typedef struct
{
    // Hair type. Ranges from 0 to 131. Not ordered the same as visible in editor.
    uint8_t hair_type : BYTE(1);
    // Enable mole. 0 = no, 1 = yes.
    bool mole_enable : 1;
    // Body height. Ranges from 0 to 127, short to tall. In the Mii editor, pressing right will add 1 to this value, and pressing left will subtract 1, allowing for precise editing.
    uint64_t body_height : 7;
    // Flip hair. 0 = no, 1 = yes.
    bool hair_flip : 1;
    // Body weight. Ranges from 0 to 127, small to large. In the Mii editor, pressing right will add 1 to this value, and pressing left will subtract 1, allowing for precise editing.
    uint64_t body_weight : 1;
    // Toggle if the Mii is a Special Mii. Completely unused functionality. Does not allow editing the Mii, or using the Mii in games.
    bool special_type : 1;
    // Hair color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint64_t hair_color : 1;
    // Mii gender. 0 = male, 1 = female.
    bool gender : 1;
    // Eye color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint64_t eye_color : 7;
    // Eyebrow color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint8_t eyebrow_color : BYTE(1);
    // Mouth color. The default colors are ordered the same as visible in editor, ranging from 19 to 23. The custom colors are not and range from 0 to 99.
    uint8_t mouth_color : BYTE(1);
    // Facial hair color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint8_t facial_hair_color : BYTE(1);
    // Glasses color. Ranges from 0 to 99. Not ordered the same as visible in editor.
    uint8_t glasses_color : BYTE(1);
    // Currently unknown.
    uint64_t region_move : 2;
    // Eye type. Ranges from 0 to 59. Not ordered the same as visible in editor.
    uint64_t eye_type : 6;
    // Font region. 0 = USA + PAL + JPN, 1 = CHN, 2 = KOR, 3 = TWN.
    uint64_t font_region : 2;
    // Mouth type. Ranges from 0 to 35. Not ordered the same as visible in editor.
    uint64_t mouth_type : 6;
    // Glasses size. Ranges from 0 to 7, small to big.
    uint64_t glasses_size : 3;
    // Eye Y (vertical position. Ranges from 18 to 0, low to high.
    uint64_t eye_vertical : 5;
    // Mustache type. Ranges from 0 to 5.
    uint64_t facial_hair_mustache : 3;
    // Eyebrow type. Ranges from 0 to 23. Not ordered the same as visible in editor.
    uint64_t eyebrow_type : 5;
    // Beard type. Ranges from 0 to 5.
    uint64_t facial_hair_beard : 3;
    // Nose type. Ranges from 0 to 17. Not ordered the same as visible in editor.
    uint64_t nose_type : 5;
    // Mouth stretch. Ranges from 0 to 6, small to big.
    uint64_t mouth_stretch : 3;
    // Nose Y (vertical position. Ranges from 18 to 0, low to high.
    uint64_t nose_vertical : 5;
    // Eyebrow stretch. Ranges from 0 to 6, small to big.
    uint64_t eyebrow_stretch : 3;
    // Mouth Y (vertical position. Ranges from 18 to 0, low to high.
    uint64_t mouth_vertical : 5;
    // Eye rotation. Ranges from 0 to 7, down to up. Note that some eye types have a default rotation.
    uint64_t eye_rotation : 3;
    // Mustache Y (vertical position. Ranges from 22 to 0, low to high.
    uint64_t facial_hair_vertical : 5;
    // Eye stretch. Ranges from 0 to 6, small to big.
    uint64_t eye_stretch : 3;
    // Glasses Y (vertical position. Ranges from 20 to 0, low to high.
    uint64_t glasses_vertical : 5;
    // Eye size. Ranges from 0 to 7, small to big.
    uint64_t eye_size : 3;
    // Mole X (horizontal position. Ranges from 0 to 16, left to right.
    uint64_t mole_horizontal : 5;
    // Mole Y (vertical position. Ranges from 30 to 0, low to high.
    uint8_t mole_vertical : BYTE(1);
    // Glasses type. Ranges from 0 to 19. Not ordered the same as visible in editor.
    uint8_t glasses_type : BYTE(1);
    // Face shape. Ranges from 0 to 11. Not ordered the same as visible in editor.
    uint64_t face_type : 4;
    // Favorite color. Ranges from 0 to 11.
    uint64_t favorite_color : 4;
    // Face wrinkles. Ranges from 0 to 11.
    uint64_t face_wrinkles : 4;
    // Skin color. Ranges from 0 to 9. Not ordered the same as visible in editor.
    uint64_t face_color : 4;
    // Eye X (horizontal distance. Ranges from 0 to 12, close to far.
    uint64_t eye_horizontal : 4;
    // Face makeup. Ranges from 0 to 11.
    uint64_t face_makeup : 4;
    // Eyebrow rotation. Ranges from 0 to 11, down to up. Note that some eye types have a default rotation.
    uint64_t eyebrow_rotation : 4;
    // Eyebrow size. Ranges from 0 to 8, small to big.
    uint64_t eyebrow_size : 4;
    // Eyebrow Y (vertical position. Ranges from 15 to 0, low to high.
    uint64_t eyebrow_vertical : 4;
    // Eyebrow X (horizontal distance. Ranges from 0 to 12, close to far.
    uint64_t eyebrow_horizontal : 4;
    // Mouth size. Ranges from 0 to 8, small to big.
    uint64_t mouth_size : 4;
    // Nose size. Ranges from 0 to 8, small to big.
    uint64_t nose_size : 4;
    // Mole size. Ranges from 0 to 8, small to big.
    uint64_t mole_size : 4;
    // Mustache size. Ranges from 0 to 8, small to big.
    uint64_t facial_hair_size : 4;
    // Mii name. Can be up to 10 characters long.
    char16_t mii_name[20];
    //Unique Mii identifier. Randomly generated. Make sure that the leftmost bit in byte 9 of the Mii ID is set to 1, as otherwise, the Mii will be deemed invalid and your Mii DB will be deleted on console boot.
    uint8_t mii_id : BYTE(1);
    // A checksum (CRC-16/XMODEM on the Mii data (all previous data in the file.
    uint8_t checksum_mii : BYTE(1);
    // A checksum (CRC-16/XMODEM on both the previous Mii data/checksum, and the device's console ID (stored separately. Seems to end up generating the same thing per-console, though.
    uint8_t checksum_console : BYTE(1);
} mii_gen3_nx_t;

// Shift seed
uint16_t shift_seed(uint16_t *seed);

// Generate a random Mii
mii_gen3_nx_t random_mii_gen3_nx(uint16_t seed, bool dump, char *fn);