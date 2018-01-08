# FlajoletMartin
Implements the Flajolet-Martin algorithm for approximately counting unique items in a data stream,
<br>&bull; Flajolet and Martin, _Probabilistic Counting Algorithms for Data Base Applications_,
Journal of Computer and System Sciences **31**, 182-209 (1985).

#### Required libraries
Boost
<br>http://www.boost.org

FarmHash
<br>https://github.com/google/farmhash

#### Other files (for tests)
main.cpp
<br>Test main that approximately counts the number of unique words in a specified text file.

constitution-words-only.txt
<br>Text of the United States Constitution, with punctuation removed. This contains 925 unique words.

declaration-words-only.txt
<br>Text of the Declaration of Independence, with punctuation removed. This contains 585 unique words.
