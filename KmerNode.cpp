/**
* Title: Hash Tables
* Author: Aysegul & Yildiz
* ID: 22002591
* Section: 1
* Homework: 4
* Description: KmerNode class
*/

#include <iostream>
#include <vector>
#include "KmerNode.h"

using namespace std;

KmerNode::KmerNode(){
    index = 0;
}

KmerNode::KmerNode(string k, int p, KmerNode* ptr){
    kmer = k;
    next = ptr;
    index = 0;
    addPosition(p);
}

void KmerNode::addPosition(int pos){
    positions.push_back(pos);
    index++;
}

void KmerNode::printPos(){
    cout<<"(";
    for(int i = 0; i < positions.size(); i++){
        if(i > 0)
            cout<<", ";
        cout<<positions[i];
    }
    cout<<")";
}
