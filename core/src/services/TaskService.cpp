#include <core/services/TaskService.h>

TaskService::TaskService(ITaskRepository& repo) 
    : m_repo(repo)
{}

int TaskService::CreateTask(const Task& task) {
    return m_repo.Add(task);
}

std::vector<Task> TaskService::GetTasks() {
    return m_repo.GetAll();
}

void TaskService::UpdateTask(const Task& task) {
    m_repo.Update(task);
}

void TaskService::RemoveTask(int id) {
    m_repo.Remove(id);
}
