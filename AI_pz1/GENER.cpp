/* gener.cpp
   Generalize new examples
*/
#include <cstdio>
#include <cstring>
#include "ml.h"
#include "FIND_MAY.cpp"

extern attr may[], must[];
extern int may_pos, must_pos;
extern FILE* prtcl;

void generalize(const char* n, const char* v, const char* o) {
    int t, i;

    // Check may_have list
    for (t = 0; t < may_pos; t++) {
        if (std::strcmp(may[t].subject, n) != 0 && // not the same subject
            std::strcmp(may[t].verb, v) == 0 &&
            std::strcmp(may[t].object, o) == 0 && may[t].active) {
            std::strcat(may[t].subject, " or ");
            std::strcat(may[t].subject, n);
        }
    }
    for (t = 0; t < may_pos; t++) {
        if (std::strcmp(may[t].subject, n) == 0 &&
            std::strcmp(may[t].verb, v) == 0 &&
            std::strcmp(may[t].object, o) != 0 && // not the same object
            may[t].active) {
            std::strcat(may[t].object, " or ");
            std::strcat(may[t].object, o);
        }
    }

    // Check must_have list
    for (t = 0; t < must_pos; t++) {
        if (std::strcmp(must[t].subject, n) != 0 && // not the same subject
            std::strcmp(must[t].verb, v) == 0 &&
            std::strcmp(must[t].object, o) == 0) {
            std::strcat(must[t].subject, " or ");
            std::strcat(must[t].subject, n);
            i = find_may(n, v, o);
            if (i != -1) {
                may[i].active = 0; // remove from may_have list
            }
        }
    }
    for (t = 0; t < must_pos; t++) {
        if (std::strcmp(must[t].subject, n) == 0 &&
            std::strcmp(must[t].verb, v) == 0 &&
            std::strcmp(must[t].object, o) != 0) { // not the same object
            std::strcat(must[t].object, " or ");
            std::strcat(must[t].object, o);
            i = find_may(n, v, o);
            if (i != -1) {
                may[i].active = 0; // remove from may_have list
            }
        }
    }
    return;
}
/* gener.cpp ---------------------------------------------------*/
