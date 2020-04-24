//
// Created by olehon on 3/2/20.
//

#include "Checker.h"

Checker::Checker(const std::string& name) : _name(name) {
    output_filename = "../output/" + _name + "_wrong_words.txt";
}

void Checker::parse_dictionary(const std::string& filename) {
    auto start = std::chrono::steady_clock::now();
    std::ifstream dictionary(filename);
    std::string token;
    if(dictionary.is_open()){
        while (getline(dictionary, token)){
            add(token);
        }
        dictionary.close();
    }
    else {
        std::cout << "Dictionary is NOT open!" << std::endl;
    }
    auto end = std::chrono::steady_clock::now();
    duration_dictionary = end - start;
}

int Checker::getCountAll() const{
    return count_all;
}
int Checker::getCountWrong() const{
    return count_wrong;
}

void Checker::parse(std::ifstream& input, std::ofstream& wrong_words){
    std::string token;
    while (input >> token) {
        prepare_token(token);
        if (!token.empty()) {
            auto start = std::chrono::steady_clock::now();
            if (!check(token)) {
                count_wrong++;
                wrong_words << token << std::endl;
            }
            count_all++;
            auto end = std::chrono::steady_clock::now();
            duration_check += end - start;
        }
    }
}

float Checker::getDurationCheck() const {
    return duration_check.count();
}

float Checker::getDurationDictionary() const {
    return duration_dictionary.count();
}

void Checker::summary() const {
    std::cout << std::fixed << std::setprecision(0);
    std::cout << _name << ':' <<  '\n'
              << "Dictionary loading time: " << getDurationDictionary() << " milliseconds" << '\n'
              << "Total time for checking all texts: " << getDurationCheck() << " milliseconds" <<'\n'
              << "Checked words: " << getCountAll() << '\n'
              << "Wrong words: " << getCountWrong() << std::endl;
    std::cout << '\n';
}

void Checker::prepare_token(std::string &token) {
    if(!isalpha(token.front())){
        token.erase(begin(token));
    }
    else if(!isalpha(token.back())){
        token.erase(end(token) - 1);
    }
    token.erase(std::remove_if(begin(token), end(token), [] (const char& ch) {
        return !(isalpha(ch) || ch == '\'' || ch == '\n');}), end(token));
    std::for_each(token.begin(), token.end(), [](char & c){c = ::tolower(c);});
}

std::string Checker::getOutputFilename() const {
    return output_filename;
}


