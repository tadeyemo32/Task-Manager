#include <stdio.h>
#include<stdlib.h>
#include <string.h>


#define titleSize 100 
#define descriptionSize 255


typedef struct Task {

int id; // Taks ID number for separation 
int state ; // task completed or not completed 
char title[titleSize]; // Name of task
char description[descriptionSize];//Task information 

}Task;

Task* taskList[100]; 
int taskVal = 0; 


int createTask(int id,char description[descriptionSize]  ,char title[titleSize]){ // create a task 

Task* newTask = malloc(sizeof(Task));


if (!newTask){
    printf("Memory Allocation failed\n");
    return 1;
}

newTask-> id = id;
newTask->state =0;

strncpy(newTask->title, title, titleSize - 1);
newTask->title[titleSize - 1] = '\0';

strncpy(newTask->description, description, descriptionSize - 1);
newTask->description[descriptionSize - 1] = '\0';

taskList[taskVal] = newTask; 
taskVal++;

return 0;
}













int main(){
char man[descriptionSize] = "Head to the gym at 10am";
char mum[titleSize] = "Gym";

    createTask(10000,man,mum);
    

    return 0;
}