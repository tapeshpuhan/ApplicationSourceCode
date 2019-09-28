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
    }
    void TreTraversePreOrder()
    {
        RecursivePreorder(root_node_);        
    }
    void TreTraversePostOrder()
    {
        RecursivePostorder(root_node_);
        std::cout<<"iterative"<<std::endl;
        IterativePostorder(root_node_);
    }
    
    std::vector<Type> FindSwapedElement()
    {
        auto temp = root_node_;
        std::vector<Type> swaped_element;
        std::stack<NodePtr> buff;
        bool read_root{false};
        
        while(temp!=nullptr || !buff.empty())
        {
            if(temp)
            {
                buff.push(temp);
                temp = temp->left_child;
            }
            else
            {
                auto top = buff.top();
                std::cout<<top->data<<" "<<std::endl;
                if(top->data == root_node_->data)
                {
                    read_root = true;
                }
                if(!read_root)
                {
                    
                }
                temp = top->right_child; 
                buff.pop();
            }
        }
        return swaped_element;
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
        NodePtr history = nullptr;
        
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
                if(top->right_child != nullptr && top->right_child != history)
                {
                    temp = top->right_child;
                }
                else
                {
                    history =top;
                    std::cout<<top->data<<std::endl;
                    buff.pop();
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
    
    NodePtr root_node_{nullptr};
    
};

int main()
{
    BinarySearchTree<int32_t> bst{15,10,17,8,12,14,11,30};
    //BinarySearchTree<char> bst{'F','B','G','I','H','A','D','C','E'};
    bst.FindSwapedElement();

    return 0;
}
