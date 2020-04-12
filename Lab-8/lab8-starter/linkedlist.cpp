/*
 Name: Nathaniel Possel                     NetID: nlp121
 Date: April 9, 2020                        Due Date: April 11, 2020

 Description: This project was to create class functions to do many actions to a linked list, including linear searching, sorting, reverse sorting,
 finding the smallest number, finding the largest number, finding the mean, inserting, and removing
*/
#include "linkedlist.h"

// GIVEN TO STUDENTS

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(head != nullptr)
    {
        Node *temp;

        while(head != nullptr)
        {
            temp = head->next;

            // deletes head
            delete head;

            // goes to next element
            head = temp;
        }
    }
}

void LinkedList::display()
{
    Node *temp = head;

    for(int i = 0; i < size; i++)
    {
        cout << temp->data << "\t";

        temp = temp->next;
    }

    cout << endl;
}

void LinkedList::append(int num)
{
    // list is empty
    if(head == nullptr)
    {
        head = new Node;

        head->data = num;
        head->next = nullptr;

        // sets tail to head
        tail = head;
    }

    else
    {
        // creates new node
        Node *temp = new Node;

        // sets new node data
        temp->data = num;
        temp->next = nullptr;

        // sets previous tail link to new node
        tail->next = temp;

        // sets this node to new tail
        tail = temp;
    }

    // increments size
    size++;
}

void LinkedList::pop()
{
    if(size > 1)
    {
        Node *temp = head;

        // loops to node before tail
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // deletes tail
        delete tail;

        // sets new tail
        tail = temp;
        tail->next = nullptr;
    }

    // if there's only one item
    else if(size == 1)
    {
        Node *temp = tail;

        // head and tail are now null
        head = nullptr;
        tail = nullptr;

        // deletes node
        delete temp;
    }

    size--;
}

// END GIVEN TO STUDENTS

int LinkedList::linearSearch(int key)
{
    //declarations of temp node and pres(position)
    int pres;
    Node *temp = head;

    // loops through linked list and keeps i the position
    for(int i=0; i<size; i++)
    {
        if(temp->data == key)
        {
            //if data is the key, sets pres to the position and breaks from the loop because it has been found
            pres = i;
            break;
        }

        else
        {
            //if the data is not the key, sets pres to -1 and temp to the next node
            pres =  -1;
            temp = temp->next;
        }
    }
    return pres;
}

void LinkedList::sort()
{
    //declares a temporary, current, and finished node all null
    Node *temp = nullptr;
    Node *curr = nullptr;
    Node *done = nullptr;

    //loops through entire linked list
    for(int i=0; i<size; i++)
    {
        //sets the current and finished nodes to the head in order to check again and not bubble just the lowest to the front
        curr = done = head;

        //while loop for the sorting
        while(curr->next != nullptr)
        {
            //checks if the data of the current node is greater than the next node's data
            if(curr->data > curr->next->data)
            {
                //sets temp equal to next node, next node equal to the node after that, and then the next node of the temp to the current node.
                temp = curr->next;
                curr->next = curr->next->next;
                temp->next = curr;

                //checks if the current node is the head and sets that and the sorted node to head
                if(curr == head)
                {
                    head = done = temp;
                }

                //sets the next node after the sorted node to temp
                else
                {
                    done->next = temp;
                }

                //sets the node currently on to the temp
                curr = temp;
            }
            //since the current data is less than the next data, sets the current node to sorted and sets current to the next one
            done = curr;
            curr = curr->next;
        }
    }
    //makes the current node the tail
    tail = curr;
    curr->next = nullptr;
}

//same as sort just changing the > in the if statement to <
void LinkedList::reverse()
{
        Node *temp = nullptr;
        Node *curr = nullptr;
        Node *done = nullptr;

        for(int i=0; i<size; i++)
        {
            curr = done = head;

            while(curr->next != nullptr)
            {
                if(curr->data < curr->next->data)
                {
                    temp = curr->next;
                    curr->next = curr->next->next;
                    temp->next = curr;

                    if(curr == head)
                    {
                        head = done = temp;
                    }

                    else
                    {
                        done->next = temp;
                    }

                    curr = temp;
                }
                done = curr;
                curr = curr->next;
            }
        }
        tail = curr;
        curr->next = nullptr;
}

int LinkedList::min()
{
    //declarations of temp node and i(as a number to check against since no numbers will be negative)
    Node *temp = head;
    int i = temp->data;

    //loops through linked list
    while(temp != nullptr)
    {
        //sets j equal to the current node's data, checks if it is less than the current i and sets i equal to j if so
        int j = temp->data;
        if(j < i)
        {
            i = j;
        }
        //sets temp equal to the next node and loops back
        temp = temp->next;
    }
    return i;
}

//same as min function but changes < to > in the if statement
int LinkedList::max()
{
    Node *temp = head;
    int i = temp->data;

    while(temp != nullptr)
    {
        int j = temp->data;
        if(j > i)
        {
            i = j;
        }
        temp = temp->next;
    }
    return i;
}

int LinkedList::mean()
{
    //declares sum as 0 and temp as the head node
    int sum = 0;
    Node *temp = head;

    //loops adding all nodes together
    while(temp != nullptr)
    {
        sum += temp->data;
        temp = temp->next;
    }
    //returns sum/size of the list to get the mean
    return sum/size;
}

void LinkedList::insert(int num, int pos)
{
    //declares var as the head and temp as the new node you are inserting
    Node *temp = new Node;
    Node *var = head;

    //these if/elif/else statements check whether the insertion is to the first, last, or in between position
    if(pos == 0)
    {
        //temp data is set to num, temp next is the head, thus inserting the temp into the list
        temp->data = num;
        temp->next = head;

        head = temp;
    }

    else if(pos == size-1)
    {
        //makes the temp data = num and the next node a nullptr. Then makes the temp the tail putting it into the list
        temp->data = num;
        temp->next = nullptr;

        tail->next = temp;

        tail = temp;
    }

    else
    {
        //checks for correct position with var being the position before the selected position, makes the
        //temp data = num, and puts the temp in the appropriate position and then breaks from the loop
        for(int i=1; i<=size; i++)
        {
            if(i == pos)
            {
               temp->data = num;
               temp->next = var->next;
               var->next = temp;

               break;
            }

            else
            {
                var = var->next;
            }
        }
    }
    size++;
}


void LinkedList::remove(int pos)
{
    //declares var as the head and temp as the node after the head
    Node *var = head;
    Node *temp = head->next;

    //these if/elif/else statements check whether the removal is in the first, last, or in between position
    if(pos == 0)
    {
        //deletes head and sets the temp (node after the head) to head
        delete head;
        head = temp;
    }

    else if(pos == size-1)
    {
        //iterates to the second to last node and deletes the tail, setting that temp to be the tail and the next a nullptr
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete tail;

        tail = temp;
        tail->next = nullptr;
    }

    else
    {
        //iterates to where temp is the node one to be deleted, links the nodes to either side of it, deletes the temp, and breaks from the loop
        for(int i=1; i<=size; i++)
        {
            if(i == pos)
            {
                var->next = var->next->next;
                delete temp;

                break;
            }

            else
            {
                var = var->next;
                temp = temp->next;
            }
        }
    }
    size--;
}

