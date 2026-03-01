/**
* Title: Hash Tables
* Author: Aysegul & Yildiz
* ID: 22002591
* Section: 1
* Homework: 4
* Description: Hash table header
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include "KmerNode.h"

using namespace std;
class HashTable{
public:
    HashTable(int tSize);
    ~HashTable();
    void addKmer_chain(string kmer, int position);
    void fillHashTable_chain(string filename, int k);
    KmerNode* findKmer_chain (string kmer);
    void addKmer_quadratic(string kmer, int position);
    void fillHashTable_quadratic(string filename, int k);
    KmerNode* findKmer_quadratic (string kmer);
    void printAll_quadratic();
    void printAll_chain();
    void go_to_positions(string inputFileName, int range, KmerNode *found);
    int hash(string kmer);
    bool isFull();
    int tableSize ;
    vector<KmerNode*> table;

};
#endif // HASHTABLE_H

