/* 
 * Cache (to files) pairs of words linked by a transform (insertion/deletion/mutation/swap). 
 */

#include "word_link_writer.hpp"

namespace word_chains {

WordLinkWriter::WordLinkWriter(
    vector<string> words,
    string argCacheWordsFile,
    string argLinksDir)
{
    this->words = words;
    this->argCacheWordsFile = argCacheWordsFile;
    this->argLinksDir = argLinksDir;
}

map<int, vector<string>> WordLinkWriter::getWordsByLen(vector<string> words) {
    map<int, vector < string>> wordsByLen;
    for (string word : words) {
        int len = word.length();
        if (wordsByLen.count(len) == 0) {
            vector<string>* pVec = new vector<string>();
            wordsByLen[len] = *pVec;
        }
        wordsByLen[len].push_back(word);
    }
    return wordsByLen;
}

void WordLinkWriter::log(string filename, string msg) {
    std::ofstream ofout(filename, std::ofstream::out | std::ofstream::app);
    ofout << msg << endl;
    ofout.close();
}

void WordLinkWriter::logDeletions(string outputDir, map<int, vector<string>> wordsByLen) {
    for (int wordLen = 1; wordLen < 30; wordLen++) {
        if (wordsByLen.count(wordLen) == 0) {
            continue;
        }
        cout << ".";
        std::stringstream wordLenStream;
        wordLenStream
                << std::setfill('0') << std::setw(2) << wordLen + 1
                << "_"
                << std::setfill('0') << std::setw(2) << wordLen;
        string wordLenStr = wordLenStream.str();
        string deletionsFilename = outputDir + "/" + BASENAME_DELETIONS + wordLenStr + ".txt";
        for (string w1 : wordsByLen[wordLen + 1]) {
            for (string w2 : wordsByLen[wordLen]) {
                if (Util::isDeletionOf(w1, w2)) {
                    // cout << "INFO: Logging deletion to " << deletionsFilename << endl;
                    log(deletionsFilename, CODE_DELETION + " " + w1 + " " + w2);
                }
            }
        }
    }
    cout << endl;
}

void WordLinkWriter::logMutationsAndSwaps(string outputDir, map<int, vector<string>> wordsByLen) {
    for (int wordLen = 1; wordLen < 30; wordLen++) {
        if (wordsByLen.count(wordLen) == 0) {
            continue;
        }
        cout << ".";
        std::stringstream wordLenStream;
        wordLenStream << std::setfill('0') << std::setw(2) << wordLen;
        string wordLenStr = wordLenStream.str();
        string mutationsFilename = outputDir + "/" + BASENAME_MUTATIONS + wordLenStr + ".txt";
        string swapsFilename = outputDir + "/" + BASENAME_SWAPS + wordLenStr + ".txt";
        for (int i = 0; i < wordsByLen[wordLen].size(); i++) {
            string w1 = wordsByLen[wordLen][i];
            for (int j = i + 1; j < wordsByLen[wordLen].size(); j++) {
                string w2 = wordsByLen[wordLen][j];
                if (Util::isMutationOf(w1, w2)) {
                    // cout << "INFO: Logging mutation to " << mutationsFilename << endl;
                    log(mutationsFilename, CODE_MUTATION + " " + w1 + " " + w2);
                }
                if (Util::isSwapOf(w1, w2)) {
                    // cout << "INFO: Logging swap to " << swapsFilename << endl;
                    log(swapsFilename, CODE_SWAP + " " + w1 + " " + w2);
                }
            }
        }
    }
    cout << endl;
}

void WordLinkWriter::writeLinks()
{
    cout << "Cache Settings: "
            << "--words=" << argCacheWordsFile
            << ", --links=" << argLinksDir
            << endl;
    cout << "INFO: Creating index of words by length" << endl;
    map<int, vector<string>> wordsByLen = getWordsByLen(words);
    cout << "INFO: Logging mutations and swaps" << endl;
    logMutationsAndSwaps(argLinksDir, wordsByLen);
    cout << "INFO: Logging deletions" << endl;
    logDeletions(argLinksDir, wordsByLen);
    // printWordVector(words);
    // printMapOfWordVectors(wordsByLen);
    // printWordTransformations(words);
}

}
