/* ml.h
   Learning class description by using the
   "hit-and-near-miss" method
*/

#ifndef ML_H
#define ML_H

#define MAX 100

struct attr {
    char subject[80];
    char verb[80];
    char object[80];
    bool active; // Changed from 'char' to 'bool' for clarity
};

#endif // ML_H
