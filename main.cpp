// Virtual Train Route Planner in C++
// Features:
// - Doubly linked list for navigation (forward/backward)
// - Circular linked list for loop routes
// - Interactive menu-based system

#include <bits/stdc++.h>
using namespace std;

struct Station {
    string name;
    Station* next;
    Station* prev;
    Station(string n) : name(n), next(nullptr), prev(nullptr) {}
};

class TrainRoute {
private:
    Station* head;
    Station* tail;
    Station* current;
    bool isCircular;

public:
    TrainRoute(bool circular = false) {
        head = tail = current = nullptr;
        isCircular = circular;
    }

    void addStation(string name) {
        Station* s = new Station(name);
        if (!head) {
            head = tail = current = s;
        } else {
            tail->next = s;
            s->prev = tail;
            tail = s;
        }

        // If circular, connect tail → head
        if (isCircular) {
            tail->next = head;
            head->prev = tail;
        }
    }

    void displayRoute(int rounds = 1) {
        if (!head) {
            cout << "No stations in route.\n";
            return;
        }

        cout << "Train Route: ";
        Station* temp = head;
        int count = 0;
        do {
            cout << temp->name;
            temp = temp->next;
            if (temp != head) cout << " -> ";
            count++;
        } while (temp && (isCircular ? count < rounds * routeLength() : temp != nullptr));
        cout << "\n";
    }

    void moveForward() {
        if (!current) return;
        current = current->next;
        if (!current) { // reached end of non-circular route
            current = tail; 
        }
        cout << "Now at: " << current->name << "\n";
    }

    void moveBackward() {
        if (!current) return;
        current = current->prev;
        if (!current) { // reached start of non-circular route
            current = head; 
        }
        cout << "Now at: " << current->name << "\n";
    }

    void showCurrent() {
        if (!current) cout << "No current station.\n";
        else cout << "Current Station: " << current->name << "\n";
    }

    int routeLength() {
        if (!head) return 0;
        int len = 0;
        Station* temp = head;
        do {
            len++;
            temp = temp->next;
        } while (temp && temp != head);
        return len;
    }
};

int main() {
    cout << "=== Virtual Train Route Planner ===\n";
    cout << "Choose route type:\n1. Linear Route\n2. Circular Route\nEnter choice: ";
    int choice;
    cin >> choice;

    bool circular = (choice == 2);
    TrainRoute route(circular);

    int n;
    cout << "Enter number of stations: ";
    cin >> n;

    cout << "Enter station names:\n";
    for (int i = 0; i < n; i++) {
        string name;
        cin >> ws; // clear whitespace
        getline(cin, name);
        route.addStation(name);
    }

    cout << "\nRoute created successfully!\n";
    route.displayRoute(circular ? 2 : 1);

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Show Current Station\n";
        cout << "2. Move Forward\n";
        cout << "3. Move Backward\n";
        cout << "4. Show Full Route\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        int opt;
        cin >> opt;

        switch (opt) {
            case 1: route.showCurrent(); break;
            case 2: route.moveForward(); break;
            case 3: route.moveBackward(); break;
            case 4: route.displayRoute(circular ? 2 : 1); break;
            case 5: cout << "Exiting planner...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }

    return 0;
}
