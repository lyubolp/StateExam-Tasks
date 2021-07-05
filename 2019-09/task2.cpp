#include <iostream>
#include <cstring>

class Edge {
public:
    Edge(Node* const next = nullptr, const unsigned value = 0, const char label = 0) {
        this->next = next;
        this->value = value;
        this->label = label;
    }

    Node* get_next() const {
        return this->next;
    }

    unsigned get_value() const {
        return this->value;
    }

    char get_label() const {
        return this->label;
    }
private:
    Node* next;
    unsigned value;
    char label;
};


class Node {
public:
    Node() {
        this->edges = nullptr;
        this->edges_length = 0;
    }


    Node(const Node& from) {
        this->copy_object(from);
    }

    Node& operator=(const Node& from) {
        if(this != &from) {
            delete[] this->edges;
            this->copy_object(from);
        }
        return *this;
    }
    void add(Node* const next, const unsigned value = 0, const char label = 0) {
        Edge* new_edges = new Edge[this->edges_length + 1];

        for(int i = 0; i < this->edges_length; i++) {
            new_edges[i] = this->edges[i];
        }

        delete[] this->edges;
        this->edges = new_edges;
        this->edges_length += 1;
    }

    int value(const Node* other) {
        for(int i = 0; i < this->edges_length; i++) {
            if(this->edges[i].get_next() == other) {
                return this->edges[i].get_value();
            }
        }
        return -1;
    }

    char label(const Node* other) {
        for(int i = 0; i < this->edges_length; i++) {
            if(this->edges[i].get_next() == other) {
                return this->edges[i].get_label();
            }
        }
        return 0;
    }
    void copy_object(const Node& from) {
        this->edges = Node::copy_array(from.edges, from.edges_length);
        this->edges_length = from.edges_length;
    }
    static Edge* copy_array(const Edge* from, const int size) {
        Edge* result = new Edge[size];

        for(int i = 0; i < size; i++) {
            result[i] = from[i];
        }

        return result;
    }
    ~Node() {
        delete[] this->edges;   
    }

private:
    Edge* edges;
    int edges_length;

};

class Branch {
public:
    Branch(): nodes(nullptr), nodes_length(0) {}

    Branch(const Branch& from) {
        this->copy_object(from);
    }

    Branch& operator=(const Branch& from) {
        if(this != &from) {
            delete[] this->nodes;
            this->copy_object(from);
        }
        return *this;
    }

    ~Branch() {
        delete[] this->nodes;
    }

    void add(const Node& node) {
        Node* new_nodes = new Node[this->nodes_length + 1];

        for(int i = 0; i < this->nodes_length; i++) {
            new_nodes[i] = this->nodes[i];
        }

        delete[] this->nodes;
        this->nodes = new_nodes;

        this->nodes_length += 1;
    }

    int val() const {
        int result = 0;
        for(int i = 0; i < this->nodes_length - 1; i++) {
            result += this->nodes[i].value(&this->nodes[i+1]);
        }
    }

    char* word() const {
        char buffer[200];
        for(int i = 0; i < this->nodes_length - 1; i++) {
            buffer[i] += this->nodes[i].label(&this->nodes[i+1]);
        }
        buffer[this->nodes_length] = '\0';

        char* result = new char[strlen(buffer) + 1];
        strcpy(result, buffer);

        return result;
    }
    void copy_object(const Branch& from) {
        this->nodes = Branch::copy_array(from.nodes, from.nodes_length);
        this->nodes_length = from.nodes_length;
    }
    static Node* copy_array(const Node* from, const int size) {
        Node* result = new Node[size];

        for(int i = 0; i < size; i++) {
            result[i] = from[i];
        }

        return result;
    }
private:
    Node* nodes;
    int nodes_length;
};


int main() {
    std::cout << "Hello world !" << std::endl;

    return 0;
}