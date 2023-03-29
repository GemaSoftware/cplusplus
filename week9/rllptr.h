#ifndef WEEK9_NODE_UNIQ
#define WEEK9_NODE_UNIQ
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

struct List {
    struct Node {
        int data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;

    ~List() {
        while (head) {
            head = std::move(head->next);
        }
    };

    void push(int data){
        auto nn = std::make_unique<Node>();
        nn->data = data;
        nn->next = std::move(head);
        head = std::move(nn);
    };
};

#endif