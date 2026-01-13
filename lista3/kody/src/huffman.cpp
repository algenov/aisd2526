#include "../include/huffman.hpp"

using namespace std;



// free memory (recursive)
void delete_huffman_tree(HuffmanTreeNode* node) {
    if (node == nullptr) return;
    delete_huffman_tree(node->left_child);
    delete_huffman_tree(node->right_child);
    delete node;
}

// build codes by going from root to leaves
// left edge = '0', right edge = '1'
void build_huffman_codes_from_root(
    HuffmanTreeNode* current_node,
    string current_code,
    vector<char>& output_symbols,
    vector<string>& output_codes,
    Counters& cnt
) {
    cnt.cmp++;
    if (current_node == nullptr) return;

    // leaf we found a symbol, current_code is its Huffman code
    cnt.cmp++;
    if (current_node->is_leaf()) {
        // special only one symbol in input  empty code use 0
        cnt.cmp++;
        if (current_code.size() == 0) {
            current_code = "0";
            cnt.assign++;
        }

        output_symbols.push_back(current_node->symbol);
        output_codes.push_back(current_code);
        return;
    }

    build_huffman_codes_from_root(
        current_node->left_child,
        current_code + "0",
        output_symbols,
        output_codes,
        cnt
    );

    build_huffman_codes_from_root(
        current_node->right_child,
        current_code + "1",
        output_symbols,
        output_codes,
        cnt
    );
}

// build binary Huffman tree and produce codes
// input_symbols[i] has frequency input_frequencies[i]
void build_binary_huffman_codes(
    const vector<char>& input_symbols,
    const vector<long long>& input_frequencies,
    vector<char>& output_symbols,
    vector<string>& output_codes,
    Counters& cnt
) {
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, CompareNodesByFrequency> min_frequency_queue;

    int number_of_symbols = (int)input_symbols.size();
    cnt.assign++;

    // put all leaves into the queue
    for (int i = 0; i < number_of_symbols; i++) {
        cnt.cmp++;
        if (input_frequencies[i] > 0) {
            HuffmanTreeNode* new_leaf = new HuffmanTreeNode(input_symbols[i], input_frequencies[i]);
            cnt.assign++;
            min_frequency_queue.push(new_leaf);
        }
    }

    cnt.cmp++;
    if (min_frequency_queue.empty()) {
        // no symbols then no codes
        output_symbols.clear();
        output_codes.clear();
        return;
    }

    //  take two smallest, merge, push back
    while (min_frequency_queue.size() > 1) {
        HuffmanTreeNode* smallest_node = min_frequency_queue.top();
        min_frequency_queue.pop();
        cnt.assign++;

        HuffmanTreeNode* second_smallest_node = min_frequency_queue.top();
        min_frequency_queue.pop();
        cnt.assign++;

        HuffmanTreeNode* new_merged_node = new HuffmanTreeNode(smallest_node, second_smallest_node);
        cnt.assign++;
        min_frequency_queue.push(new_merged_node);
    }

    // final node is the root of the Huffman tree
    HuffmanTreeNode* huffman_tree_root = min_frequency_queue.top();
    cnt.assign++;

    // build codes
    output_symbols.clear();
    output_codes.clear();
    build_huffman_codes_from_root(huffman_tree_root, "", output_symbols, output_codes, cnt);

    // cleanup
    delete_huffman_tree(huffman_tree_root);
}




// free memory
void delete_ternary_huffman_tree(TernaryHuffmanTreeNode* node) {
    if (node == nullptr) return;
    delete_ternary_huffman_tree(node->child_0);
    delete_ternary_huffman_tree(node->child_1);
    delete_ternary_huffman_tree(node->child_2);
    delete node;
}

// build codes from root in 0,1,2
void build_ternary_huffman_codes_from_root(
    TernaryHuffmanTreeNode* current_node,
    string current_code,
    vector<char>& output_symbols,
    vector<string>& output_codes,
    Counters& cnt
) {
    cnt.cmp++;
    if (current_node == nullptr) return;

    if (current_node->is_leaf()) {
    // ignore dummy leaf added for ternary balancing
    cnt.cmp++;
    if (current_node->symbol == 0 && current_node->frequency == 0) {
        return;
    }

    // special: only one symbol in input
    cnt.cmp++;
    if (current_code.size() == 0) {
        current_code = "0";
        cnt.assign++;
    }

    output_symbols.push_back(current_node->symbol);
    output_codes.push_back(current_code);
    return;
}


    build_ternary_huffman_codes_from_root(
        current_node->child_0,
        current_code + "0",
        output_symbols,
        output_codes,
        cnt
    );

    build_ternary_huffman_codes_from_root(
        current_node->child_1,
        current_code + "1",
        output_symbols,
        output_codes,
        cnt
    );

    build_ternary_huffman_codes_from_root(
        current_node->child_2,
        current_code + "2",
        output_symbols,
        output_codes,
        cnt
    );
}

// main
void build_ternary_huffman_codes(
    const vector<char>& input_symbols,
    const vector<long long>& input_frequencies,
    vector<char>& output_symbols,
    vector<string>& output_codes,
    Counters& cnt
) {
    priority_queue<
        TernaryHuffmanTreeNode*,
        vector<TernaryHuffmanTreeNode*>,
        CompareTernaryNodesByFrequency
    > min_frequency_queue;  // create queue with our comparator

    int number_of_symbols = (int)input_symbols.size();
    cnt.assign++;

    // put all leaves into the queue
    for (int i = 0; i < number_of_symbols; i++) {
        cnt.cmp++;
        if (input_frequencies[i] > 0) {
            min_frequency_queue.push(
                new TernaryHuffmanTreeNode(input_symbols[i], input_frequencies[i])
            );
        }
    }

    cnt.cmp++;
    if (min_frequency_queue.empty()) {  // case no symbols
        output_symbols.clear();
        output_codes.clear();
        return;
    }

    // we need to have 2k+1 nodes in the queue
    while ((min_frequency_queue.size() - 1) % 2 != 0) {
        min_frequency_queue.push(
            new TernaryHuffmanTreeNode(0, 0)
        );
    }

    // glueing three smallest at once
    while (min_frequency_queue.size() > 1) {
        TernaryHuffmanTreeNode* a = min_frequency_queue.top();
        min_frequency_queue.pop();
        cnt.assign++;

        TernaryHuffmanTreeNode* b = min_frequency_queue.top();
        min_frequency_queue.pop();
        cnt.assign++;

        TernaryHuffmanTreeNode* c = min_frequency_queue.top();
        min_frequency_queue.pop();
        cnt.assign++;

        TernaryHuffmanTreeNode* merged_node =
            new TernaryHuffmanTreeNode(a, b, c);
        cnt.assign++;

        min_frequency_queue.push(merged_node);
    }

    TernaryHuffmanTreeNode* root = min_frequency_queue.top();
    cnt.assign++;

    output_symbols.clear();
    output_codes.clear();
    build_ternary_huffman_codes_from_root(
        root,
        "",
        output_symbols,
        output_codes,
        cnt
    );

    delete_ternary_huffman_tree(root);
}
