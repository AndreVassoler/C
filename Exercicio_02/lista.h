#ifndef LISTA_H
#define LISTA_H

struct TaskNode {
    char name[50];
    int priority;
    char status[20];
    struct TaskNode* next;
    struct TaskNode* prev;
};

struct TaskList {
    struct TaskNode* head;
    struct TaskNode* tail;
};

struct TaskList* initializeTaskList();
void insertOrdered(struct TaskList* list, char name[], int priority, char status[]);
void removeTask(struct TaskList* list, char name[]);
struct TaskNode* getHighestPriorityTask(struct TaskList* list);
void printTasks(struct TaskList* list);

#endif  
