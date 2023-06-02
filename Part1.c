#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *originalHead = NULL; // Pointer to the original head of the linked list

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
        current->next = newNode;
    }
}

// Function to insert an element at the head of the linked list
void insertAtHead(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = head;
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
    }
}

// Function to delete an element from the linked list
void deleteElement(int element)
{
    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL)
    {
        if (current->value == element)
        {
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            return;
        }

        prev = current;
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
    struct Node *prev = NULL;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
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
            printf(" -> ");
        }

        current = current->next;
    }

    printf("\n");
}

// Function to restore the original linked list
void restoreList()
{
    head = originalHead;
}

int main()
{
    // Test the linked list operations
    insertAtEnd(23);
    insertAtEnd(52);
    insertAtEnd(19);
    insertAtEnd(9);
    insertAtEnd(100);

    originalHead = head; // Store the original head

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

    restoreList(); // Restore the original list

    int insertElement, insertPosition;
    printf("Enter the element and position to insert: ");
    scanf("%d %d", &insertElement, &insertPosition);
    insertAtPosition(insertElement, insertPosition);
    printf("After insertion at position %d: ", insertPosition);
    printList();

    int insertHeadElement;
    printf("Enter the element to insert at the head: ");
    scanf("%d", &insertHeadElement);
    insertAtHead(insertHeadElement);
    printf("After insertion at the head: ");
    printList();

    int insertEndElement;
    printf("Enter the element to insert at the end: ");
    scanf("%d", &insertEndElement);
    insertAtEnd(insertEndElement);
    printf("After insertion at the end: ");
    printList();

    int deleteElementValue;
    printf("Enter the element to delete: ");
    scanf("%d", &deleteElementValue);
    deleteElement(deleteElementValue);
    printf("After deletion: ");
    printList();

    printf("Deleting the head: ");
    deleteHead();
    printList();

    printf("Deleting the last element: ");
    deleteLast();
    printList();

    return 0;
}
