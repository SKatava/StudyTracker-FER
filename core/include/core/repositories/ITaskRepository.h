#ifndef ITASKREPOSITORY_CLASS_H
#define ITASKREPOSITORY_CLASS_H

#include <core/domain/Task.h>

#include <vector>

class ITaskRepository {
    public:
        virtual ~ITaskRepository() = default;

        virtual int Add(const Task& task) = 0;
        virtual std::vector<Task> GetAll() = 0;
        virtual void Update(const Task& task) = 0;
        virtual void Remove(int id) = 0;

};

#endif


