#include "insertion_sort.h"
#include "counters.h"
#include <iostream>
using namespace std;


void append(Node*& head, float value){
    Node* new_node = new Node{value, nullptr};
    c.assignments++;

    c.comparisons++;
    if (head == nullptr)
    {   
        
        head = new_node;
        c.assignments++;
        return;
    }
    
    Node* current = head;
    c.assignments++;
    while (current->next != nullptr)
    {
        c.comparisons++;
        current = current->next;
        c.assignments++;
    }
    current->next = new_node;
    c.assignments++;
}

void print_list(Node* head){
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void insertion_sort(Node*& head){
    c.comparisons++;
    if (head == nullptr or head->next == nullptr){
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;
    c.assignments++;

    while (current) {
        c.comparisons++;
        Node* original_next = current->next;
        c.assignments++;
        // we will change current->next, so we need to store original next not to lose the rest of the list
        c.comparisons++;
        if (sorted == nullptr or current->value < sorted->value) {
            current->next = sorted;
            c.assignments++;
            sorted = current;
            c.assignments++;
        }   // insert at the beginning if sorted is empty or current value is smaller than the first sorted value
        else
        {
            Node* sorted_runner = sorted;
            c.assignments++;
            while (sorted_runner->next != nullptr and sorted_runner->next->value < current->value) {
                c.comparisons++;
                sorted_runner = sorted_runner->next;
                c.assignments++;
            }
            // find where sorted_runner->next->value is bigger or equal to current value, so we can insert current value between sorted_runner and sorted_runner->next

            current->next = sorted_runner->next;
            c.assignments++;
            sorted_runner->next = current;
            c.assignments++;
            // insert current between sorted_runner and sorted_runner->next
        }

        current = original_next;
        c.assignments++;

    }

    head = sorted;
    c.assignments++;
    // update head to point to the new sorted list
    
}