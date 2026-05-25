#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct {
    char storage[MAX_SIZE];
    int head;
    int tail;
    int total;
} RingBuffer;

void prepare(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->total = 0;
}

int checkEmpty(const RingBuffer *rb) {
    return rb->total == 0;
}

int checkFull(const RingBuffer *rb) {
    return rb->total == MAX_SIZE;
}

void pushData(RingBuffer *rb, char val) {
    if (checkFull(rb)) {
        printf("Buffer Full\n");
        return;
    }
    rb->storage[rb->tail] = val;
    rb->tail = (rb->tail + 1) % MAX_SIZE;
    rb->total++;
}

char popData(RingBuffer *rb) {
    if (checkEmpty(rb)) {
        printf("Buffer Empty\n");
        return '\0';
    }
    char val = rb->storage[rb->head];
    rb->head = (rb->head + 1) % MAX_SIZE;
    rb->total--;
    return val;
}

int main() {
    RingBuffer myBuffer;
    prepare(&myBuffer);

    char inputStr[50];
    printf("Enter your name: ");
    scanf("%49s", inputStr);
    strcat(inputStr, "CE-ESY");

    for (int i = 0; i < (int)strlen(inputStr); i++) {
        pushData(&myBuffer, inputStr[i]);
    }

    while (!checkEmpty(&myBuffer)) {
        char letter = popData(&myBuffer);
        printf("%c", letter);
    }
    
    printf("\n");
    return 0;
}


//
