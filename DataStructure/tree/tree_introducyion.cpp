#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stack>

  
  void print(const std::string& str)
  {
      std::cout<<str<<std::endl;
  }  
    struct Node
    {
        std::string value;
        std::vector<std::shared_ptr<Node>> child;        
    };
    
    using tNode = std::shared_ptr<Node>;

class TreeSample
{
    public:
    explicit TreeSample(const std::string& root)
    {
        InsertRootNode(root);
    }

    
    bool InsertNode(const std::string& node_child,const std::string& node_root);
    std::vector<std::string> GetNode(const std::string& node_value);
    
    void DisplayTree(const std::string& node);
    private:
    
    tNode root_node;
    
    void InsertRootNode(const std::string& root);
    tNode CreateNode(const std::string& data);
    std::pair<bool,tNode> SearchParent(const std::string& data);
    std::pair<bool,tNode> SerchSubTree(const tNode node, const std::string& data);
};

std::vector<std::string> TreeSample::GetNode(const std::string& node_value)
{
    std::vector<std::string> return_value;
    
    //print("GetNode" + node);
    auto index = SerchSubTree(root_node, node_value);
    
    if(index.first == true)
    {
        for(auto& child : index.second->child)
        {
            return_value.push_back(child->value);
        }
    }
    return return_value;
}

void TreeSample::DisplayTree(const std::string& node)
{    
    
    auto index = SerchSubTree(root_node, node);
    
    
    if(index.first == true)
    {
        for(auto& child : index.second->child)
        {
            DisplayTree(child->value);
        }
    }   
}

void TreeSample::InsertRootNode(const std::string& root)
{
    root_node = std::make_shared<Node>();
    root_node->value = root;
}

bool TreeSample::InsertNode(const std::string& node_child,const std::string& node_root)
{
    bool parent_found = false;
    
    if(nullptr != root_node)
    {
        if(root_node->value == node_root)
        {
            root_node->child.push_back( CreateNode(node_child));
            parent_found = true;
        }
        else
        {
            auto index = SearchParent(node_root);
            if(index.first == true)
            {
               index.second->child.push_back(CreateNode(node_child));
            }
        }
    }
}

std::pair<bool,tNode> TreeSample::SearchParent(const std::string& data)
{
   return SerchSubTree(root_node, data);   
}

tNode TreeSample::CreateNode(const std::string& data)
{
    tNode node = std::make_shared<Node>();
    
    node->value = data;
    return node;
}

std::pair<bool,tNode> TreeSample::SerchSubTree(const tNode node, const std::string& data)
{
    std::stack<tNode> store;
    bool found = false;
    tNode parent;
    
    store.push(node);
    
    while(!store.empty())
    {

       if(store.top()->value == data)
       {           
             found = true;
             parent = store.top();
             break;   
        }
        if(store.top()->child.size())
        {
            auto temp = store.top();
            store.pop();
            for(auto& child: temp->child)
            {
                store.push(child);
            }
        }
        else
        {
            store.pop();
        }
    }
    return std::make_pair(found,parent);
}

int main()
{
    TreeSample obj{"/"};
    
    
    obj.InsertNode("dir1","/");
    obj.InsertNode("dir2","/");
    obj.InsertNode("dir3","/");
    obj.InsertNode("dir4","/");
    obj.InsertNode("dir5","dir2");
    obj.InsertNode("dir6","dir2");

    auto res = obj.GetNode("dir2");
    for(auto& at : res)
    {
        //std::cout<<at<<std::endl;
    }
        std::cout<<" print "<<std::endl;
    obj.DisplayTree("dir8");
    return 0;
}
