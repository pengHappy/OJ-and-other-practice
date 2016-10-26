#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_D 18

typedef struct num{
    char digit[MAX_D];
    struct num *next;
}Node;

typedef Node* Node_pt;

Node_pt Loc[10];

void emptyLoc() {
    for(int i = 0; i < 10; i++)
        Loc[i] = NULL;
}

Node_pt initNodes() {
    emptyLoc();
    char holder[MAX_D] = {'\0'};
    Node_pt head = NULL;
    Node_pt last = NULL;
    while(true) {
        scanf("%s", holder);
        if(strcmp(holder, "-1") == 0)
            break;

        //Initialize a new node
        Node_pt nodePointer = new Node;
        nodePointer->next = NULL;

        //Reverse
        int len = strlen(holder) - 1;
        int i;
        for(i = 0; i <= len; i++)
            nodePointer->digit[i] = holder[len - i];
        while(i < MAX_D)
            nodePointer->digit[i++] = '0';

        //Compose a list
        if(head == NULL) {
            head = nodePointer;
            last = head;
        }
        else {
            last->next = nodePointer;
            last = nodePointer;
        }
    }
    return head;
}

Node_pt composeList() {
    //Compose a list according to the order
    Node_pt head, current;
    int j;
    for(j = 0; j < 10; j++) { //last real node pointer
        if(Loc[j] != NULL) {
            head = Loc[j];
            while(head->next != NULL)
                head = head->next;
            break;
        }
    }
    for(int i = j + 1; i < 10; i++) {
        if(Loc[i] != NULL) {
            current = Loc[i];
            head->next = current;
            while(current->next != NULL)
                current = current->next;
            head = current;
        }
    }
    for(j = 0; j < 10; j++) {
        if(Loc[j] != NULL) {
            head = Loc[j];
            break;
        }
    }
    return head;
}

void distribute(Node_pt head, int i) {
    emptyLoc();
    Node_pt current = head;
    Node_pt listNext = NULL;
    while(current != NULL) {
        listNext = current->next;
        int place = current->digit[i] - '0';
        if(Loc[place] == NULL)
            Loc[place] = current;
        else {
            Node_pt locLast = Loc[place];
            while(locLast->next != NULL)
                locLast = locLast->next;
            locLast->next = current;
        }
        current->next = NULL;
        current = listNext;
    }
}

Node_pt processRadix(Node_pt headPointer) {

    int i;
    Node_pt head = headPointer;
    for(i = 0; i < MAX_D; i++) {
        distribute(head, i);
        head = composeList();
    }
    return head;
}

void printFormated(char a[]) {
    int i = 0;
    int realStart;
    while(i < MAX_D && a[i] != '0')
        i++;
    for(realStart = i - 1; realStart >= 0; realStart--)
        printf("%c", a[realStart]);
    printf("\n");
}

void printAll(Node_pt head) {
    Node_pt current = head;
    printf("\n");
    while(current) {
        printFormated(current->digit);
        current = current->next;
    }
}

void deleteAll(Node_pt head) {
    Node_pt current = head;
    Node_pt theNext = NULL;
    while(current) {
        theNext = current->next;
        delete current;
        current = theNext;
    }
}

int main()
{
    Node_pt head = NULL;
    head = initNodes();
    head = processRadix(head);
    printAll(head);
    deleteAll(head);
    return 0;
}
//No.59
