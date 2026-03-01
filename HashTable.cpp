/**
* Title: Hash Tables
* Author: Aysegul & Yildiz
* ID: 22002591
* Section: 1
* Homework: 4
* Description: Hash table class
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "HashTable.h"
#include "KmerNode.h"

using namespace std;

HashTable::HashTable(int tSize){
    tableSize = tSize;
   table = vector <KmerNode*>(tableSize,nullptr);
}

HashTable::~HashTable(){
    for (int i = 0; i < tableSize; ++i) {
        delete table[i];
    }

}

void HashTable::addKmer_chain(string kmer, int position){
    int hashVal = hash(kmer);

    KmerNode* current = table[hashVal];

    while(current != nullptr){
        if(current->kmer == kmer){
            current->addPosition(position);
            return;
        }
        current = current->next;
    }

    KmerNode* newNode = new KmerNode(kmer, position, nullptr);

    if (table[hashVal] == nullptr) {
        table[hashVal] = newNode;
    } else {
        current = table[hashVal];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }


}

void HashTable::fillHashTable_chain(string filename, int k){
    fstream file;
    string fileText = "";
    file.open(filename, ios::in);
    if(file.is_open()){
          string fileLine;
          while(getline(file, fileLine)){
            fileText = fileText + fileLine;
           }
            file.close();
    }

    transform(fileText.begin(), fileText.end(), fileText.begin(), ::tolower);
    int len = fileText.length() - fileText.length()%k;
    for(int i=0; i < len;i+=k){
    addKmer_chain(fileText.substr(i,k), i);
    }
}

KmerNode* HashTable::findKmer_chain (string kmer){
    int hashVal = hash(kmer);
    KmerNode* current = table[hashVal];

    while(current != nullptr){
        if(current->kmer == kmer)
            return current;
        current = current->next;
    }

    return nullptr;

}
void HashTable::addKmer_quadratic(string kmer, int position){
    int hashVal = hash(kmer);

    for (int i = 0; i < tableSize; i++) {
        int pos = (hashVal + i * i) % tableSize; // Calculate position using quadratic probing

        if (table[pos] == nullptr) {
            // Found an empty slot, insert new kmer here
            table[pos] = new KmerNode(kmer, position, nullptr);
            return;
        } else if (table[pos]->kmer == kmer) {
            // Found the kmer, add the position to this node
            table[pos]->addPosition(position);
            return;
        }
    }
}
void HashTable::fillHashTable_quadratic(string filename, int k){
   fstream file;
        string fileText = "";
        file.open(filename, ios::in);
        if(file.is_open()){
            string fileLine;
            while(getline(file, fileLine)){
                fileText = fileText + fileLine;
            }
            file.close();
        }

        transform(fileText.begin(), fileText.end(), fileText.begin(), ::tolower);
        int len = fileText.length() - fileText.length()%k;
        for(int i=0; i < len;i+=k){
            addKmer_quadratic(fileText.substr(i,k), i);
        }
}
KmerNode* HashTable::findKmer_quadratic (string kmer){
    int hashVal = hash(kmer);
    for(int i = 0; i < tableSize; i++){
        if(table[hashVal] == nullptr)
            return nullptr;
        else if((table[hashVal] != nullptr) && (table[hashVal]->kmer == kmer))
            return table[hashVal];
        else
            hashVal = (hashVal + (i*i)) % tableSize;
    }
    return nullptr;
}
void HashTable::printAll_quadratic(){
    cout<<endl;
    for(int i = 0; i< tableSize; i++){
            if(table[i] != nullptr){
                    cout<<"("<<i<<"th line of the table) = "<<table[i]->kmer<<" ";
                    table[i]->printPos();
                    cout<<endl;

            }
    }
}

void HashTable::printAll_chain(){
    cout<<endl;
    for(int i = 0; i< tableSize; i++){
            if(table[i] != nullptr){
                    cout<<"("<<i<<"th line of the table) = "<<table[i]->kmer<<" ";
                    table[i]->printPos();
                    KmerNode* nextNode = table[i]->next;
                    while(nextNode != nullptr){
                         cout<<"--->"<<nextNode->kmer<<" ";
                         nextNode->printPos();
                        nextNode = nextNode->next;
                    }
                    cout<<endl;
            }

    }

}
void HashTable::go_to_positions(string inputFileName, int range, KmerNode *found){
    int k = found->kmer.length();

    fstream file;
    string fileText = "";
    file.open(inputFileName, ios::in);
    if(file.is_open()){
        string fileLine;
        while(getline(file, fileLine)){
        fileText = fileText + fileLine;
        }
        file.close();
    }
    int endPos = k + range;
    for(int i = 0; i < found->positions.size(); i++){
         int startingPos = found->positions[i];
        string posToRange = fileText.substr(startingPos,endPos);
        cout<<posToRange<<" (generated from position "<<startingPos<<" )"<<endl;
    }


}
int HashTable::hash(string kmer){
    int ascii = 0;
    for(int i = 0; i < kmer.length(); i++){
        ascii += int(kmer[i]);
    }
    return (ascii % tableSize);
}

bool HashTable::isFull(){
    bool full = true;
    for(int i = 0; i < tableSize; i++){
        if(table[i] == nullptr)
            full = false;
    }
    return full;
}
