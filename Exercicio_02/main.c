#include "lista.h"

int main() {
    struct TaskList* taskList = initializeTaskList();

    insertOrdered(taskList, "Tarefa1", 3, "pendente");
    insertOrdered(taskList, "Tarefa2", 5, "em progresso");
    insertOrdered(taskList, "Tarefa3", 2, "pendente");

    printTasks(taskList);

    removeTask(taskList, "Tarefa2");

    struct TaskNode* highestPriorityTask = getHighestPriorityTask(taskList);
    if (highestPriorityTask) {
        printf("A tarefa de maior prioridade não concluída é: %s\n", highestPriorityTask->name);
    } else {
        printf("Não há tarefas não concluídas na lista.\n");
    }

    return 0;
}
