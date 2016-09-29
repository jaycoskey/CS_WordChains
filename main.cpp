/* Parse command-line args, then call WordChain's start() method.
 * Two modes of operation:
 *   (1) Create a cache of word transform pairs (insertion/deletion/mutation/swap).
 *   (2) Run commands to search for various word chains, using the above cache.  
 */

#include "util.hpp"
#include "word_chain_arguments.hpp"
#include "word_chains.hpp"

using word_chains::Util;
using word_chains::WCPA_None;
using word_chains::WCPA_Cache;
using word_chains::WCPA_Search;
using word_chains::WordChainArguments;
using word_chains::WordChains;

// Get primary option (cache, or search), and run it.
// Command-line options:
//   --cache  => --words, --links
//   --search => --links, --commands, --log
// TODO: Implement building of (word transform) Graph
// TODO: Implement search feature
int main(int argc, char** argv) {
    WordChainArguments arguments = WordChainArguments();
    
    for (int i = 1; i < argc; i++) {
        if (arguments.primaryArgument == WCPA_None) {
            if (Util::streq(argv[i], "--cache")) {
                arguments.primaryArgument = WCPA_Cache;
                i++;
            } else if (Util::streq(argv[i], "--search")) {
                arguments.primaryArgument = WCPA_Search;
                i++;
            } else {
                WordChains::usage();
            }
        } else if (arguments.primaryArgument == WCPA_Cache) {
            if (Util::streq(argv[i], "--words")) {
                arguments.argCacheWordsFile = argv[i++];
            } else if (Util::streq(argv[i], "--links")) {
                arguments.argLinksDir = argv[i++];
            } else {
                WordChains::usage();
            }
        } else if (arguments.primaryArgument == WCPA_Search) {
            if (Util::streq(argv[i], "--links")) {
                arguments.argLinksDir = argv[i++];
            } else if (Util::streq(argv[i], "--commands")) {
                arguments.argSearchCommandsFile = argv[i++];
            } else if (Util::streq(argv[i], "--log")) {
                arguments.argSearchLogFile = argv[i++];
            } else {
                WordChains::usage();
            }
        } else {
            WordChains::usage();
        }
    }
    WordChains wordChains(arguments);
    wordChains.start();
    return 0;
}
