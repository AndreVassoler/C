#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TaskList* initializeTaskList() {
    struct TaskList* newList = (struct TaskList*)malloc(sizeof(struct TaskList));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

void insertOrdered(struct TaskList* list, char name[], int priority, char status[]) {
    struct TaskNode* newTask = (struct TaskNode*)malloc(sizeof(struct TaskNode));
    snprintf(newTask->name, sizeof(newTask->name), "%s", name);
    newTask->priority = priority;
    snprintf(newTask->status, sizeof(newTask->status), "%s", status);
    newTask->next = NULL;
    newTask->prev = NULL;

    if (list->head == NULL) {
        list->head = newTask;
        list->tail = newTask;
    } else {
        struct TaskNode* current = list->head;
        while (current && (current->priority > priority || (current->priority == priority && current->next))) {
            current = current->next;
        }

        if (!current) {
            newTask->prev = list->tail;
            list->tail->next = newTask;
            list->tail = newTask;
        } else if (!current->prev) {
            newTask->next = list->head;
            list->head->prev = newTask;
            list->head = newTask;
        } else {
            newTask->prev = current->prev;
            newTask->next = current;
            current->prev->next = newTask;
            current->prev = newTask;
        }
    }
}

void removeTask(struct TaskList* list, char name[]) {
    struct TaskNode* current = list->head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            free(current);
            return;
        }
        current = current->next;
    }
}

struct TaskNode* getHighestPriorityTask(struct TaskList* list) {
    struct TaskNode* current = list->head;
    while (current) {
        if (strcmp(current->status, "concluída") != 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printTasks(struct TaskList* list) {
    struct TaskNode* current = list->head;
    while (current) {
        printf("Name: %s, Priority: %d, Status: %s\n", current->name, current->priority, current->status);
        current = current->next;
    }
}
