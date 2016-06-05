/******************************************************************************/

#include "FlajoletMartin.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <boost/tokenizer.hpp>

/******************************************************************************/

// read the data from a file
void readItems(const std::string& filename, const std::string& sep, std::vector<std::string>& items) {
  std::ifstream fin(filename.c_str());
  if (!fin) {
    std::cout << "File \"" << filename << "\" not found" << std::endl;
    return;
  }

  typedef boost::tokenizer<boost::char_separator<char> > Tokenizer;
  boost::char_separator<char> ch_sep(sep.c_str());
  std::string line;
  std::string item;

  while (getline(fin, line)) {
    // TODO: remove punctuation...

    // tokenize
    Tokenizer data(line, ch_sep);
    Tokenizer::iterator iter = data.begin();
    Tokenizer::iterator iend = data.end();

    for (iter = data.begin(); iter != iend; iter++) {
      items.push_back(*iter);
    }
  }

  fin.close();
}

/******************************************************************************/

int main(int argc, char **argv) {
  // TODO: command-line options
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 0;
  }

  // read the data
  std::vector<std::string> myItems;
  readItems(argv[1], " ", myItems);

  std::cout << "Read " << myItems.size() << " total strings, ";
  std::map<std::string, bool> myItemsMap;
  for (std::vector<std::string>::iterator iter = myItems.begin(); iter != myItems.end(); iter++) {
    myItemsMap[*iter] = true;
  }
  std::cout << myItemsMap.size() << " are unique." << std::endl;

  FlajoletMartin fm;
  std::cout << "Flajolet-Martin counts: " << std::endl;
  for (int m = 16; m <= 16384; m *= 2) {
    std::cout << "M = " << m << " -> approximate word count = " << fm.approximateCount(myItems, m) << std::endl;
  }

  return 0;
}

/******************************************************************************/
