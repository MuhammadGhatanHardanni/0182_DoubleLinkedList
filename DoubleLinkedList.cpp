#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
        int noMhs;
        Node *next;
        Node *prev;
};

class DoubleLinkedList
{
private:
    Node *start;

    public:
    DoubleLinkedList()
    {
        start = NULL;
    }

    void addNode()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newNode = new Node();

        // Step 2: Assign value to the data fields
        newNode->noMhs = nim;

        // Step 3: Insert at beginning if list is empty or nim is smallest
        if (start == NULL || nim <= start->noMhs){
            if (start != NULL && nim == start->noMhs){
            cout << "\nDuplicate number not allowed" << endl;
            return;
            }
        // Step 4: newNode.next = Start
        newNode->next = start;

        // step 5: Start.prev = newNode (if Start exists)
        if (start != NULL)
            start->prev = newNode;

        // Step 6: newNode.prev = NULL
        newNode->prev = NULL;

        // Step 7: Start = newNode
        start = newNode;
        return;
        }

        // insert in between node
        // Step 8: Locate position for insertion
        Node *current = start;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // Step 9: Insert between current and current->next
        newNode->next = current->next; // step 9a: newNode.next = current.next
        newNode->prev = current;       // Step 9b: newNode.prev = current

        // insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // Step 9c: current.next.prev = newNode

            current->next = newNode; // Step 9d: current.next = newNode
    }

    void hapus()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose recorf is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = start;

        // step 1 traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // Step 2: if node is at the beginning
        if (current == start)
        {
            start = current->next; // Step 2a: Start = Start.next
            if (start != NULL)
                start->prev = NULL; // Step 2b: Start.prev = NULL
        }
        else
        {
            // Step 3: Link previous node to next of current
            current->prev->next = current->next;

            // Step 4: if current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 5: Delete the node
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse(){
        if (start == NULL)
        {
            cout << "\nList is Empty" << endl;
            return;
        }
        // Step 1: Mark first node ass currentNode
        Node *currentNode = start;
        // Step 2: Repeat until currenttNode == NULL
        cout << "\nRecords in ascending order off roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << 1 + 1 << ". " << currentNode->noMhs << " " << endl;
            // Step 3: Move to next node
            currentNode = currentNode->next;
            i++;
        }
        
    }

    void revtraverse()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
         // Step 1: Move to last node
         Node *currentNode = start;
         int i = 0;
         while (currentNode->next != NULL)
         {
             currentNode = currentNode->next;
             i++;
         }
 
         // Step 2: Traverse backward
         cout << "\nRecords in descending order of roll number are:\n";
         while (currentNode != NULL)
         {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // step 3: move to previous node
            currentNode = currentNode->prev;
            i--;
         }
         
    }

    void searchData()
    {
        if (start == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = start;

        // Step 1: Traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        // step 2: Output result
        if (current == NULL)
        {
            cout << "Reocrd not found\n";
        } 
        else
        {
            cout << "Record Found\n";
            cout << "Roll Number: " << current->noMhs << endl;
        }
        
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
        }
        cout << "\nPress Enter to continue....";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');
}