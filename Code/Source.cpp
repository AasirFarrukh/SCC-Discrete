#include <iostream>
#include <list>
#include<fstream>
#include<string>
using namespace std;

struct node {
    node* next;
    int data;
};

class List {
public:
    node* head;
    List() {
        head = NULL;
    }

    void push_back(int value) {
        node* val = new node;
        val->data = value;
        val->next = NULL;
        if (head == NULL)
            head = val;
        else {
            node* trav = head;
            while (trav->next != NULL)
                trav = trav->next;
            trav->next = val;
        }
    }

    void display() {
        node* trav = head;
        while (trav)
        {
            cout << trav->data << ", ";
            trav = trav->next;
        }
        cout << endl;
    }
};


class sysStack {
public:
    node* top;

    sysStack() {
        top = NULL;
    }

    void push(int val) {
        node* trav = new node;
        trav->data = val;
        trav->next = NULL;
        if (top == NULL)
            top = trav;
        else {
            trav->next = top;
            top = trav;
        }
    }

    int pop() {
        int temp = top->data;
        top = top->next;
        return temp;
    }

    void display() {
        node* trav = top;
        while (trav) {
            cout << trav->data << "  ";
            trav = trav->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        if (top == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    int topNum() {
        return top->data;
    }
};


class dGraph {
    int vertex;
    list<int>* l;
    //stack fill
    void fill(int node, bool vertexVisit[], sysStack& stk) {
        vertexVisit[node] = true;
        list<int>::iterator itr;
        itr = l[node].begin();

        while (itr != l[node].end()) {
            if (!vertexVisit[*itr]) {
                fill(*itr, vertexVisit, stk);
            }
            itr++;
        }
        stk.push(node);
    }
    //Depth first search and counting largest scc nodes
    int DFS(int node, bool vertexVisit[],int count) {
        vertexVisit[node] = true;
        list<int>::iterator itr;
        itr = l[node].begin();
        count++;
        while (itr != l[node].end()) {
            if (!vertexVisit[*itr]) {
                count = DFS(*itr, vertexVisit, count);
            }
            itr++;
        }
        return count;
    }

public:
    //Default Constructor
    dGraph() {
        vertex = 0;
        l = new list<int>;
    }
    //Constructor
    dGraph(int data) {
        vertex = data;
        l = new list<int>[data];
    }
    //Insert vertex at the end of list
    void insert(int node, int data) {
        l[node].push_back(data);
    }
    //Print SCC
    void print() {
        sysStack stk;
        bool* vertexVist = new bool[vertex];

        //Initially setting all to not visited
        for (int i = 0; i < vertex; i++) {
            vertexVist[i] = false;
        }

        for (int i = 0; i < vertex; i++) {
            if (vertexVist[i] == false) {
                fill(i, vertexVist, stk);
            }
        }
        //reverse the graph
        dGraph revGraph = invert();
        //Initially setting all to not visited
        for (int i = 0; i < vertex; i++) {
            vertexVist[i] = false;
        }
        int largestN = 0;
        int count = 0;
        while (stk.isEmpty() == false) {
            int s = stk.topNum();
            stk.pop();

            if (vertexVist[s] == false) {
                count = revGraph.DFS(s, vertexVist, count);
                if (count >= largestN) {
                    largestN = count;
                    count = 0;
                }
            }
        }
        cout << largestN << endl;
    }
    //Reverse of directed graph
    dGraph invert() {
        dGraph graph(vertex);

        int i = 0;
        while (i < vertex) {
            list<int>::iterator itr;
            itr = l[i].begin();

            while (itr != l[i].end()) {
                graph.l[*itr].push_back(i);
                itr++;
            }
            i++;
        }
        return graph;
    }
};


int main() {   
    string file_name = "web-Google.txt";
    ifstream ff(file_name);
    string term = "";
    string term2 = "";
    int count = 0;

    while (ff >> term) {
        ff >> term2;
        count++;
    }
    ff.close();
    dGraph graph(count);

    ff.open(file_name);
    while (ff >> term) {
        ff >> term2;
        int a = stoi(term);
        int b = stoi(term2);
        graph.insert(a, b);
    }

    cout << "Largest SCC Nodes:" << endl;
    graph.print();
}