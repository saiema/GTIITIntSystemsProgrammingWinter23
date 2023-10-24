#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void im_dead(int sig) {
    if (sig == SIGTERM || sig == SIGINT) {
        puts("\nNoooooo!!!! I'm dying!!!!!\n");
        fflush(stdout);
        exit(sig);
    }
}

void main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Wrong amount of arguments (%d)\n", argc - 1);
        printf("Call me and just give me a name :)");
        exit(1);
    }
    signal(SIGTERM, im_dead);
    signal(SIGINT, im_dead);
    const int pid = getpid();
    char * name = argv[1];
    printf("Howdy! My name is %s (%d), very nice to meet you! :)\n", argv[1], pid);
    while(1) {
        printf("I'm %s (%d), and I'm so happy!\n", argv[1], pid);
        sleep(2);
    }
}