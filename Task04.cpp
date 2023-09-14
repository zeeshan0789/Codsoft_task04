#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                Task task;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, task.description);
                task.completed = false;
                tasks.push_back(task);
                cout << "Task added successfully!" << endl;
                break;
            }
            case 2:
                if (tasks.empty()) {
                    cout << "No tasks in the list." << endl;
                } else {
                    cout << "Tasks:" << endl;
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        cout << i + 1 << ". ";
                        if (tasks[i].completed) {
                            cout << "[X] ";
                        } else {
                            cout << "[ ] ";
                        }
                        cout << tasks[i].description << endl;
                    }
                }
                break;
            case 3: {
                size_t index;
                cout << "Enter the task number to mark as completed: ";
                cin >> index;
                if (index >= 1 && index <= tasks.size()) {
                    tasks[index - 1].completed = true;
                    cout << "Task marked as completed!" << endl;
                } else {
                    cout << "Invalid task number." << endl;
                }
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter the task number to remove: ";
                cin >> index;
                if (index >= 1 && index <= tasks.size()) {
                    tasks.erase(tasks.begin() + index - 1);
                    cout << "Task removed successfully!" << endl;
                } else {
                    cout << "Invalid task number." << endl;
                }
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
