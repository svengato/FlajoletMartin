CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT (FlajoletMartin)

SET(CMAKE_CXX_FLAGS_RELEASE "-O3")
SET(CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES (
  $ENV{FARMHASH_INCLUDES}
)

FIND_LIBRARY (
  FarmHash_lib
  farmhash
  $ENV{FARMHASH_LIBRARIES}
)

ADD_EXECUTABLE (
  FlajoletMartin
  FlajoletMartin.cpp
  main.cpp
)

TARGET_LINK_LIBRARIES (
  FlajoletMartin
  ${FarmHash_lib}
)
