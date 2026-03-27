#ifndef TASKSERVICE_CLASS_H
#define TASKSERVICE_CLASS_H

#include <core/domain/Task.h>
#include <core/repositories/ITaskRepository.h>

class TaskService {
    public:
        explicit TaskService(ITaskRepository& repo);
        int CreateTask(const Task& task);
        std::vector<Task> GetTasks();
        void UpdateTask(const Task& task);
        void RemoveTask(int id);

    private:
        ITaskRepository& m_repo;
};

#endif
