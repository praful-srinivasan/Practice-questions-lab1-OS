#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;

// Renamed to avoid conflicts with system headers
void custom_wait(int *s) {
    (*s)--;
}

void custom_signal(int *s) {
    (*s)++;
}

void producer(int next_prod) {
    if (empty != 0) {
        custom_wait(&empty);
        custom_wait(&mutex);

        buffer[in] = next_prod;
        printf("Producer produced: %d at position %d\n", next_prod, in);
        in = (in + 1) % BUFFER_SIZE;

        custom_signal(&mutex);
        custom_signal(&full);
    } else {
        printf("Buffer full, producer waiting...\n");
    }
}

void consumer() {
    int next_cons;
    if (full != 0) {
        custom_wait(&full);
        custom_wait(&mutex);

        next_cons = buffer[out];
        printf("Consumer consumed: %d from position %d\n", next_cons, out);
        out = (out + 1) % BUFFER_SIZE;

        custom_signal(&mutex);
        custom_signal(&empty);
    } else {
        printf("Buffer empty, consumer waiting...\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            break; 
        }

        switch (choice) {
            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                producer(item);
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("\nExiting. A Praful Srinivasan\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}