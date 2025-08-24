#include <iostream>
#include <string>
using namespace std;

// Node structure for train station
struct Station {
    string name;
    Station* next;
    Station* prev;
};

// Class for Train Route
class TrainRoute {
    Station* head;
    bool isCircular;

public:
    TrainRoute(bool circular = false) {
        head = nullptr;
        isCircular = circular;
    }

    // Add station to the route
    void addStation(string stationName) {
        Station* newStation = new Station;
        newStation->name = stationName;
        newStation->next = nullptr;
        newStation->prev = nullptr;

        if (!head) {
            head = newStation;
            if (isCircular) {
                head->next = head;
                head->prev = head;
            }
            return;
        }

        Station* temp = head;
        if (isCircular) {
            // Insert before head in circular route
            Station* tail = head->prev;
            tail->next = newStation;
            newStation->prev = tail;
            newStation->next = head;
            head->prev = newStation;
        } else {
            // Normal doubly linked list append
            while (temp->next) temp = temp->next;
            temp->next = newStation;
            newStation->prev = temp;
        }
    }

    // Display route
    void displayRoute(int count = 0) {
        if (!head) {
            cout << "No stations in the route." << endl;
            return;
        }

        cout << "\nTrain Route:" << endl;
        Station* temp = head;
        int steps = 0;
        do {
            cout << "-> " << temp->name << " ";
            temp = temp->next;
            steps++;
            // for circular routes, prevent infinite loop
            if (isCircular && count != 0 && steps >= count) break;
        } while (temp != nullptr && temp != head);

        cout << endl;
    }

    // Navigate forward through stations
    void navigateForward(int steps) {
        if (!head) {
            cout << "No stations available." << endl;
            return;
        }

        Station* temp = head;
        cout << "\nMoving Forward:" << endl;
        for (int i = 0; i < steps; i++) {
            cout << "At station: " << temp->name << endl;
            temp = temp->next;
            if (!temp) break; // stop if linear route ends
        }
    }

    // Navigate backward through stations
    void navigateBackward(int steps) {
        if (!head) {
            cout << "No stations available." << endl;
            return;
        }

        // Go to tail first if not circular
        Station* temp = head;
        if (!isCircular) {
            while (temp->next) temp = temp->next;
        } else {
            temp = head->prev;
        }

        cout << "\nMoving Backward:" << endl;
        for (int i = 0; i < steps; i++) {
            cout << "At station: " << temp->name << endl;
            temp = temp->prev;
            if (!temp) break;
        }
    }
};

// Main function
int main() {
    int choice;
    cout << "Choose Route Type:\n1. Linear Route\n2. Circular Route\n";
    cin >> choice;

    bool circular = (choice == 2);
    TrainRoute route(circular);

    int n;
    cout << "Enter number of stations: ";
    cin >> n;

    cout << "Enter station names:\n";
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        route.addStation(name);
    }

    int action;
    do {
        cout << "\n--- Train Route Menu ---\n";
        cout << "1. Display Route\n2. Navigate Forward\n3. Navigate Backward\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> action;

        switch (action) {
        case 1:
            if (circular)
                route.displayRoute(n * 2); // show extended cycle
            else
                route.displayRoute();
            break;
        case 2: {
            int steps;
            cout << "Enter steps to move forward: ";
            cin >> steps;
            route.navigateForward(steps);
            break;
        }
        case 3: {
            int steps;
            cout << "Enter steps to move backward: ";
            cin >> steps;
            route.navigateBackward(steps);
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
        }
    } while (action != 4);

    return 0;
}
