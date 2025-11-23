#pragma once

struct Node
{
    float value;
    Node* next;
};

void append(Node*& head, float value);
void print_list(Node* head);
void insertion_sort(Node*& head);
