/* astr.cpp
   Learning class description by using the
   "hit-and-near-miss" method
   Place an entry into the may-have database
*/

#include <iostream>
#include <cstring>
#include "ml.h"

void assert_may(const char* n, const char* v, const char* o) {
    extern attr may[];
    extern int may_pos;

    if (may_pos < MAX) {
        std::strcpy(may[may_pos].subject, n);
        std::strcpy(may[may_pos].verb, v);
        std::strcpy(may[may_pos].object, o);
        may[may_pos].active = 1;
        may_pos++;
    }
    else {
        std::cout << "Out of memory for may_have database" << std::endl;
    }
}

// Note: The struct 'attr' and constant 'MAX' should be defined in "ml.h".
