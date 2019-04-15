/*
Author : Abdallah Hemdan
    ___   __
*  |\  \|\  \
*  \ \  \_\  \
*   \ \   ___ \emdan
*    \ \  \\ \ \
*     \ \__\\ \_\
*      \|__| \|__|
*/

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue> 
#include <unordered_map>
#include <unordered_set>
#include "Huffman.h"
using namespace std;

int main() {
	string Text = "Huffman coding is a data compression algorithm."; 
	BuildHuffmanTree(Text); 
}
