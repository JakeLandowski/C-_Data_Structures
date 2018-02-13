/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #5, 2/13/18
 * 
 *  Utilities.h
 * 
 *  This file contains a library of useful utility functions
 *  to be used in c++ assignments.
 */

#ifndef H_Utilities_H
#define H_Utilities_H

#include <string>
#include <vector>

namespace Utilities
{
    /**
     *  Java-like split function. Takes a string, and a delimiter,
     *  then returns a vector with those string chunks. Third 
     *  optional parameter to specify initial vector capacity
     *  if you want to estimate the size you'll need for efficiency.
    */
    std::vector<std::string> split(const std::string &splitting, 
                                   const std::string &delimiter,
                                   int estimatedCapacity = 10);
    bool isNumeric(const std::string &str);
};

#endif