#include <iostream>

class Node {
public:
    int data;
    Node* xorPtr;  // XOR of next and previous nodes

    Node(int value) : data(value), xorPtr(nullptr) {}
};

class XORLinkedList {
private:
    Node* head;

    Node* XOR(Node* a, Node* b) {
        return reinterpret_cast<Node*>
        (reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
    }

public:
    XORLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->xorPtr = XOR(nullptr, head);

        if (head != nullptr) {
            head->xorPtr = XOR(newNode, XOR(nullptr, head->xorPtr));
        }

        head = newNode;
    }

    void display() {
        Node* current = head;
        Node* prev = nullptr;
        Node* next;

        while (current != nullptr) {
            std::cout << current->data << " ";

            next = XOR(prev, current->xorPtr);

            prev = current;
            current = next;
        }

        std::cout << std::endl;
    }
};

int main() {
    XORLinkedList xorList;

    xorList.insert(1);
    xorList.insert(2);
    xorList.insert(3);
    xorList.insert(4);

    std::cout << "XOR Linked List: ";
    xorList.display();

    return 0;
}
