/**
* Title: Hash Tables
* Author: Aysegul & Yildiz
* ID: 22002591
* Section: 1
* Homework: 4
* Description: KmerNode class header
*/

#ifndef KMERNODE_H
#define KMERNODE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KmerNode{
public:
    KmerNode();
    KmerNode(string k, int p, KmerNode* ptr);
    void addPosition(int pos);
    void printPos();
    string kmer;
    vector <int> positions;
    KmerNode* next;
    int index;
};
#endif // KMERNODE_H
