#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct {
    char data[CAPACITY];
    int head;
    int tail;
    int count;
} ArrayLogBuffer;

void array_buffer_init(ArrayLogBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

bool array_buffer_is_empty(const ArrayLogBuffer *cb) {
    return cb->count == 0;
}

bool array_buffer_is_full(const ArrayLogBuffer *cb) {
    return cb->count == CAPACITY;
}

bool array_buffer_dequeue(ArrayLogBuffer *cb, char *out_val) {
    if (array_buffer_is_empty(cb)) {
        return false;
    }
    *out_val = cb->data[cb->head];
    cb->head = (cb->head + 1) % CAPACITY;
    cb->count--;
    return true;
}

void array_buffer_enqueue(ArrayLogBuffer *cb, char c) {
    if (array_buffer_is_full(cb)) {
        cb->head = (cb->head + 1) % CAPACITY;
        cb->count--;
        printf("[Array LogBuffer] Buffer full! Overwrote oldest character, added '%c'\n", c);
    } else {
        printf("[Array LogBuffer] Added '%c'\n", c);
    }

    cb->data[cb->tail] = c;
    cb->tail = (cb->tail + 1) % CAPACITY;
    cb->count++;
}

void array_buffer_print(const ArrayLogBuffer *cb) {
    if (array_buffer_is_empty(cb)) {
        printf("Buffer is empty [ ] (0/%d)\n", CAPACITY);
        return;
    }
    printf("Content (oldest -> newest): [ ");
    for (int i = 0; i < cb->count; i++) {
        int idx = (cb->head + i) % CAPACITY;
        printf("%c ", cb->data[idx]);
    }
    printf("] (%d/%d)\n", cb->count, CAPACITY);
}

int main(void) {
    printf("=== TESTING ARRAY IMPLEMENTATION (ARRAY LOG BUFFER) ===\n");
    ArrayLogBuffer buf;
    array_buffer_init(&buf);

    char val;

    printf("\n--- Test 1: Dequeue from an empty buffer ---\n");
    if (!array_buffer_dequeue(&buf, &val)) {
        printf("Success: Dequeue on empty buffer returned false without crashing.\n");
    }

    printf("\n--- Test 2: Filling buffer to maximum capacity (5 elements) ---\n");
    array_buffer_enqueue(&buf, 'A');
    array_buffer_enqueue(&buf, 'B');
    array_buffer_enqueue(&buf, 'C');
    array_buffer_enqueue(&buf, 'D');
    array_buffer_enqueue(&buf, 'E');
    array_buffer_print(&buf);
    printf("\n--- Test 3: Adding new elements to full buffer ---\n");
    array_buffer_enqueue(&buf, 'F');
    array_buffer_enqueue(&buf, 'G');
    array_buffer_print(&buf);
    printf("\n--- Test 4: Partial dequeue ---\n");
    if (array_buffer_dequeue(&buf, &val)) printf("Dequeued: %c\n", val);
    if (array_buffer_dequeue(&buf, &val)) printf("Dequeued: %c\n", val);
    array_buffer_print(&buf);

    return 0;
}