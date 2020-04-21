//
// Created by olehon on 3/3/20.
//

#include "HashTable.h"

HashTable::HashTable(int s, const std::string& name) : Checker(name), size(s)
{
    hash_table.resize(size);
}

void HashTable::add(const std::string& token)
{
    int count = calculateHash(token);
    hash_table[count].push_front(token);
}

int HashTable::calculateHash(const std::string& token){
    int hash = 0;
    for(char i : token){
        hash = (hash * p + i) % size;
    }
    return hash;
}

bool HashTable::check(const std::string& token)
{
    int count = calculateHash(token);
    return !(std::find(begin(hash_table[count]), end(hash_table[count]), token) == end(hash_table[count]));
}
