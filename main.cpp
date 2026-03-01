/**
* Title: Hash Tables
* Author: Aysegul & Yildiz
* ID: 22002591
* Section: 1
* Homework: 4
* Description: main method
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "HashTable.h"
#include"KmerNode.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 3){
        cerr<<"usage: "<<argv[0]<<"<k> <fileName>"<<endl;
        return 1;
    }

     string fileName = argv[2];
    int k = atoi(argv[1]);
    int size_quadratic = 71;
    int size_chain = 7;
    HashTable hash_quadratic(size_quadratic);
    hash_quadratic.fillHashTable_quadratic(fileName, k);
    cout<<"Kmer Nodes in the hash table (quadratic probing used):";
    hash_quadratic.printAll_quadratic();

    cout<<endl;
    string search_str = "haa";
    cout<<"Searching for the string '"<<search_str<<"'..."<<endl;

    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;
    startTime = std::chrono::system_clock::now();

    KmerNode* found_quadratic = hash_quadratic.findKmer_quadratic(search_str);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    if(found_quadratic == nullptr)
        cout<<"The hash table does not contain the string '"<<search_str<<"'."<<endl;
    else{
        cout<<"The string was found in the hash table!"<<endl;
        cout<<"Kmer node: ";
        cout<<found_quadratic->kmer<<" ";
        found_quadratic->printPos();
        cout<<endl;
    }

    cout<< "Searching for the string '"<<search_str<<"' in the hash table with quadratic probing took "<<elapsedTime.count() << " milliseconds."<<endl;
    cout<<endl;

    search_str = "xxx";
    cout<<"Searching for the string '"<<search_str<<"'..."<<endl;


    startTime = std::chrono::system_clock::now();

    KmerNode* notFound_quadratic = hash_quadratic.findKmer_quadratic(search_str);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    if(notFound_quadratic == nullptr)
        cout<<"The hash table does not contain the string '"<<search_str<<"'."<<endl;
    else{
        cout<<"The node was found in the hash table!"<<endl;
        cout<<"Kmer node: ";
        cout<<notFound_quadratic->kmer<<" ";
        notFound_quadratic->printPos();
        cout<<endl;
    }

    cout<< "Searching for the string '"<<search_str<<"' in the hash table with quadratic probing took "<<elapsedTime.count() << " milliseconds."<<endl;
    cout<<endl;

    if(found_quadratic != nullptr){
        int range = 2;
        cout<<"The strings excerpted from the input text extending to the range "<<range<<" : "<<endl;
        hash_quadratic.go_to_positions(fileName,range, found_quadratic);
    }

    cout<<"--------------------------------------------------------------------------------"<<endl;
    HashTable hash_chain(size_chain);
    hash_chain.fillHashTable_chain(fileName,k);
     cout<<"Kmer Nodes in the hash table (quadratic probing used):";
    hash_chain.printAll_chain();

    cout<<endl;
    search_str = "haa";
    cout<<"Searching for the string '"<<search_str<<"'..."<<endl;

    startTime = std::chrono::system_clock::now();

    KmerNode* found_chain = hash_chain.findKmer_chain(search_str);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    if(found_chain == nullptr)
        cout<<"The hash table does not contain the string '"<<search_str<<"'."<<endl;
    else{
        cout<<"The node was found in the hash table!"<<endl;
        cout<<"Kmer node: ";
        cout<<found_chain->kmer<<" ";
        found_chain->printPos();
        cout<<endl;
    }
     cout<< "Searching for the string '"<<search_str<<"' in the hash table with separate chaining took "<<elapsedTime.count() << " milliseconds."<<endl;
      cout<<endl;

    search_str = "xxx";
    cout<<"Searching for the string '"<<search_str<<"'..."<<endl;

    startTime = std::chrono::system_clock::now();

    KmerNode* notFound_chain = hash_chain.findKmer_chain(search_str);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    if(notFound_chain == nullptr)
        cout<<"The hash table does not contain the string '"<<search_str<<"'."<<endl;
    else{
        cout<<"The node was found in the hash table!"<<endl;
        cout<<"Kmer node: ";
        cout<<notFound_chain->kmer<<" ";
        notFound_chain->printPos();
        cout<<endl;
    }
       cout<< "Searching for the string '"<<search_str<<"' in the hash table with separate chaining took "<<elapsedTime.count() << " milliseconds."<<endl;
       cout<<endl;

    if(found_chain != nullptr){
        int range = 2;
        cout<<"The strings excerpted from the input text extending to the range "<<range<<" : "<<endl;
        hash_chain.go_to_positions(fileName,range, found_chain);
    }

}
