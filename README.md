# Speller

-------------------------------

## Description

The program reads one dictionary - a text file that contains words of the English language.
 1. Dictionary sorted alphabetically;
 2. There is only one word on each line;
 3. The dictionary may contain up to 200,000 words;
 4. In the dictionary there can only be Latin words, all letters are small,
    but the word may include the symbol `'`(apostrophe).

The program reads texts from the folder, which in turn checks for "correctness".   
For each text, a file is formed with a list of "wrong" words - words, that are not in the dictionary.  
Texts are real texts of books.  
Before checking, the program 
 - breaks the text into words;
 - translate everything into lower case;
 - discard punctuation marks and unknown characters - only small English letters and an apostrophe are considered valid.

Dictionary storage and verification is implemented on the basis of several data structures: 
 - the built-in type `<vector>`;
 - AVL-tree;
 - the built-in type `<unordered_set>`;
 - My own hash table.
 
 The target of the project - is to compare the performance of these options.  
 Thus, for each structure, I detect two parameters: 
 1. Dictionary loading time;
 2. Time for checking all files.

The program uses *polymorphism*.   
A basic abstract class `Checker` has been created from which other classes, such as:  
`VectorChecker`, `HashMapChecker`, `AVL`, `HashTable`, - are inherited and `override` methods `add()` and `check()`.

In the process of working on the project, I tried my best to follow the principle **DRY**.

The program does not accept anything from `stdin`. 
Dictionary placed in the repository's root directory, the texts are int folder `texts/`. "Wrong" words will be created in `output/` folder.

The program outputs to the console:

- the name of the data structure;
- dictionary loading time;
- total time for checking all texts;
- total number of checked words;
- total number of "wrong" words.

Time is everywhere in milliseconds.

Example:

> Vector:  
Dictionary loading time: 22 milliseconds  
Total time for checking all texts: 5558 milliseconds  
Checked words: 1996292  
Wrong words: 52549

The basis for the implementation of the project idea was a similar task [Speller CS50](https://cs50.harvard.edu/x/2020/psets/5/speller/).

## Tools

- CLion 2019.3
- cmake
- g++
- C++11