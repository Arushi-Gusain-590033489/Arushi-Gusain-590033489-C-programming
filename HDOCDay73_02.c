#include <stdio.h>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

int main() {
    enum TrafficLight light = GREEN;

    if (light == RED)
        printf("Stop");
    else if (light == YELLOW)
        printf("Wait");
    else if (light == GREEN)
        printf("Go");

    return 0;
}
