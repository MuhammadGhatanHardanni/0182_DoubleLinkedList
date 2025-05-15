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
        if (start == NULL || nim <= start->noMhs)
        {
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
    };
};