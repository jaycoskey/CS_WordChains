/* 
 * Utility functions (all static)
 */

#ifndef UTIL_HPP
#define UTIL_HPP

#include <cstring>

#include <sys/stat.h>
#include <sys/types.h>

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace word_chains {

struct Util {
    static bool doesDirectoryExist(string dirPath);
    static bool isAlphaAndLowercase(string s);

    static bool isDeletionOf(string s1, string s2);
    static bool isInsertionOf(string s1, string s2);
    static bool isMutationOf(string s1, string s2);
    static bool isSwapOf(string s1, string s2);

    static void log(string filename, string msg);
    static vector<string> readWords(string filename);
    static bool streq(char *s1, const char *s2);
};

}

#endif /* UTIL_HPP */
