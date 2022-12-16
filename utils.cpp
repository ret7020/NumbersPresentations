#include <iostream>
#include <string.h>
#include "utils.h"

string generate_colored(string base, int color_id){
    bool FAILSAFE = true;
    if (FAILSAFE) return base;
    string res = "";
    switch (color_id){
        case 0: // red color
            res = "\x1B[31m" + base + "\033[0m\t\t";
            break;
        case 1: // cyan color
            res = "\x1B[36m" + base + "\033[0m\t\t";
            break;
        case 2: // green color
            res = "\x1B[32m" + base + "\033[0m\t\t";
            break;
    }
    return res;
}
