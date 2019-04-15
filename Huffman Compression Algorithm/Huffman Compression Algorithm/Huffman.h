#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue> 
#include <unordered_map>
#include <unordered_set>

using namespace std; 

struct Node {
	char Ch;
	int Freq;
	Node* Left;
	Node* Right;
	Node(char ch, int freq, Node* left, Node* right) {
		Ch = ch;
		Freq = freq;
		Left = left;
		Right = right;
	}
};

struct Compare {
	bool operator()(Node* Left, Node* Right) {
		return Left->Freq > Right->Freq;
	}
};

Node* CreateNode(char ch, int freq, Node* left, Node* right) {
	Node* NewNode = new Node(ch, freq, left, right);
	return NewNode;
}

void Encoding(Node* Root, string Str, unordered_map<char, string> & HuffmanCode) {
	if (Root == nullptr) {
		return;
	}

	if (!Root->Left && !Root->Right) {
		HuffmanCode[Root->Ch] = Str;
	}
	Encoding(Root->Left, Str + '0', HuffmanCode);
	Encoding(Root->Right, Str + '1', HuffmanCode);
}

void Decoding(Node* Root, int& index, string Str) {
	if (Root == nullptr) {
		return;
	}

	if (!Root->Left && !Root->Right) {
		cout << Root->Ch;
		return;
	}

	index++;

	if (Str[index] == '0') {
		Decoding(Root->Left, index, Str);
	}
	else {
		Decoding(Root->Right, index, Str);
	}
}


void BuildHuffmanTree(string Text) {
	unordered_map<char, int> FreqOfChars;
	for (char ch : Text) {
		FreqOfChars[ch]++;
	}

	priority_queue<Node*, vector<Node*>, Compare> HuffmanTree;
	for (auto pair : FreqOfChars) {
		HuffmanTree.push(CreateNode(pair.first, pair.second, nullptr, nullptr));
	}

	while (HuffmanTree.size() != 1) {
		Node* Left = HuffmanTree.top();
		HuffmanTree.pop();

		Node* Right = HuffmanTree.top();
		HuffmanTree.pop();

		int SUM = Left->Freq + Right->Freq;
		HuffmanTree.push(CreateNode('\0', SUM, Left, Right));
	}

	Node* Root = HuffmanTree.top();
	unordered_map<char, string> HuffmanCodes;
	Encoding(Root, "", HuffmanCodes);

	cout << "Huffman Codes are : " << endl << endl;
	for (auto Pair : HuffmanCodes) {
		cout << "\t" << Pair.first << " " << Pair.second << endl;
	}
	cout << endl;
	cout << "The Original Text : " << endl << endl;
	cout << Text << endl;


	string Str = "";
	for (char Ch : Text) {
		Str += HuffmanCodes[Ch];
	}

	cout << "Encoded Text is : " << Str << endl;

	int Index = -1;
	cout << "Decoded Text is : ";
	while (Index < int(Str.size()) - 2) {
		Decoding(Root, Index, Str);
	}
	cout << endl << endl;
}
