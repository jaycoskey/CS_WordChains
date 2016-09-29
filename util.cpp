/* 
 * Utility functions (all static)
 */

#include "util.hpp"

namespace word_chains {

bool Util::doesDirectoryExist(string dirPath) {
    struct stat st;

    if (stat(dirPath.c_str(), &st) != 0) {
        return false;
    } else if (st.st_mode & S_IFDIR) {
        return true;
    } else {
        return false;
    }
}

bool Util::isAlphaAndLowercase(string s) {
    auto beg = std::begin(s);
    auto end = std::end(s);
    bool result = !std::all_of(
            beg, end,
            [](char c) {
                return isalpha(c) && islower(c); }
    );
    return result;
}

// Return true if s2 can be obtained by deleting a character from s1
bool Util::isDeletionOf(string s1, string s2) {
    if (s1.length() != s2.length() + 1) {
        return false;
    }
    int length2 = s2.length();
    int insertionCount = 0;
    for (int i = 0; i < length2; i++) {
        if (s1[i + insertionCount] != s2[i]) {
            if (insertionCount > 0) {
                return false;
            }
            if (s1[i + 1] == s2[i]) {
                insertionCount++;
            } else {
                return false;
            }
        }
    }
    return true;
}

// Return true if s2 can be obtained by inserting a character into s1
bool Util::isInsertionOf(string s1, string s2) {
    if (s1.length() != s2.length() - 1) {
        return false;
    }
    int length1 = s1.length();
    int deletionCount = 0;
    for (int i = 0; i < length1; i++) {
        if (s1[i] != s2[i + deletionCount]) {
            if (deletionCount > 0) {
                return false;
            }
            if (s1[i] == s2[i + 1]) {
                deletionCount++;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool Util::isMutationOf(string s1, string s2) {
    if (s2.length() != s1.length()) {
        return false;
    }
    int length = s1.length();
    int mutationCount = 0;
    for (int i = 0; i < length; i++) {
        if (s1[i] != s2[i]) {
            mutationCount++;
            if (mutationCount > 1) {
                return false;
            }
        }
    }
    return mutationCount == 1 ? true : false;
}

bool Util::isSwapOf(string s1, string s2) {
    if (s2.length() != s1.length()) {
        return false;
    }
    int length = s1.length();
    int swapCount = 0;
    for (int i = 0; i < length; i++) {
        if (s1[i] != s2[i]) {
            if (i == length - 1) {
                return false;
            }
            if (s1[i] == s2[i + 1] && s1[i + 1] == s2[i]) {
                swapCount++;
                if (swapCount > 1) {
                    return false;
                }
                i++;
            } else {
                return false;
            }
        }
    }
    return swapCount == 1 ? true : false;
}

void Util::log(string filename, string msg) {
    std::ofstream ofout(filename, std::ofstream::out | std::ofstream::app);
    ofout << msg << std::endl;
    ofout.close();
}

vector<string> Util::readWords(string filename) {
    vector<string> words;

    std::ifstream inputFile(filename);
    string str;
    while (std::getline(inputFile, str)) {
        if (isAlphaAndLowercase(str)) {
            continue;
        }
        words.push_back(str);
    }
    inputFile.close();

    return words;
}

bool Util::streq(char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}

}
