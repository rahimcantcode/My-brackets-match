#ifndef DSStack_array_H
#define DSStack_array_H

template <typename ItemType>
class DSStack_array {
private:
    ItemType* elements;  // Array to store stack elements
    size_t elementCount; // Current number of elements in the stack
    int topIndex;        // Index of the top element in the stack

public:
    // Default constructor
    DSStack_array() {
        elements = new ItemType[500]; // Fixed initial size
        elementCount = 0;
        topIndex = -1;
    }

    // Copy constructor
    DSStack_array(const DSStack_array &other) {
        elementCount = other.elementCount;
        topIndex = other.topIndex;
        elements = new ItemType[500]; // Fixed size for simplicity
        for (size_t i = 0; i < elementCount; i++) {
            elements[i] = other.elements[i];
        }
    }

    // Assignment operator
    DSStack_array& operator=(const DSStack_array &other) {
        if (this != &other) {
            delete[] elements;
            elements = new ItemType[500]; // Fixed size for simplicity
            elementCount = other.elementCount;
            topIndex = other.topIndex;
            for (size_t i = 0; i < elementCount; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Destructor
    ~DSStack_array() {
        delete[] elements;
    }

    // Return the number of elements in the stack
    size_t getSize() const {
        return elementCount;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elementCount == 0;
    }

    // Clear the stack
    void clear() {
        delete[] elements;
        elements = new ItemType[500]; // Fixed initial size
        elementCount = 0;
        topIndex = -1;
    }

    // Find an element, returning its position or -1 if not found
    int find(const ItemType &toFind) const {
        for (size_t i = 0; i < elementCount; i++) {
            if (elements[i] == toFind) {
                return i;
            }
        }
        return -1;
    }

    // Push an element onto the stack
    void push(const ItemType &toPush) {
        elements[++topIndex] = toPush;
        elementCount++;
    }

    // Pop the top element from the stack
    ItemType pop() {
        if (isEmpty())
            throw std::runtime_error("Stack is empty");
        elementCount--;
        return elements[topIndex--];
    }

    // Peek at the top element of the stack
    ItemType peek() const {
        if (isEmpty())
            throw std::runtime_error("Stack is empty");
        return elements[topIndex];
    }
};

#endif // DSStack_array_H
