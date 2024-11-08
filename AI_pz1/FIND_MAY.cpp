/* Find_May.cpp
   Find an entry in the "may have" database
*/
#include <cstring>
#include "ml.h"

int find_may(const char* n, const char* v, const char* o) {
    extern attr may[];
    extern int may_pos;

    for (int t = 0; t < may_pos; t++) {
        if (std::strcmp(may[t].subject, n) == 0 &&
            std::strcmp(may[t].verb, v) == 0 &&
            std::strcmp(may[t].object, o) == 0 &&
            may[t].active) {
            return t;
        }
    }
    return -1;
}
