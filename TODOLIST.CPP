#include <iostream.h>
#include <conio.h>
#include <string.h>

const int MAX_TASKS = 10;
int i;
class Task
{
public:
    char description[100];
};

class ToDoList
{
private:
    Task tasks[MAX_TASKS];
    int numTasks;

public:
    ToDoList()
    {
        numTasks = 0;
    }

    void addTask()
    {
        if (numTasks < MAX_TASKS)
        {
            Task newTask;
            cout << "Enter task description: ";
            cin.ignore();
            cin.getline(newTask.description, 100);
            tasks[numTasks] = newTask;
            numTasks++;
            cout << "Task added!\n";
        }
        else
        {
            cout << "Task list is full!\n";
        }
    }

    void editTask()
    {
        cout << "Enter task number to edit (1-" << numTasks << "): ";
        int taskNum;
        cin >> taskNum;

        if (taskNum >= 1 && taskNum <= numTasks)
        {
            cout << "Enter new task description: ";
            cin.ignore();
            cin.getline(tasks[taskNum - 1].description, 100);
            cout << "Task updated!\n";
        }
        else
        {
            cout << "Invalid task number!\n";
        }
    }

    void removeTask()
    {
        int taskNum;
        cout << "Enter task number to remove (1-" << numTasks << "): ";
        cin >> taskNum;

        if (taskNum >= 1 && taskNum <= numTasks)
        {
            for (i = taskNum - 1; i < numTasks - 1; ++i)
            {
                tasks[i] = tasks[i + 1];
            }
            numTasks--;
            cout << "Task removed!\n";
        }
        else
        {
            cout << "Invalid task number!\n";
        }
    }

    void listTasks()
    {
        cout << "Tasks:\n";
        for (i = 0; i < numTasks; ++i)
        {
            cout << i + 1 << ". ";
            cout << "[X] ";
            cout << tasks[i].description << "\n";
        }
    }
};

int main()
{
    ToDoList todo;

    while (1)
    {
        clrscr();

        cout << "To-Do List Application\n";
        cout << "1. Add Task\n";
        cout << "2. Edit Task\n";
        cout << "3. Remove Task\n";
        cout << "4. List Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            todo.addTask();
            break;
        case 2:
            todo.editTask();
            break;
        case 3:
            todo.removeTask();
            break;
        case 4:
            todo.listTasks();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }

        cout << "\nPress enter to continue...";
        getch();
        getch();
    }
    getch();
    return 0;
}