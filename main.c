#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>



#define titleSize 100 
#define descriptionSize 255
FILE *fptr;


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

//instert node at the end of linked list
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

void removeNode(int pos) {
    if (pos < 0 || pos >= numOfTask || head == NULL) return;

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        free(temp->task);
        free(temp);
    } else {
        Node* current = head;
        for (int i = 0; i < pos - 1 && current->next != NULL; i++) {
            current = current->next;
        }

        Node* nodeToRemove = current->next;
        current->next = nodeToRemove->next;

        if (nodeToRemove == lastAddedNode) {
            lastAddedNode = current;  // Update lastAddedNode if needed
        }

        free(nodeToRemove->task);
        free(nodeToRemove);
    }

    numOfTask--;
}





// insert node at specific index 

Node* insertNodeAtPos(Node* head,Node* newNode,int pos){
  

if(pos<=0){
    newNode->next = head;
    numOfTask++;
    return newNode;
}

if(pos>=numOfTask){
    return insertNodeAtEnd(head,newNode);
}

  Node* current = head;
  int index = 0;  

  while (current!=NULL&&index<pos-1)
  {
   current=current->next;
   index++;
  }
  
  if (current != NULL) {
    newNode->next = current->next;
    current->next = newNode;
    numOfTask++;
}


return head;
}

Node* searchById(Node* head, int id) {
    Node* current = head;
    while (current != NULL) {
        if (current->task->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}



Node* searchByTitle(Node* head, const char* title) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->task->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}
int idNum(char title[]) {
    unsigned long hash = 5381; 
    int c;

    while ((c = *title++)) {
        hash = ((hash << 5) + hash) + c; 
    }

    return hash % 100000; 
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


FILE* save(Node* head){
    
    Node* current = head;
    fptr = fopen("app.txt","w");
    if (fptr == NULL) {
        printf("The file is not opened.");
        exit(1);
    }else{
        printf("The file is open");
    }

    while (current != NULL) {
        int id = current->task->id;
        int state = current->task->state;
        char* title = current->task->title;
        char* description = current->task->description;
        fprintf(fptr, "Id:%d|", id);
        fprintf(fptr, "Title:%s|", title);
        fprintf(fptr, "Description:%s|", description);
        fprintf(fptr, "State:%d\n", state);

        current = current->next;
    }

    fclose(fptr);

    return fptr;
}

FILE* load() {
    fptr = fopen("app.txt", "r");
    if (fptr == NULL) {
        printf("Failed to open app.txt\n");
        return NULL;
    }

    char buffer[512];
    while (fgets(buffer, sizeof(buffer), fptr)) {
        int id, state;
        char title[titleSize], description[descriptionSize];

        int fieldsParsed = sscanf(buffer, "Id:%d|Title:%[^|]|Description:%[^|]|State:%d", &id, title, description, &state);
        if (fieldsParsed == 4) {
            Task* task = createTask(id, description, title);
            task->state = state;
            createNode(task);
        }
    }

    fclose(fptr);
    return fptr;
}




int main() {
    int choice;

    while (1) {
        printf("\n--- TASK MANAGER ---\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View All Tasks\n");
        printf("4. Save Tasks to File\n");
        printf("5. Load Tasks from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline after scanf

        if (choice == 6) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1: {
                char title[titleSize];
                char description[descriptionSize];

                printf("Enter task title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // remove newline

                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // remove newline

                int id = idNum(title);
                Task* task = createTask(id, description, title);
                createNode(task);
                printf("Task added.\n");
                break;
            }

            case 2: {
                int pos;
                printf("Enter task position to remove (0-based): ");
                scanf("%d", &pos);
                removeNode(pos);
                save(head); // <-- Automatically save after deletion
                printf("Task removed (if position was valid) and file updated.\n");
                break;
            }

            case 3:
                printList(head);
                break;

            case 4:
                save(head);
                printf("Tasks saved to app.txt\n");
                break;

            case 5:
                load();
                printf("Tasks loaded from app.txt\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}


