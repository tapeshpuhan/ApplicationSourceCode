#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

class MaxHeap
{
    public:
    
    MaxHeap();
    MaxHeap(const std::initializer_list<int>& list);
    void InsertElements(const std::initializer_list<int>& list);
    void InsertElement(const int number);
    void DeleteElement(const int number);
    void DisplayHeap();
    private:
    
    size_t GetParentIndex(const size_t index);
    size_t GetLeftChildIndex(const size_t index);
    size_t GetRightChildIndex(const size_t index);
    void ReArrengeMaxHeap(std::vector<int>& heap, const size_t child_index);
    void SwapIndexValues(std::vector<int>& heap, const size_t source, const size_t dest)noexcept;
    
    std::vector<int> max_heap_;
    size_t heap_size_{0};
};

MaxHeap::MaxHeap(const std::initializer_list<int>& list)
{
    max_heap_.reserve(list.size());
    
    for(const auto& value : list)
    {
        InsertElement(value);
    }
}

void MaxHeap::InsertElements(const std::initializer_list<int>& list)
{
    max_heap_.reserve(heap_size_ + list.size());
    
    for(const auto& value : list)
    {
        InsertElement(value);
    }
}

void MaxHeap::InsertElement(const int number)
{
    max_heap_.push_back(number);
    heap_size_ = max_heap_.size();
    ReArrengeMaxHeap(max_heap_,heap_size_-1);
}

size_t MaxHeap::GetParentIndex(const size_t index)
{
    size_t result_index = 0;
    
    if(index > 0)
    {
        result_index = (index-1)/2;
    }
    
    return result_index;
}

size_t MaxHeap::GetLeftChildIndex(const size_t index)
{
    return (index * 2) + 1;
}

size_t MaxHeap::GetRightChildIndex(const size_t index)
{
    return (index * 2) + 2;
}

void MaxHeap::SwapIndexValues(std::vector<int>& heap, const size_t source, const size_t dest)noexcept
{
    int temp = heap[source];
    heap[source] = heap[dest];
    heap[dest] = temp;
}

void MaxHeap::ReArrengeMaxHeap(std::vector<int>& heap, const size_t child_index)
{
    if(child_index)
    {   size_t child_local_index =  child_index;
        while(child_local_index)
        {
            size_t parent_index = GetParentIndex(child_local_index);
            
            if(heap[parent_index] < heap[child_local_index])
            {
                SwapIndexValues(heap,parent_index,child_local_index);
            }
            else
            {
                break;
            }
            child_local_index = parent_index;
        }
    }   
}

void MaxHeap::DeleteElement(const int number)
{
}
void MaxHeap::DisplayHeap()
{
    for(const auto& value : max_heap_)
    {
        std::cout<<value<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    MaxHeap obj{4,5,2,8,15,30,18,15};
    obj.DisplayHeap();
    return 0;
}
