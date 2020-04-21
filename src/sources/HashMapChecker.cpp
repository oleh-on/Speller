//
// Created by olehon on 3/1/20.
//

#include "HashMapChecker.h"

void HashMapChecker::add(const std::string &token) {
    words.emplace(token);
}

bool HashMapChecker::check(const std::string& token) {
    return !(words.find(token) == words.end());
}
