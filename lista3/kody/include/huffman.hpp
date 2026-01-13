#pragma once

#include <vector>
#include <queue>
#include <string>
#include <iostream>

#include "counters.hpp"

using namespace std;


// binary

// one node of the Huffman tree
struct HuffmanTreeNode {
    char symbol;                       // valid only for leaves
    long long frequency;               // how often it appears
    HuffmanTreeNode* left_child;
    HuffmanTreeNode* right_child;
    HuffmanTreeNode* parent;

    // leaf constructor
    HuffmanTreeNode(char given_symbol, long long given_frequency) {
        symbol = given_symbol;
        frequency = given_frequency;
        left_child = nullptr;
        right_child = nullptr;
        parent = nullptr;
    }

    // internal node constructor glue two nodes together
    HuffmanTreeNode(HuffmanTreeNode* left, HuffmanTreeNode* right) {
        symbol = 0; // not a real symbol
        frequency = left->frequency + right->frequency;

        left_child = left;
        right_child = right;
        parent = nullptr;

        // set parent
        left->parent = this;
        right->parent = this;
    }

    bool is_leaf() const {
        return left_child == nullptr && right_child == nullptr;
    }
};

// comparator for priority queue 
// if a has bigger frequency than b, then a goes down
struct CompareNodesByFrequency {
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b) {
        return a->frequency > b->frequency;
    }
};

void delete_huffman_tree(HuffmanTreeNode* node);

void build_huffman_codes_from_root(
    HuffmanTreeNode* current_node,
    string current_code,
    vector<char>& output_symbols,
    vector<string>& output_codes,
    Counters& cnt
);

void build_binary_huffman_codes(
    const vector<char>& input_symbols,
    const vector<long long>& input_frequencies,
    vector<char>& output_symbols,
    vector<string>& output_codes,
    Counters& cnt
);


// ternary 

//  one ternary Huffman node
struct TernaryHuffmanTreeNode {
    char symbol;                       // valid only for leaves
    long long frequency;               // frequency
    TernaryHuffmanTreeNode* child_0;
    TernaryHuffmanTreeNode* child_1;
    TernaryHuffmanTreeNode* child_2;
    TernaryHuffmanTreeNode* parent;

    // leaf constructor
    TernaryHuffmanTreeNode(char given_symbol, long long given_frequency) {
        symbol = given_symbol;
        frequency = given_frequency;
        child_0 = nullptr;
        child_1 = nullptr;
        child_2 = nullptr;
        parent = nullptr;
    }

    // glue nodes
    TernaryHuffmanTreeNode(
        TernaryHuffmanTreeNode* a,
        TernaryHuffmanTreeNode* b,
        TernaryHuffmanTreeNode* c
    ) {
        symbol = 0; // not a real symbol
        frequency = a->frequency + b->frequency + c->frequency;

        child_0 = a;
        child_1 = b;
        child_2 = c;
        parent = nullptr;

        a->parent = this;
        b->parent = this;
        c->parent = this;
    }

    bool is_leaf() const {
        return child_0 == nullptr && child_1 == nullptr && child_2 == nullptr;
    }
};

// ternary comparator
struct CompareTernaryNodesByFrequency {
    bool operator()(TernaryHuffmanTreeNode* a, TernaryHuffmanTreeNode* b) {
        return a->frequency > b->frequency;
    }
};

void delete_ternary_huffman_tree(TernaryHuffmanTreeNode* node);

void build_ternary_huffman_codes_from_root(
    TernaryHuffmanTreeNode* current_node,
    string current_code,
    vector<char>& output_symbols,
    vector<string>& output_codes,
    Counters& cnt
);

void build_ternary_huffman_codes(
    const vector<char>& input_symbols,
    const vector<long long>& input_frequencies,
    vector<char>& output_symbols,
    vector<string>& output_codes,
    Counters& cnt
);
