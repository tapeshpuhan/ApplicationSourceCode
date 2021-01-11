#include <iostream>
#include <memory>
#include <initializer_list>

template<typename TYPE>
struct Tree
{
	private:
	
	struct Node
	{
		Node(const TYPE& value_p):value{value_p},left{nullptr},right{nullptr}{}
		
		TYPE value;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
	};
	
	using NodePtr = std::shared_ptr<Node>;
	
	NodePtr root=nullptr;
	
	NodePtr GetDataPtr(const TYPE& value)
	{
		return std::make_shared<Node>(value);
	}
	
	public:
	
	Tree(const std::initializer_list<TYPE>& value_list)
	{
		for(const auto& data : value_list)
			insert(data);
	}
	
	void insert(const TYPE& data)
	{
		if(root == nullptr)
		{
			root = GetDataPtr(data);
		}
		else
		{
			auto temp = root;
			auto pre = temp;
			
			while(temp!=nullptr)
			{
				pre = temp;
				
				if(data < temp->value)
					temp = temp->left;
				else
					temp = temp->right;
			}
			if(data < pre->value)
				pre->left =  GetDataPtr(data);
			else
				pre->right =  GetDataPtr(data);
		}
	}
	
	void Print()
	{
		Print(root);
	}
	void Print(NodePtr root)
	{
		if(root == nullptr)
			return;
		std::cout<<root->value<<std::endl;
		Print(root->left);
		Print(root->right);
	}
	
	int Hight()
	{
		return Hight(root);
	}
	
	int Hight(NodePtr root)
	{
		if(root == nullptr)
		{
			return 0;
		}
		auto nl = Hight(root->left);
		auto nr = Hight(root->right);
		
		return 1 + std::max(nl,nr);
	}
};

int main()
{
	Tree<int> tree{100,34,56,4,156};
	tree.Print();
	
	std::cout<<"Hight is "<<tree.Hight()<<std::endl;
	return 0;
}
