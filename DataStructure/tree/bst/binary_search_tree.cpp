#include <iostream>
#include <memory>
#include <initializer_list>
#include <queue>
#include <stack>

template<typename Type>
class BinarySearchTree
{
    private:

        struct Node
        {
            std::shared_ptr<Node> left_child{nullptr};
            std::shared_ptr<Node> right_child{nullptr};
            Type data;
        };    
        
    public:
    using NodePtr = std::shared_ptr<Node>;
    
    BinarySearchTree(const std::initializer_list<Type>& list)
    {
        for(const auto& data : list)
        {
            insert(data);
        }
    }
        
    void insert(const Type& data)
    {
        if(root_node_ == nullptr)
        {
            root_node_= CreateNode(data);
        }
        else
        {
            NodePtr availabe_node = FindAvailabeNode(root_node_,data);
            if(nullptr != availabe_node)
            {
                if(availabe_node->data > data)
                {
                   availabe_node->left_child =  CreateNode(data);
                }
                else
                {
                    availabe_node->right_child =  CreateNode(data);
                }
            }
        }    
    }    
    void TreTraverseLabelOrder()
    {
        std::queue<NodePtr> buffer;
        
        if(nullptr != root_node_)
        {
            buffer.push(root_node_);
            while(!buffer.empty())
            {
                auto temp_node = buffer.front();
                buffer.pop();
                if(temp_node->left_child != nullptr)
                {
                    buffer.push(temp_node->left_child);
                }
                if(temp_node->right_child != nullptr)
                {
                    buffer.push(temp_node->right_child);
                }
                std::cout<<temp_node->data<<std::endl;
            }            
        }
    }
    
    void TreTraverseInOrder()
    {
        RecursiveInorder(root_node_);
        std::cout<<"iterative"<<std::endl;
        IterativeInorder(root_node_);
    }
    void TreTraversePreOrder()
    {
        //RecursivePreorder(root_node_);
        IterativePreorder(root_node_);
    }
    void TreTraversePostOrder()
    {
        RecursivePostorder(root_node_);
        std::cout<<"iterative"<<std::endl;
        IterativePostorder(root_node_);
    }
    void DeleteValue(const Type& data)
    {
        DeleteNode(root_node_,data);
    }
    ~BinarySearchTree()=default;
    
    private:
    
    void RecursivePreorder(const NodePtr node)
    {
        if(node != nullptr)
        {
            std::cout<<node->data<<std::endl;
            RecursivePreorder(node->left_child);
            RecursivePreorder(node->right_child);
        }
    }
    
    void IterativePreorder(const NodePtr node)
    {
        if(node != nullptr)
        {
            std::stack<NodePtr> buf;
            auto temp = node;
            while(temp != nullptr || !buf.empty())
            {
                std::cout<<temp->data<<std::endl;
                if(temp->right_child!=nullptr)
                {
                    buf.push(temp->right_child);
                }
                if(temp->left_child!=nullptr)
                {
                    buf.push(temp->left_child);
                }
                if(!buf.empty())
                {
                 temp = buf.top();
                 buf.pop();   
                }
                else
                {
                    temp = nullptr;
                }
            }
        }
    }
    
    void IterativeInorder(const NodePtr node)
    {
        if(node != nullptr)
        {
            std::stack<NodePtr> buf;
            auto temp = node;
            while(temp != nullptr || !buf.empty())
            {
                if(temp!=nullptr)
                {
                    buf.push(temp);
                    temp = temp->left_child;                    
                }
                else
                {
                    temp = buf.top();
                    buf.pop();
                    std::cout<<temp->data<<std::endl;
                    temp = temp->right_child;
                }                
            }
        }
    }
    
    void RecursiveInorder(const NodePtr node)
    {
        if(node != nullptr)
        {            
            RecursiveInorder(node->left_child);
            std::cout<<node->data<<std::endl;
            RecursiveInorder(node->right_child);
        }
    }
    
    void RecursivePostorder(const NodePtr node)
    {
        if(node != nullptr)
        {            
            RecursivePostorder(node->left_child);            
            RecursivePostorder(node->right_child);
            std::cout<<node->data<<std::endl;
        }
    }
    
    void IterativePostorder(const NodePtr node)
    {
        auto temp = node;
        std::stack<NodePtr> buff;
        NodePtr poped_ptr = nullptr;
        
        while(temp!=nullptr || !buff.empty())
        {
            if(temp != nullptr)
            {
                buff.push(temp);
                temp = temp->left_child;
            }
            else
            {
                auto top = buff.top();
                if(top->right_child != nullptr && top->right_child != poped_ptr)
                {
                    temp = top->right_child;
                }
                else
                {
                    std::cout<<top->data<<std::endl;
                    buff.pop();
                    poped_ptr = top;
                    if(!buff.empty() && poped_ptr != buff.top()->right_child)
                        temp = buff.top()->right_child;
                    else
                        temp = nullptr;
                }
            }
        }
    }
    
    NodePtr CreateNode(const Type& data)
    {
      NodePtr node = std::make_shared<Node>();
      node->data = data;
      return node;  
    }
    
    NodePtr FindAvailabeNode(const NodePtr root_node, const Type& data)
    {
        NodePtr temp_node = root_node;
        NodePtr availabe_node=nullptr;
        
        while(temp_node != nullptr)
        {
            availabe_node = temp_node;
            if(temp_node->data > data)
            {
                temp_node = temp_node->left_child;
            }
            else
            {
                temp_node = temp_node->right_child;
            }
        }
        return availabe_node;
    }
    
    NodePtr FindInoderSucessure(const NodePtr root_node)
    {
        NodePtr result =nullptr;
        NodePtr temp =root_node->right_child;
        
        while(temp->left_child!=nullptr)
        {
            result = temp;
            temp = temp->left_child;
        }
        return result;
        
    }
    
    void swap(const NodePtr node1, const NodePtr node2)
    {
        auto temp  = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
    // it is quite triky my help in had interviews 
    // http://www.algolist.net/Data_structures/Binary_search_tree/Removal
    
    void DeleteNode(const NodePtr root_node, const Type& data)
    {
        auto temp = root_node;
        NodePtr previous_node = nullptr;
        
        while(temp != nullptr)
        {
            if(temp->data == data)
            {
               if(temp->left_child == nullptr && temp->right_child == nullptr) // senario 1 - if node is leaf node
               {                   
                   if( previous_node!= nullptr)
                   {
                       if(previous_node->data < data)
                       {
                           previous_node->right_child = nullptr;
                       }
                       else
                       {
                           previous_node->left_child = nullptr;
                       }
                   }
                   else
                   {
                    root_node_ = nullptr;   
                   }
               }
               else if(temp->right_child == nullptr) // senario 2 - if no left child 
               {
                   if( previous_node!= nullptr)
                   {
                       if(previous_node->data < data)
                       {
                           previous_node->right_child = temp->left_child;
                       }
                       else
                       {
                           previous_node->left_child = temp->left_child;
                       }
                   }
                   else
                   {
                       root_node_ = temp->left_child;
                   }
               }
               else // scenario 3 : if both child availabe get the inorder sucessor and swap the elements
               {
                   auto sucessure = FindInoderSucessure(temp); // get the sucessor
                   if(sucessure != nullptr)// if left suceesor found
                   {
                       swap(temp,sucessure->left_child); //swap with the left child of sucessor
                       sucessure->left_child = sucessure->left_child->right_child;// delete the left child by replaceing its right child
                   }
                   else
                   {
                       swap(temp,temp->right_child); // in case succesotr not found replace its right child
                       temp->right_child = temp->right_child->right_child;
                   }
               }
               temp = nullptr; 
            }
            else if (temp->data < data)
            {
                previous_node = temp;
                temp = temp->right_child;   
            }
            else
            {
                previous_node = temp;
                temp = temp->left_child;  
            }
        }
    }
    
    NodePtr root_node_{nullptr};
    
};

int main()
{
    BinarySearchTree<int32_t> bst{15,10,17,8,12,14,11,30};
    //BinarySearchTree<char> bst{'F','B','G','I','H','A','D','C','E'};
    bst.TreTraverseLabelOrder();
    bst.DeleteValue(10);
    std::cout<<"delete"<<std::endl;
    bst.TreTraverseLabelOrder();
    return 0;
}
