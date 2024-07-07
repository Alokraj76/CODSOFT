//To-Do-List management

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string desc; //description
    bool completed;
};
class ToDoList
{
    private:
    vector<Task> tasks;
    public:
    
    void addTask(const string& desc)
    {
        tasks.push_back({desc,false});
        cout<<"Task added successfully."<<"\n";
    }

    void viewTasks()
    {
        if(tasks.empty())
        cout<<"No tasks to display."<<"\n";
        else
        {
            cout<<"Tasks:"<<"\n";
            for(size_t i=0;i<tasks.size(); ++i)
            {
                string status = tasks[i].completed ? "Completed" : "Pending";
                cout<<i+1<<". "<<tasks[i].desc<<" - "<<status<<"\n";
            }
        }
    }

    void markTask(size_t taskIndex)
    {
        if(taskIndex>0 and taskIndex <= tasks.size())
        {
            tasks[taskIndex-1].completed = true;
            cout<<"Task marked as competed."<<"\n";
        }
        else
        cout<<"Invalid task index."<<"\n";
    }

    void removeTask(size_t taskIndex)
    {
        if(taskIndex>0 and taskIndex <= tasks.size())
        {
            tasks.erase(tasks.begin()+taskIndex-1);
            cout<<"Task removed successfully."<<"\n";
        }
        else
        cout<<"Invalid task index."<<"\n";
    }
};

int main()
{
    ToDoList todoList;

    while(true)
    {
        cout<<"\nMenu:"<<"\n";
        cout<<"1.Add Task"<<"\n";
        cout<<"2.View Tasks"<<"\n";
        cout<<"3.Mark Task as completed"<<"\n";
        cout<<"4.Remove Task"<<"\n";
        cout<<"4. Exit"<<"\n";

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: {
                string desc;
                cout<<"Enter task: ";
                cin.ignore();
                getline(cin,desc);
                todoList.addTask(desc);
                break;
            }
            case 2: todoList.viewTasks();
            break;
            case 3: {
                size_t taskIndex;
                cout<<"Enter task index to mark as completed: ";
                cin>>taskIndex;
                todoList.markTask(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                cout<<"Enter task index to remove: ";
                cin>>taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5: cout<<"Exiting...."<<"\n";
            return 0;
            default: cout<<"Invalid choice.Please enter a number between 1 to 5."<<"\n";
        }
    }
    return 0;
}
