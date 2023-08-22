#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string& value);
};
Node::Node(string& value) {
    data = value;
    prev = nullptr;
    next = nullptr;
}
class Souhoukou {
public:
    Node* mae;
    Node* ato;
    Souhoukou();
    void kakunou(string& value);
    void show();
};
Souhoukou::Souhoukou() {
    mae = nullptr;
    ato = nullptr;
}
void Souhoukou::kakunou(string& value) {
    {
        Node* newNode = new Node(value);
        if (!mae) {
            mae = ato = newNode;
        }
        else {
            newNode->prev = ato;
            ato->next = newNode;
            ato = newNode;
        }
    }
}
void Souhoukou::show(){
    Node* current = mae;
    while (current) {
        cout << current->data << "\n";
        current = current->next;
    }
}


int main() {
    Souhoukou souhoukou;

    ifstream ifs("Scores.txt");
    if (!ifs) {
        cout << "file not opened;\n";
        return 0;
    }
    else {
        string line;
        while (getline(ifs, line)) {
            souhoukou.kakunou(line);
        }
    }
    souhoukou.show();

    return 0;
}