#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> list;
    int choice, value, specific;
    do
    {
        cout << "\n===== ARRAY LIST MENU =====\n";
        cout << "1. Insert value at end\n";
        cout << "2. Insert value at start\n";
        cout << "3. Insert value after specific value\n";
        cout << "4. Insert value before specific value\n";
        cout << "5. Display array list\n";
        cout << "6. Delete value from end\n";
        cout << "7. Delete value from start\n";
        cout << "8. Delete specific value\n";
        cout << "9. Linear Search\n";
        cout << "10. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.push_back(value);
            cout << "Value inserted at end.\n";
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insert(list.begin(), value);
            cout << "Value inserted at start.\n";
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter specific value: ";
            cin >> specific;
            {
                bool found = false;
                for (int i = 0; i < list.size(); i++)
                {
                    if (list[i] == specific)
                    {
                        list.insert(list.begin() + i + 1, value);
                        found = true;
                        cout << "Value inserted after "
                             << specific << ".\n";
                        break;
                    }
                }
                if (!found)
                    cout << "Specific value not found.\n";
            }
            break;
        case 4:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter specific value: ";
            cin >> specific;
            {
                bool found = false;
                for (int i = 0; i < list.size(); i++)
                {
                    if (list[i] == specific)
                    {
                        list.insert(list.begin() + i, value);
                        found = true;
                        cout << "Value inserted before "
                             << specific << ".\n";
                        break;
                    }
               }
                if (!found)
                    cout << "Specific value not found.\n";
            }
            break;
        case 5:
            cout << "Array List: ";
            if (list.empty())
            {
                cout << "List is empty.";
            }
            else
            {
                for (int i = 0; i < list.size(); i++)
                {
                    cout << list[i] << " ";
                }
            }
            cout << endl;
            break;
        case 6:
            if (list.empty())
            {
                cout << "List is empty.\n";
            }
            else
            {
                list.pop_back();
                cout << "Value deleted from end.\n";
            }
            break;
        case 7:
            if (list.empty())
            {
                cout << "List is empty.\n";
            }
            else
            {
                list.erase(list.begin());
                cout << "Value deleted from start.\n";
            }
            break;
        case 8:
            cout << "Enter value to delete: ";
            cin >> specific;
            {
                bool found = false;
                for (int i = 0; i < list.size(); i++)
                {
                    if (list[i] == specific)
                    {
                        list.erase(list.begin() + i);
                        found = true;
                        cout << "Value deleted successfully.\n";
                        break;
                    }
                }
                if (!found)
                    cout << "Value not found.\n";
            }
            break;
        case 9:
            cout << "Enter value to search: ";
            cin >> value;
            {
                int i = 0;
                bool found = false;
                while (i < list.size())
                {
                    if (list[i] == value)
                    {
                        cout << "Value found at index "
                             << i << ".\n";
                        found = true;
                        break;
                    }
                    i++;
                }
                if (!found)
                {
                    cout << "Value not found.\n";
                }
            }
            break;
        case 10:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);
    return 0;
}

