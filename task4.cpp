#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks
string taskDescriptions[MAX_TASKS];
bool taskCompleted[MAX_TASKS] = { false };
int taskCount = 0; // Keep track of the number of tasks

int Add_tasks() {
    if (taskCount < MAX_TASKS) {
        cout << "Enter task description: ";
        cin.ignore(); // Ignore any previous newline character
        getline(cin, taskDescriptions[taskCount]);
        taskCompleted[taskCount] = false;
        int addedIndex = taskCount;
        taskCount++;
        cout << "Task added successfully!" << endl;
        return addedIndex;
    }
    else {
        cout << "Task list is full. Cannot add more tasks." << endl;
        return -1; // Indicate failure to add task
    }
}

void Remove_task() {
    if (taskCount > 0) {
     cout << "Enter the index of the task to remove: ";
        int index;
        cin >> index;

        if (index >= 0 && index < taskCount) {
            for (int i = index; i < taskCount - 1; ++i) {
                taskDescriptions[i] = taskDescriptions[i + 1];

                taskCompleted[i] = taskCompleted[i + 1];
            }
            taskCount--;
            cout << "Task removed successfully!" << endl;
        }
        else {
            cout << "Invalid index. No task removed." << endl;
        }
    }
    else {
      cout << "Task list is empty. No task to remove." <<endl;
    }
}

void mark_task() {
    if (taskCount > 0) {
        cout << "Enter the index of the task to mark as completed: ";
        int index;
       cin >> index;

        if (index >= 0 && index < taskCount) {
            taskCompleted[index] = true;
           cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid index. No task marked." << endl;
        }
    }
    else {
       cout << "Task list is empty. No task to mark." << endl;
    }
}

void view_tasks() {
    if (taskCount > 0) {
        std::cout << "Task List:" << std::endl;
        for (int i = 0; i < taskCount; ++i) {
           cout << "[" << i << "] ";
           cout << (taskCompleted[i] ? "[Completed] " : "[Pending] ");
          cout << taskDescriptions[i] << endl;
        }
    }
    else {
        cout << "Task list is empty." << endl;
    }
}

void input_task() {
   cout << "1: Add task\n2: Remove task\n3: Mark task as completed\n4: View tasks\n0: Exit\n";
    int choice;
   cin >> choice;
    switch (choice) {
    case 1: {
        int addedIndex = Add_tasks();
        if (addedIndex != -1) {
         cout << "Added task index: " << addedIndex << endl;
        }
        break;
    }
    case 2:
        Remove_task();
        break;
    case 3:
        mark_task();
        break;
    case 4:
        view_tasks();
        break;
    case 0:
      cout << "Exiting program. Goodbye!" << endl;
        exit(0);
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}
int main() {
    while (true) {
        input_task();
    }
    return 0;
}
