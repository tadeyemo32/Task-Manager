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







void printList(Node* node) {
    while (node) {
        printf("%s -> ", node->task->title);
        node = node->next;
    }
    printf("null\n");
}







int main(){
    char man[descriptionSize] = "Head to the gym at 10am";
    char mum[titleSize] = "Gym";
    char mum2[titleSize] = "School";

    createNode(createTask(10000, man, mum));
    createNode(createTask(10001, man, mum2));

    printList(head); // Print entire list

    return 0;
}
