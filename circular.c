// including libraries for input and output and string methods
#include <stdio.h>
#include <string.h>

// decleration of the circular buffer and its variables
char buffer[300];
int head = 0;
int tail = 0;
int count = 0;
int SIZE = 0;

// initialization of the cicular buffer
void init(int s) {
    SIZE = s;
    head = 0;
    tail = 0;
    count = 0;
}

// discussion filled buffer state
int is_full() {
    return count == SIZE;
}

// discussion empty buffer state
int is_empty() {
    return count == 0;
}

// the writing in circular buffer method
int write_char(char c) {
    if (is_full()) {
        return 0;
    }
    buffer[head] = c;
    head = (head + 1) % SIZE;
    count++;
    return 1;
}

// the reading from circular buffer method
int read_char(char *c) {
    if (is_empty()) {
        return 0;
    }
    *c = buffer[tail];
    tail = (tail + 1) % SIZE;
    count--;
    return 1;
}

// main fucntion
int main() {
    char name[100];
    char combined[200];

    printf("Enter Your Name:");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    strcpy(combined, name);
    strcat(combined, " CE-ESY");

    int len = strlen(combined);

    printf(" trying to store: %s\n", combined);

    // ============================
    // testing a small storage
    // ============================
    printf("\n===testing a small storage===\n");
    init(5);

    for (int i = 0; i < len; i++) {
        if (!write_char(combined[i])) {
            printf("storage is filled at the character '%c'\n", combined[i]);
            break;
        }
    }

    printf("the reading of what we stored: ");
    char c;
    while (read_char(&c)) {
        putchar(c);
    }

    is_empty() ? printf("\nstorage is empty\n") : printf("\nstorage is not empty\n");

    // ============================
    // testing a big storage
    // ============================
    printf("\n===testing a big storage===\n");
    init(200);

    for (int i = 0; i < len; i++) {
        write_char(combined[i]);
    }

    printf("the reading of what we stored: ");
    while (read_char(&c)) {
        putchar(c);
    }

    is_empty() ? printf("\nstorage is empty\n") : printf("\nstorage is not empty\n");

    return 0;
}