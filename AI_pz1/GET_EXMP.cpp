/* get_exmp.cpp
   Input description
*/
#include <iostream>
#include <cstring>
#include "ml.h"

int get_example(char* n, char* v, char* o) {
    extern attr may[], must[];
    extern int may_pos, must_pos;
    extern FILE* prtcl;

    std::cout << "\n subject: ";
    std::cin.getline(n, 80);
    if (!*n) {
        std::strcpy(n, "<NL>");
    }
    fprintf(prtcl, "\n subject: %s", n);
    if (n[0] == '<') return 0;

    std::cout << "    verb: ";
    std::cin.getline(v, 80);
    std::cout << "  object: ";
    std::cin.getline(o, 80);
    fprintf(prtcl, "\n    verb: %s\n  object: %s", v, o);

    return 1;
}
