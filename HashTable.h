//
// Created by olehon on 3/3/20.
//

#ifndef SPELLER_HASHTABLE_H
#define SPELLER_HASHTABLE_H

#include "Checker.h"
#include <vector>
#include <list>
#include <set>

class HashTable : public Checker {
    std::vector<std::list<std::string>> hash_table;
    const int size;
    const int p = 31; // constant to calculate hash
    int calculateHash(const std::string& token); // calculate hash from input string value

public:
    explicit HashTable(int s, const std::string& name);
    ~HashTable() override = default;
    void add(const std::string& word) override ;
    bool check(const std::string& word) override ;
};


#endif //SPELLER_HASHTABLE_H
