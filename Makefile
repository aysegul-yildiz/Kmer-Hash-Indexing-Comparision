# Author : Aysegul & Yildiz
# ID: 22002591
# Section : 1
# Homework : 4
# Description : makefile to create executable named hw4

hw4: main.cpp KmerNode.h KmerNode.cpp HashTable.h HashTable.cpp 
	g++ main.cpp KmerNode.cpp HashTable.cpp -o hw4

clean:
	rm -f hw4
