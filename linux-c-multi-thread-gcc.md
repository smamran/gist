## Linux C Multi-thread Using g++
```c
#include <assert.h>  //	Conditionally compiled macro that compares its argument to zero
#include <complex.h> // (since C99) 	Complex number arithmetic
#include <ctype.h>   //	Functions to determine the type contained in character data
#include <errno.h>   //	Macros reporting error conditions
#include <fenv.h>    // (since C99) 	Floating-point environment
#include <float.h> 	// Limits of float types
#include <inttypes.h>// (since C99) 	Format conversion of integer types
#include <iso646.h>  // (since C95) 	Alternative operator spellings
#include <limits.h>  //	Sizes of basic types
#include <locale.h>  //	Localization utilities
#include <math.h> 	// Common mathematics functions
#include <setjmp.h> 	// Nonlocal jumps
#include <signal.h> 	// Signal handling
//#include <stdalign.h>// (since C11) 	alignas and alignof convenience macros
#include <stdarg.h> 	// Variable arguments
//#include <stdatomic.h>// (since C11) 	Atomic types
#include <stdbool.h> // (since C99) 	Boolean type
#include <stddef.h> 	// Common macro definitions
#include <stdint.h>  // (since C99) 	Fixed-width integer types
#include <stdio.h> 	// Input/output
#include <stdlib.h> 	// General utilities: memory management, program utilities, string conversions, random numbers
//#include <stdnoreturn.h> // (since C11) 	noreturn convenience macros
#include <string.h> 	// String handling
//#include <tgmath.h>  // (since C99) 	Type-generic math (macros wrapping math.h and complex.h)
//#include <threads.h> // (since C11) 	Thread library
#include <time.h> 	// Time/date utilities
//#include <uchar.h>   // (since C11) 	UTF-16 and UTF-32 character utilities
#include <wchar.h>   // (since C95) 	Extended multibyte and wide character utilities
#include <wctype.h>  // (since C95) 	Wide character classification and mapping utilities

#include <pthread.h>
#include <unistd.h>

//==========================================================================================
//==========================================================================================
//==========================================================================================

using namespace std;

/* Prints x's to stderr. The parameter is unused. Does not return. */
void *print_xs (void* unused)
{
    while (1){
        fputc ('x', stderr);
        usleep(10000);
    }
}

void *print_100(void* unused){
    int i = 10000;
    while(i){
        printf("%d",i--);
        usleep(10000);
    }
}

int main ()
{
    pthread_t thread_id;
    pthread_t print_100_thread;

    pthread_create (&thread_id, NULL, print_xs, 0);
    pthread_create (&print_100_thread, NULL, print_100, 0);

    pthread_join(thread_id,NULL);
    pthread_join(print_100_thread, NULL);

    return 0;
}
```
