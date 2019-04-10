#ifndef PRGASST05_ASCIIMATION_H
#define PRGASST05_ASCIIMATION_H

#include "list.h"
#include "SLLwT.h"
#include <string>
#include <utility>

using std::string;
using std::pair;

/**
 * This function loads an ASCIImation file, returning a list of frames.  Each
 * frame is represented as a pair between a duration (in units of 15fps) and the
 * frame's contents (as a string).
 * @param filename The name of the file to load.
 * @return A pointer to the list that contains the data.  Ownership of this
 *         list belongs to the caller; that is, the caller must eventually
 *         delete the returned list.
 *         The function should return nullptr is the filename is invalid.
 */
SLLwT* loadMovie(string filename);

/**
 * This function plays an ASCIImation from the provided list.
 * @param list The list of frame data to use when playing the video.
 */
void playMovie(SLLwT* list);

#endif //PRGASST05_ASCIIMATION_H
