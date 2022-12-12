#include <iostream>
#include <string.h>
#include "utils.h"

string generate_colored(string base, int color_id){
    string res = "";
    switch (color_id){
        case 0: // red color
            res = "\x1B[31m" + base + "\033[0m\t\t";
            break;
        case 1: // cyan
            res = "\x1B[36m" + base + "\033[0m\t\t";
            break;
        case 2:
            res = "\x1B[32m" + base + "\033[0m\t\t";
            break;
    }
    return res;
}