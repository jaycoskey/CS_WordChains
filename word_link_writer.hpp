/* 
 * Header for caching of pairs of words linked by a transform (insertion/deletion/mutation/swap). 
 */

#ifndef WORD_LINK_WRITER_HPP
#define WORD_LINK_WRITER_HPP

#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "util.hpp"

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

namespace word_chains {

class WordLinkWriter {
public:
    WordLinkWriter(vector<string> words, string argCacheWordsFile, string argLinksDir);
    map<int, vector<string>> getWordsByLen(vector<string> words);
    void writeLinks();
    
private:
    void log(string filename, string msg);
    void logDeletions(string outputDir, map<int, vector<string>> wordsByLen);
    void logMutationsAndSwaps(string outputDir, map<int, vector<string>> wordsByLen);

    string argCacheWordsFile;
    string argLinksDir;
    vector<string> words;
    
    const string BASENAME_DELETIONS = "deletions_";
    const string BASENAME_INSERTIONS = "insertions_";
    const string BASENAME_MUTATIONS = "mutations_";
    const string BASENAME_SWAPS = "swaps_";

    const string CODE_DELETION = "D";
    const string CODE_INSERTION = "I";
    const string CODE_MUTATION = "M";
    const string CODE_SWAP = "S";
};

}

#endif /* WORD_LINK_WRITER_HPP */
