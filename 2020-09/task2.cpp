#include <iostream>
#include <queue>


struct Node {
    char text;
    Node *left, *right;

    Node(const char text) {
        this->text = text;
    }
};

int get_amount_of_elements(Node* root) {
    int result = 0;

    std::queue<Node*> bfs;

    bfs.push(root);

    int current_level = 0;
    while (bfs.size()) {
        Node* current_element = bfs.front();
        bfs.pop();


        if(current_element != nullptr) {
            result += 1;
            bfs.push(current_element->left);
            bfs.push(current_element->right);
        }
    }

    return result;

}
void print_text(Node* root) {
    std::queue<std::pair<Node*, int>> bfs;

    bfs.push({root, 0});

    int current_level = 0;
    int total_elements = get_amount_of_elements(root);
    while (total_elements > 0) {
        std::pair<Node*, int> current_element = bfs.front();
        bfs.pop();

        if(current_element.second != current_level) {
            std::cout << "\n";
        }

        if(current_element.first == nullptr) {
            std::cout << " ";
        }
        else {
            std::cout << current_element.first->text;

            bfs.push({current_element.first->left, current_element.second + 1});
            bfs.push({current_element.first->right, current_element.second + 1});
            total_elements -=1;
        }
        
        current_level = current_element.second;
    }
}
int main() {
    Node* el = new Node('I');

    el->left = new Node('a');
    el->right = new Node('m');

    el->left->left = new Node('g');
    el->left->right = new Node('o');
    el->right->left = new Node('o');
    el->right->right = new Node('d');

    el->left->left->left = new Node('a');
    el->left->left->right = new Node('t');

    el->left->right->right = new Node('s');

    el->right->left->left = new Node('o');
    el->right->left->right = new Node('l');

    el->right->right->left = new Node('v');
    el->right->right->right = new Node('i');

    el->left->left->left->left = new Node('n');
    el->left->left->left->right = new Node('g');

    print_text(el);
}