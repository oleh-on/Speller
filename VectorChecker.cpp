//
// Created by olehon on 3/1/20.
//

#include "VectorChecker.h"

void VectorChecker::add(const std::string& token) {
    words.push_back(token);
}

bool VectorChecker::check(const std::string& token){
    return  std::binary_search(begin(words), end(words), token);
}



