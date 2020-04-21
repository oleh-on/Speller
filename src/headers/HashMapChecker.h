//
// Created by olehon on 3/1/20.
//

#ifndef SPELLER_HASHMAPCHECKER_H
#define SPELLER_HASHMAPCHECKER_H

#include <unordered_set>

#include "Checker.h"

class HashMapChecker : public Checker{
    std::unordered_set<std::string> words;
public:
    explicit HashMapChecker(const std::string& name) : Checker(name) {}
    ~HashMapChecker() override = default;
    void add(const std::string& token) override ;
    bool check(const std::string& token) override ;
};


#endif //SPELLER_HASHMAPCHECKER_H
