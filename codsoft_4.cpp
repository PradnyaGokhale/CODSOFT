#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;  // Maximum number of tasks

class ToDoList {
private:
    string tasks[MAX_TASKS];
    bool completed[MAX_TASKS];
    int numTasks;

public:
    ToDoList() : numTasks(0) {}

    void addTask(const string& description) {
        if (numTasks < MAX_TASKS) {
            tasks[numTasks] = description;
            completed[numTasks] = false;
            numTasks++;
            cout << "Task added: " << description << endl;
        } else {
            cout << "Cannot add more tasks. Maximum limit reached." << endl;
        }
    }

    void displayTasks() const {
        if (numTasks == 0) {
            cout << "To-Do List is empty." << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (int i = 0; i < numTasks; i++) {
                cout << "[" << (i + 1) << "] ";
                if (completed[i]) {
                    cout << "[Completed] ";
                } else {
                    cout << "[Pending] ";
                }
                cout << tasks[i] << endl;
            }
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex > 0 && taskIndex <= numTasks) {
            completed[taskIndex - 1] = true;
            cout << "Task marked as completed: " << tasks[taskIndex - 1] << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex > 0 && taskIndex <= numTasks) {
            cout << "Task removed: " << tasks[taskIndex - 1] << endl;
            for (int i = taskIndex - 1; i < numTasks - 1; i++) {
                tasks[i] = tasks[i + 1];
                completed[i] = completed[i + 1];
            }
            numTasks--;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;
    string task;
    int itemNumber;

    while (true) {
        cout << "\nTo-Do List Menu:" << endl;
        cout << "1. Add item" << endl;
        cout << "2. Remove item" << endl;
        cout << "3. Mark as completed" << endl;
        cout << "4. View items" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1:
                cout << "Enter the task to add: ";
                getline(cin, task);
                toDoList.addTask(task);
                break;
            case 2:
                cout << "Enter the item number to remove: ";
                cin >> itemNumber;
                toDoList.removeTask(itemNumber);
                break;
            case 3:
                cout << "Enter the item number to mark as completed: ";
                cin >> itemNumber;
                toDoList.markTaskAsCompleted(itemNumber);
                break;
            case 4:
                toDoList.displayTasks();
                break;
            case 5:
                cout << "Exiting the To-Do List program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;
}
