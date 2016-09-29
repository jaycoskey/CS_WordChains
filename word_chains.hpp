/* 
 * Header for the body of the program.  Called by main() after parsing of args.
 */

#ifndef WORD_CHAINS_HPP
#define WORD_CHAINS_HPP

#include "word_chain_arguments.hpp"

#include <iostream>
#include <vector>

#include "util.hpp"
#include "word_link_writer.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

namespace word_chains {

class WordChains {
public:
    WordChains(WordChainArguments arguments);
    void start();
    static void usage();
private:
    WordChainArguments arguments;
};

}

#endif /* WORD_CHAINS_HPP */

