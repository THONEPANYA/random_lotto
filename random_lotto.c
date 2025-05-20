#include <stdio.h>
#include <string.h>

#define NUM_ENTRIES 5
#define DIGITS_PER_ENTRY 6

int main() {
    char entries[NUM_ENTRIES][DIGITS_PER_ENTRY + 1];
    int all_digits[NUM_ENTRIES * DIGITS_PER_ENTRY];
    int sum = 0, digit_count[10] = {0};
    int idx = 0;

    printf("กรอกเลข 6 หลัก จากทั้งหมด %d งวด:\n", NUM_ENTRIES);

    for (int i = 0; i < NUM_ENTRIES; i++) {
        printf("งวดที่ %d: ", i + 1);
        scanf("%s", entries[i]);

        if (strlen(entries[i]) != 6) {
            printf("เลขต้องมี 6 หลักเท่านั้น!\n");
            return 1;
        }

        for (int j = 0; j < DIGITS_PER_ENTRY; j++) {
            int d = entries[i][j] - '0';
            if (d < 0 || d > 9) {
                printf("ต้องเป็นตัวเลขเท่านั้น!\n");
                return 1;
            }
            all_digits[idx++] = d;
            sum += d;
            digit_count[d]++;
        }
    }

    printf("\n🔢 ผลรวมตัวเลขทั้งหมด: %d\n", sum);
    printf("เลข 2 หลักที่ได้: %02d\n", sum % 100);
    printf("เลข 3 หลักที่ได้: %03d\n", sum % 1000);
    printf("เลข 4 หลักที่ได้: %04d\n", (sum * 123) % 10000);
    printf("เลข 6 หลักที่ได้: %06d\n", (sum * 123456) % 1000000);

    printf("\n📊 ความถี่ของตัวเลข:\n");
    for (int i = 0; i < 10; i++) {
        printf("เลข %d ออก %d ครั้ง\n", i, digit_count[i]);
    }

    return 0;
}
