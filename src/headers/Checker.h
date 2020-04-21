//
// Created by olehon on 3/2/20.
//

#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>

class Checker {
public:
    explicit Checker(const std::string& name);
    virtual ~Checker() = default;
    virtual void add(const std::string& token) = 0;
    virtual bool check(const std::string& token) = 0;
    void parse(std::ifstream& input, std::ofstream& wrong_words);
    void parse_dictionary(const std::string& filename);
    std::string getOutputFilename() const;
    int getCountAll() const;
    int getCountWrong() const;
    float getDurationCheck() const ;
    float getDurationDictionary() const ;
    void summary() const;

private:
    int count_all = 0; // count of all analyzed words
    int count_wrong = 0; // count of words which dictionary doesn't include
    std::chrono::duration<float, std::milli> duration_check; // duration of analyzed all texts
    std::chrono::duration<float, std::milli> duration_dictionary; // duration of parsing dictionary
    void prepare_token(std::string& token);
    const std::string _name;
    std::string output_filename;
};


#endif //SPELLER_CHECKER_H
