//
// Created by olehon on 3/1/20.
//

#ifndef SPELLER_VECTORCHECKER_H
#define SPELLER_VECTORCHECKER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

#include "Checker.h"

class VectorChecker : public Checker {
    std::vector<std::string> words;
public:
    explicit VectorChecker(const std::string& name) : Checker(name) {}
    ~VectorChecker() override = default;
    void add(const std::string& token) override ;
    bool check(const std::string& token) override ;

};


#endif //SPELLER_VECTORCHECKER_H
