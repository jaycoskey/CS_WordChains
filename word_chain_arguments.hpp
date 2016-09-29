/* 
 * struct containing command-line arguments
 */

#include "word_chain_primary_argument.hpp"

#ifndef WORD_CHAIN_ARGUMENTS_HPP
#define WORD_CHAIN_ARGUMENTS_HPP

#include <string>

using std::string;
      
namespace word_chains {

struct WordChainArguments {
    WordChainPrimaryArgument primaryArgument = WCPA_None;
    string argCacheWordsFile = "/usr/share/dict/linux.words";
    string argLinksDir = "./wordLinks";
    string argSearchCommandsFile = "./commands.txt";
    string argSearchLogFile = "./wordChainsOutput.txt";
};

}

#endif /* WORD_CHAIN_ARGUMENTS_HPP */

