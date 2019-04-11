#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <chrono>
#include <thread>
#include <sstream>

#include "asciimationFunctions.h"
#include "list.h"
//#include "SLLwT.h"
#include "arrayPairList.h"

using namespace std;

ArrayPairList* loadMovie(string filename) {
  ArrayPairList* theArray = new ArrayPairList();
  ifstream inFile;

  inFile.open(filename);
  if (!inFile.is_open()) {
      throw runtime_error("asciimationFunctions::loadMovie, not a valid filename");
  }
  while (!inFile.eof()) {
    string frameCountHolder;
    string asciiFrame;

    //getting the line that contains the frame count
    getline(inFile, frameCountHolder);
    istringstream ss(frameCountHolder);
    int frameCount;
    ss >> frameCount >> ws;

    //using a loop to grab the next 13 lines to store for the frame
    for (int i = 0; i < 13; i++) {
        string tempString;
        getline(inFile, tempString);

        asciiFrame += tempString;
        asciiFrame += "\n";
    }
    pair<int, string> thePair(frameCount, asciiFrame);
    theArray->insertAtTail(thePair);
    }
  return theArray;
}

void playMovie(ArrayPairList* list) {
  for (int i = 0; i < list->getSize(); i++) {
      pair<int,string> frame = list->at(i);

      cout << frame.second << endl;
      this_thread::sleep_for(chrono::microseconds(1000000/15*frame.first));
      cout << flush;
  }

  delete list;
}

void playMovieReverse(ArrayPairList* list) {
    //Making a new list that will be filled in reverse of the provided list
    ArrayPairList* reverseList = new ArrayPairList();

    for (int i = list->getSize() - 1; i >= 0; i--) {
        reverseList->insertAtTail(list->at(i));
    }

    delete list;
    playMovie(reverseList);
}
