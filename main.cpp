#include <iostream>
#include <string>
#include <utility>

#include "list.h"
#include "asciimationFunctions.h"
//#include "SLLwT.h"
#include "arrayPairList.h"

using namespace std;

int main() {

  // Initial code to read input from cin.
  // You shouldn't need to modify this portion of code
  cout << "Welcome to the ASCIIMATION player." << endl;
  string animationFileName; // name of asciimation file
  cout << "animation file: ";
  cin >> animationFileName;

  string yesIn = "No";
  cout << "type \"yes\" to play movie in reverse: ";
  cin >> yesIn;

  bool reverse = false; // true iff movie should be played in
  // reverse
  if (yesIn == "yes") {
    reverse = true;
  }

  ArrayPairList* theMovie = loadMovie(animationFileName);

  // TODO: write your program here
  if (reverse == true) {
      playMovieReverse(theMovie);
  } else {
      playMovie(theMovie);
  }

  return 0;
}
