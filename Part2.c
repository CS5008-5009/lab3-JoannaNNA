#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Function to search for an element in the linked list
int search(int element)
{
    struct Node *current = head;
    int position = 1;

    while (current != NULL)
    {
        if (current->value == element)
        {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

// Function to insert an element at a specific position in the linked list
void insertAtPosition(int element, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = element;

    if (position == 1)
    {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    else
    {
        struct Node *current = head;
        int currentPosition = 1;

        while (current != NULL && currentPosition < position - 1)
        {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL)
        {
            printf("Invalid position\n");
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

// Function to insert an element at the head of the linked list
void insertAtHead(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert an element at the end of the linked list
void insertAtEnd(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        struct Node *current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to delete an element from the linked list
void deleteElement(int element)
{
    struct Node *current = head;

    while (current != NULL)
    {
        if (current->value == element)
        {
            if (current == head)
            {
                head = current->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
            }
            else
            {
                current->prev->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = current->prev;
                }
            }
            free(current);
            return;
        }

        current = current->next;
    }

    printf("Element not found\n");
}

// Function to delete the head of the linked list
void deleteHead()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete the last element of the linked list
void deleteLast()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    if (current == head)
    {
        head = NULL;
    }
    else
    {
        current->prev->next = NULL;
    }

    free(current);
}

// Function to print all elements in the linked list
void printList()
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d", current->value);

        if (current->next != NULL)
        {
            printf(" <--> ");
        }

        current = current->next;
    }

    printf("\n");
}

// Function to print all elements in the linked list in reverse order
void printReverseList()
{
    struct Node *current = head;

    if (current == NULL)
    {
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    while (current != NULL)
    {
        printf("%d", current->value);

        if (current->prev != NULL)
        {
            printf(", ");
        }

        current = current->prev;
    }

    printf("\n");
}

int main()
{
    // Test the linked list operations
    insertAtEnd(23);
    insertAtEnd(52);
    insertAtEnd(19);
    insertAtEnd(9);
    insertAtEnd(100);

    printf("Original linked list: ");
    printList();

    int searchElement;
    printf("Enter the element to search: ");
    scanf("%d", &searchElement);
    int position = search(searchElement);
    if (position != -1)
    {
        printf("Element found at position %d\n", position);
    }
    else
    {
        printf("Element not found\n");
    }

    int insertElement, insertPosition;
    printf("Enter the element and position to insert: ");
    scanf("%d %d", &insertElement, &insertPosition);
    insertAtPosition(insertElement, insertPosition);
    printf("After insertion : ");
    printList();

    int insertHeadElement;
    printf("Enter the element to insert at the head: ");
    scanf("%d", &insertHeadElement);
    insertAtHead(insertHeadElement);
    printf("After insertion : ");
    printList();

    int insertEndElement;
    printf("Enter the element to insert at the end: ");
    scanf("%d", &insertEndElement);
    insertAtEnd(insertEndElement);
    printf("After insertion : ");
    printList();

    int deleteElementValue;
    printf("Enter the element to delete: ");
    scanf("%d", &deleteElementValue);
    deleteElement(deleteElementValue);
    printf("After insertion : ");
    printList();

    printf("Deleting the head: ");
    deleteHead();
    printList();

    printf("Deleting the last element: ");
    deleteLast();
    printList();

    printf("Elements in reverse order: ");
    printReverseList();

    return 0;
}