//
// Created by Tapeswar on 2/13/20.
//

#ifndef TASK_POOL_H
#define TASK_POOL_H
#include <helper/safe_queue.h>

namespace encoder {
	
    constexpr size_t thread_pool_size{5};
    constexpr size_t thread_pool_max_size{25};

    template<typename PARAM>
    class TaskPool {
    public:
        using UpdateThreadByRef = std::function<void(PARAM &&, const size_t)>;
        struct StoreType {
            PARAM data;
            UpdateThreadByRef handler;
        };

        explicit TaskPool(const size_t pool_size = 0);

        void Run(const size_t thread_id);

        void AddTask(PARAM &&param, UpdateThreadByRef &&handler);

        void ShutDown();

        ~TaskPool();

    private:
        void HandelThread(const size_t thread_id);

        SafeQueue <StoreType> param_task_queue_;
        std::condition_variable condition_to_run_;
        std::atomic_bool shut_down_{false};
    };

    template<typename PARAM>
    TaskPool<PARAM>::TaskPool(const size_t pool_size)
    {
            auto min_size = thread_pool_size;
            if (pool_size)
            {
                min_size = std::min(pool_size, thread_pool_max_size);
            }

           for (size_t index = 0; index < min_size; index++)
           {
             Run(index);
           }
    }

    template<typename PARAM>
    void TaskPool<PARAM>::Run(const size_t thread_id)
    {
        shut_down_.store(false);
        std::thread reader(&TaskPool::HandelThread, this, thread_id);
        if (reader.joinable()) {
            reader.detach();
        }
    }

    template<typename PARAM>
    void TaskPool<PARAM>::HandelThread(const size_t thread_id) {
        while (false == shut_down_.load()) {
            {
                auto msg = param_task_queue_.Pop();
                if (msg.handler != nullptr)
                    msg.handler(std::move(msg.data), thread_id);
            }
        }
    }

    template<typename PARAM>
    void TaskPool<PARAM>::AddTask(PARAM &&param, UpdateThreadByRef &&handler) {
        StoreType type{std::move(param), std::move(handler)};
        param_task_queue_.Push(std::move(type));
    }

    template<typename PARAM>
    void TaskPool<PARAM>::ShutDown() {
        param_task_queue_.ShutDown();
        shut_down_.store(true);
        condition_to_run_.notify_all();
    }

    template<typename PARAM>
    TaskPool<PARAM>::~TaskPool() {
        ShutDown();
    }

}//end of namespace
#endif  // TASK_POOL_H
