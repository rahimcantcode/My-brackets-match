#ifndef DSList_H
#define DSList_H

// Template for a singly-linked list with stack-like behavior
template <typename ElementType>
class DSList {
private:

    struct Node {
        ElementType value; // Stores the element in the node
        Node *nextNode;   // Pointer to the next node in the list

        Node(const ElementType &val = ElementType{}, Node *nextPtr = nullptr)
            : value(val), nextNode(nextPtr) {}
    };

    Node *head; // Pointer to the first node in the list

public:
    DSList() : head(nullptr) {}

    // Copy constructor
    DSList(const DSList &other) : head(nullptr) {
        Node *current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->nextNode;
        }
    }

    // Assignment operator
    DSList &operator=(const DSList &rhs) {
        if (this != &rhs) {
            clear();
            Node *current = rhs.head;
            while (current != nullptr) {
                push_back(current->value);
                current = current->nextNode;
            }
        }
        return *this;
    }

    // Destructor
    ~DSList() {
        clear();
    }

    int size() const {
        Node *current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->nextNode;
        }
        return count;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop_front();
        }
    }

    int find(const ElementType &toFind) const {
        Node *current = head;
        int position = 0;
        while (current != nullptr) {
            if (current->value == toFind) {
                return position;
            }
            current = current->nextNode;
            position++;
        }
        return -1;
    }

    void push_front(const ElementType &value) {
        Node *newNode = new Node(value, head);
        head = newNode;
    }

    void push_back(const ElementType &value) {
        Node *newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->nextNode != nullptr) {
                current = current->nextNode;
            }
            current->nextNode = newNode;
        }
    }

    ElementType pop_front() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        Node *temp = head;
        ElementType frontValue = temp->value;
        head = head->nextNode;
        delete temp;
        return frontValue;
    }

    ElementType pop_back() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        if (head->nextNode == nullptr) {
            ElementType backValue = head->value;
            delete head;
            head = nullptr;
            return backValue;
        }
        Node *current = head;
        while (current->nextNode->nextNode != nullptr) {
            current = current->nextNode;
        }
        ElementType backValue = current->nextNode->value;
        delete current->nextNode;
        current->nextNode = nullptr;
        return backValue;
    }

    ElementType peek_front() const {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        return head->value;
    }

    ElementType peek_back() const {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        Node *current = head;
        while (current->nextNode != nullptr) {
            current = current->nextNode;
        }
        return current->value;
    }
};

#endif // DSList_H
