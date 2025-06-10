#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>


#define titleSize 100 
#define descriptionSize 255



typedef struct Task {

int id; // Taks ID number for separation 
int state ; // task completed or not completed 
char title[titleSize]; // Name of task
char description[descriptionSize];//Task information 

}Task;


typedef struct Node {

     Task* task; 

    struct Node* next ; 

    
    }Node;


int numOfTask = 0; 
Node* lastAddedNode ; 



Node* head = NULL;


Node* createNode(Task* task){
Node* newNode = (Node*)(malloc(sizeof(Node))) ;
if (!newNode){
    printf("Malloc Failed ");
    exit(1);
}
newNode->task = task; 


if (!numOfTask){
head = newNode;
}else{
    lastAddedNode->next = newNode;
}

lastAddedNode = newNode;
numOfTask++;
return  newNode;
}







Task* createTask(int id,char description[descriptionSize]  ,char title[titleSize]){ // create a task 
Task* newTask = malloc(sizeof(Task));


if (!newTask){
    printf("Memory Allocation failed\n");
    exit(1);
}

newTask-> id = id;
newTask->state =0;

strncpy(newTask->title, title, titleSize - 1);
newTask->title[titleSize - 1] = '\0';

strncpy(newTask->description, description, descriptionSize - 1);
newTask->description[descriptionSize - 1] = '\0';


return newTask;
}



// adds node to the start of the linked list 
Node* insertNodeAtHead(Node* head,Node* nodeToBeInserted){


nodeToBeInserted->next = head;

return nodeToBeInserted;
}


Node* insertNodeAtEnd( Node* head,Node* newNode){

 if (head == NULL){
    return newNode;
 }
Node* current = head;

while (current->next != NULL) {
    current = current->next;  
}
 
current->next = newNode;
newNode->next = NULL;  

return head;

}





void printList(Node* node) {
    while (node) {
        printf("ID: %d | Title: %s | State: %s\n", 
               node->task->id, 
               node->task->title,
               node->task->state ? "Done" : "Pending");
        node = node->next;
    }
    printf("End of List.\n");
}

int main(){
    char man[descriptionSize] = "Head to the gym at 10am";
    char mum[titleSize] = "Gym";
    char mum2[titleSize] = "School";
    char num3[titleSize] = "Hospital";
    char num4[titleSize] = "Police Station";

    createNode(createTask(10000, man, "Office"));
    createNode(createTask(10001, man, mum));
    createNode(createTask(10001, man, mum2));
    createNode(createTask(10001, man, num3));
    createNode(createTask(10001, man, num4));

    printList(head); // Print entire list
printf("%d\n",numOfTask);

    return 0;
}
