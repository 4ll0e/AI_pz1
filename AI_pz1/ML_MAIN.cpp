/* ML_main.cpp
   Learning class description by using the
   "hit-and-near-miss" method
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "ml.h"

// Protocol file
std::ofstream prtcl;
attr may[MAX];      // may-have database
attr must[MAX];     // must-have database
int may_pos = 0;    // index into may-have database
int must_pos = 0;   // index into must-have database
char str[20];

void mkwnd(int, int, int, int, int, int) {
    // Placeholder function for window creation, replace or remove as needed
}

void learn() {
    // Implement learning function
}

void display() {
    // Implement display function
}

int main() {
    char s;

    mkwnd(1, 1, 80, 25, 14 /* YELLOW */, 1 /* BLUE */);
    std::cout << "\nEnter a name of your task, please\n";
    std::cin.getline(str, 20);
    strcat(str, ".ptc");

    prtcl.open(str, std::ios::out | std::ios::binary);
    if (!prtcl.is_open()) {
        std::cerr << "\nFile \"" << str << "\" isn't opened for writing";
        std::cin.get(); // replace getch()
        exit(1);
    }
    else {
        std::cout << "\nFile \"" << str << "\" is opened for protocol\n";
    }

    for (;;) {
        std::cout << "(L)earn, (D)isplay, or (Q)uit?  ";
        prtcl << "(L)earn, (D)isplay, or (Q)uit?";
        std::cin >> s;
        prtcl << " " << s;

        switch (tolower(s)) {
        case 'l': learn(); break;
        case 'd': display(); break;
        case 'q':
            prtcl.close();
            std::cout << "\nThat is all!\n";
            std::cin.get(); // replace getch()
            exit(0);
        }
        std::cout << "\n\n";
        prtcl << "\n\n";
    }
}
