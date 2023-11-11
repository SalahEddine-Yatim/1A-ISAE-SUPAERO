#include <stdio.h>

int main(void) {
    struct time {
        int minutes;
        int seconds;
    };

    struct time my_time;

    my_time.minutes = 20;
    my_time.seconds = 15;

    printf("minutes: %d\nseconds: %d\n",
           my_time.minutes,
           my_time.seconds);

    return 0;
}
