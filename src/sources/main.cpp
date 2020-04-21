#include <memory>

#include "HashMapChecker.h"
#include "VectorChecker.h"
#include "HashTable.h"
#include "AVL.h"

void run_analyse(std::shared_ptr<Checker>& structure, std::vector<std::string>& texts){
    std::ofstream wrong_words(structure->getOutputFilename());
    structure->parse_dictionary("../dictionary.txt");
    for(std::string& filename: texts){
        std::ifstream input(filename);
        if(input.is_open()){
            structure->parse(input, wrong_words);
        } else {
            std::cout << "File " << filename << "doesn't open!" << std::endl;
        }
    }
    structure->summary();
}

int main() {

    std::vector<std::string> texts = {"../texts/alice.txt",
                           "../texts/dracula.txt",
                           "../texts/holmes.txt",
                           "../texts/sherlock.txt",
                           "../texts/tolstoy.txt"};

    std::vector<std::shared_ptr<Checker>> structures = {
            std::make_shared<VectorChecker>("Vector"),
            std::make_shared<AVL>("Tree"),
            std::make_shared<HashMapChecker>("HashMap"),
            std::make_shared<HashTable>(100000, "HashTable")
    };

    for(auto& item: structures){
        run_analyse(item, texts);
    }

    return 0;
}
