# Kmer-Hash-Indexing-Comparision
This project was done for cs 202 course and it is a search tool that breaks down large text files into small, fixed length snippets called k-mers. It builds a custom hash table to index these snippets making it possible to find any specific sequence and all its locations in a massive file quickly.
Instead of just counting how many times a sequence appears, the program saves every single starting position (index) where that sequence is found in the text
when two different sequences fight for the same spot in the table the program uses two different strategies to solve it: building a linked list at that spot to hold multiple items and using a mathematical jump to find the next available open slot.
