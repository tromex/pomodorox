/*
 * Pomodorox
 *
 * Author: tromex <tromersebastian@gmail.com>
 * Date: 13/01/2016
 *
 * MIT License
 *
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Color definitions
#ifdef NOCOLOR
#define ANSI_COLOR_RED     ""
#define ANSI_COLOR_GREEN   ""
#define ANSI_COLOR_YELLOW  ""
#define ANSI_COLOR_BLUE    ""
#define ANSI_COLOR_MAGENTA ""
#define ANSI_COLOR_CYAN    ""
#define ANSI_COLOR_RESET   ""
#else
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#endif

#define SCREEN_HEIGHT 100

void clear_screen();
void run_timer(unsigned int seconds);

int main(int argc, char **argv)
{
    // locals
    bool flag = false;

    // title
    clear_screen();
    printf(ANSI_COLOR_GREEN "\n\n  Pomodorox  \n\n");

    // start pomodoro timer
    run_timer(25 * 60);

    // timer end
    while (1) {
        if (flag)
            printf(ANSI_COLOR_RED "             \r");
        else
            printf(ANSI_COLOR_RED "    00:00    \r");

        flag = !flag;
        fflush(stdout);
        usleep(100000);
    }

    return EXIT_SUCCESS;
}

void clear_screen()
{
    for (int i=0; i<SCREEN_HEIGHT; i++)
        printf("\n");
}

void run_timer(unsigned int seconds) {
    unsigned char m, s;

    for(int i=seconds; i>0; i--) {
        // compute minutes and seconds from i
        m = i / 60;
        s = i % 60;

        // show timer and wait 1 second
        printf(ANSI_COLOR_RESET "    %02d:%02d    \r", m, s);
        fflush(stdout);
        sleep(1);
    }
}
