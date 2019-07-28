#include <iostream>
#include <initializer_list>
#include <memory>
#include <stack>
#include <vector>

template<typename VALUE_TYPE>
class Bst
{
    public:
    Bst()=default;
    explicit Bst(const std::initializer_list<VALUE_TYPE>& lists);
    bool Insert(const VALUE_TYPE& value);
    bool Insert(const std::initializer_list<VALUE_TYPE>& lists);    
    std::vector<VALUE_TYPE> InOrder();
    inline size_t size()const {return counter_;}
    private:
    
    struct DataStore
    {
        explicit DataStore(const VALUE_TYPE& value):data{value}{}
        VALUE_TYPE data;
        std::shared_ptr<DataStore> left = nullptr;
        std::shared_ptr<DataStore> right = nullptr;        
    };
    
    using tDataStorePtr = std::shared_ptr<DataStore>;
    using tDataStoreConstPtr = const std::shared_ptr<DataStore>;
    
    tDataStorePtr CreateNode(const VALUE_TYPE& value)
    {
        return std::make_shared<DataStore>(value);
    }
    
    void GetLeafNode(tDataStoreConstPtr new_node);
    
    tDataStorePtr root_=nullptr;
    size_t counter_{0};    
};

template<typename VALUE_TYPE>
Bst<VALUE_TYPE>::Bst(const std::initializer_list<VALUE_TYPE>& lists)
{
    for(const auto& value : lists)
    {
        Insert(value);
    }
}

template<typename VALUE_TYPE>
bool Bst<VALUE_TYPE>::Insert(const std::initializer_list<VALUE_TYPE>& lists)
{
    int ret = false;
    for(const auto& value : lists)
    {
        ret = Insert(value);
    }
    return ret;
}


template<typename VALUE_TYPE>
bool Bst<VALUE_TYPE>::Insert(const VALUE_TYPE& value)
{
    tDataStorePtr data_ptr = CreateNode(value);
    bool ret =false;
    
    if(root_ == nullptr)
    {
      root_ =  data_ptr;
      ret = true;
    }
    else
    {
        GetLeafNode(data_ptr);
    }    
    counter_++;
    return ret;
}

/*template<typename VALUE_TYPE>
tDataStorePtr Bst<VALUE_TYPE>::CreateNode(const VALUE_TYPE& value)
{
    return std::make_shared<DataStore>(value);
}*/

template<typename VALUE_TYPE>
void Bst<VALUE_TYPE>::GetLeafNode(tDataStoreConstPtr new_node)
{
    tDataStorePtr index_ptr = root_;
    tDataStorePtr index_leaf=nullptr;
    
    while(index_ptr != nullptr)
    {
        index_leaf = index_ptr;
        if(index_ptr->data > new_node->data)
        {            
            index_ptr = index_ptr->left;
        }
        else
        {
            index_ptr = index_ptr->right;
        }
    }
    if(index_leaf != nullptr)
    {
        if(index_leaf->data > new_node->data)
        {               
            index_leaf->left = new_node;
        }
        else
        {            
            index_leaf->right = new_node;
        }
    }
}

template<typename VALUE_TYPE>
std::vector<VALUE_TYPE> Bst<VALUE_TYPE>::InOrder()
{
    tDataStorePtr index_ptr = root_;
    std::stack<tDataStorePtr> read_stack;
    std::vector<VALUE_TYPE> result;
    
    result.reserve(counter_);
    
    do{
        if(index_ptr != nullptr)
        {            
            read_stack.push(index_ptr);
            index_ptr = index_ptr->left;            
        }
        else
        {
            tDataStorePtr ptr = read_stack.top();
            read_stack.pop();
            result.push_back(ptr->data);
            index_ptr = ptr->right;
        }
    }while((!read_stack.empty()) || (index_ptr != nullptr));
    
    return result;
}

int main()
{
    Bst<int> data{5,7,8,2,3,34,2,5,9,23};
    
    std::cout<<data.size()<<std::endl;
    auto values = data.InOrder();
    
    
    for(auto& at : values)
    {
        std::cout<<at<<std::endl;
    }
    return 0;
}
