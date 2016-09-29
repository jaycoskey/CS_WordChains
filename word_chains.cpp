/* 
 * Run the body of the program.  Called by main() after parsing of args.
 */

#include "word_chains.hpp"

using std::cerr;
using std::cout;
using std::endl;

namespace word_chains {

WordChains::WordChains(WordChainArguments arguments) {
    this->arguments = arguments;        
}

void WordChains::start() {
    cout << "INFO: Reading words from " << arguments.argCacheWordsFile << endl;
    vector<string> words = Util::readWords(arguments.argCacheWordsFile);

    if (!Util::doesDirectoryExist(arguments.argLinksDir)) {
        cerr << "Error: Directory " << arguments.argLinksDir << " does not exist" << endl;
        exit(1);
    }
    if (arguments.primaryArgument == WCPA_Cache) {
        WordLinkWriter writer(words, arguments.argCacheWordsFile, arguments.argLinksDir);
        writer.writeLinks();
    } else if (arguments.primaryArgument == WCPA_Search) {
        cout
                << "Search Settings: "
                << "--links=" << arguments.argLinksDir
                << ", --commands=" << arguments.argSearchCommandsFile
                << ", --log=" << arguments.argSearchLogFile
                << endl;
        // Graph g = getTransformGraph(words, argLinksDir);
        // runSearchCommands(g, argSearchCommandsFile, argSearchLogFile);
    }
}

void WordChains::usage() {
    string usageMsg = "Usage:\n"
            "    wordChains <cache_options>\n"
            "    wordChains <search_options>\n"
            "  Cache Options: --cache --words WORDFILE --links LINKDIR]\n"
            "                (--cache must precede the other options)\n"
            "    WORDFILE is the file that contains the list of input words.\n"
            "    LINKDIR is the directory where the list of linked pairs of words are to be stored.\n"
            "        types of pairs are words related by (single-letter) mutation, swaps, or insertions/deletions.\n"
            "  Search Options: --search --links LINKDIR --commands COMMANDFILE --log LOGFILE\n"
            "                 (--search must precede the other options)\n"
            "    LINKDIR is the same directory mentioned above.\n"
            "    COMMANDFILE is a file with search commands.  Syntax TBD.\n"
            "    LOGFILE is the file where the results of the search commands are logged."
            ;
    cerr << usageMsg;
}

}
