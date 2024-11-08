/* display.cpp */
#include <iostream>
#include <cstdio>
#include "ml.h"

void display() {
    extern FILE* prtcl;
    extern attr may[], must[];
    extern int may_pos, must_pos;

    std::cout << "\n\nDisplay of description:\n\nMay have:";
    fputs("\n\nDisplay of description:\n", prtcl);
    fputs("-----------------------\nMay have:", prtcl);

    for (int t = 0; t < may_pos; t++) {
        if (may[t].active) {
            std::cout << "\n" << may[t].subject << " " << may[t].verb << " " << may[t].object;
            fprintf(prtcl, "\n%s %s %s", may[t].subject, may[t].verb, may[t].object);
        }
    }

    std::cout << "\n\nMust have:";
    fputs("\n\nMust have:", prtcl);

    for (int t = 0; t < must_pos; t++) {
        std::cout << "\n" << must[t].subject << " " << must[t].verb << " " << must[t].object;
        fprintf(prtcl, "\n%s %s %s", must[t].subject, must[t].verb, must[t].object);
    }
}
