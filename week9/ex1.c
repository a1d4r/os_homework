#include <stdio.h>
#include <stdlib.h>

#define PRINT_ACTIONS 0

int main(int argc, char *argv[]) {
    // read the number of page frames
    if (argc != 2) {
        printf("Wrong number of arguments!\n");
        return 0;
    }
    int n_page_frames = atoi(argv[1]);
    
    // open the file with pages
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("The file cannot be read!\n");
        return 0;
    }
    
    // page frames
    int page[n_page_frames], r_bit[n_page_frames];

    // 8-bit counter 
    unsigned char counter[n_page_frames];

    for (int i = 0; i < n_page_frames; i++) {
        page[i] = -1; // empty
        r_bit[i] = 0;
        counter[i] = 0;
    }

    int hits = 0, misses = 0;

    // read pages
    while (!feof(input)) {
        int next_page;
        int rc = fscanf(input, "%d", &next_page);
        if (rc != 1)
            break;
    
        // search the page
        char found_page = 0;
        for (int i = 0; i < n_page_frames; i++)
            if (next_page == page[i]) { // hit
                hits++;
                r_bit[i] = 1;
                found_page = 1;
                if (PRINT_ACTIONS) printf("Page %d is already in the table\n", next_page);
                break;
            }

        if (!found_page) { // miss
            misses++;

            // search empty
            int index = -1;
            for (int i = 0; i < n_page_frames; i++)
                if (page[i] == -1) {
                    index = i;
                    break;
                }

            if (index != -1) { // replace empty page
                page[index] = next_page;
                r_bit[index] = 1;
                counter[index] = 0;
                if (PRINT_ACTIONS) printf("Adding page %d\n", next_page);
            } else { // no empty page, find the page with the minimal counter
                index = 0;
                for (int i = 0; i < n_page_frames; i++)
                    if (counter[i] < counter[index])
                        index = i;
                if (PRINT_ACTIONS) printf("Replacing page %d with page %d\n", page[index], next_page);
                page[index] = next_page;
                r_bit[index] = 1;
                counter[index] = 0;
            }
        }

        // update counters and R-bits
        for (int i = 0; i < n_page_frames; i++) {
            counter[i] >>= 1;
            counter[i] |= r_bit[i] << 7;
            r_bit[i] = 0;
        }

    }

    printf("Page frames: %d\n", n_page_frames);
    printf("Hits: %d\n", hits);
    printf("Misses: %d\n", misses);
    printf("Hits/Misses: %f\n", (double) hits/misses);

    return 0;
}