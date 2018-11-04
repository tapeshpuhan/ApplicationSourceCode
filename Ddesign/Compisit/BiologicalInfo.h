#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "FrameWorkComposit.hpp"
/*
 * Component class which is used as a interface to client
 * */
class BiologicalInfo
{
	public:
	virtual std::string Info()=0;
};
/*Leaf for Human
 * */
class Human : public BiologicalInfo
{
	std::string Info()override;
};

/*Leaf for Monkey
 * */
class Monkey : public BiologicalInfo
{
	std::string Info()override;
};

/*Leaf for Tiger
 * */
class Tiger : public BiologicalInfo
{
	std::string Info()override;
};

/*Leaf for dog
 * */
class dog : public BiologicalInfo
{
	std::string Info()override;
};

/*Leaf for pigeon
 * */
class pigeon : public BiologicalInfo
{
	std::string Info()override;
};
/*Leaf for dock
 * */
class duck : public BiologicalInfo
{
	std::string Info()override;
};

/*
 * A composite class for mammal group 
 * */
class Mammal : public CompositeFrame<BiologicalInfo>
{
	public:
	 
	 std::string Info()override;
};
/*
 * A composite class for animal group 
 * */
class Animal : public CompositeFrame<BiologicalInfo>
{
	public:
	 
	 std::string Info()override;
};
/*
 * A composite class for bird group 
 * */
class Bird : public CompositeFrame<BiologicalInfo>
{
	public:
	 
	 std::string Info()override;
};
