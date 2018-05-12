/*
 * Fixed_Array.cpp

 *
 *  Created on: 24-Mar-2018
 *      Author: tapesh
 */
#if 0
#include<iostream>
#include<string>
#include<algorithm>
#include<initializer_list>

using namespace std;

template<typename T, size_t size>
class fixed_array
{
private:
	T array[size];
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	fixed_array(){}
	fixed_array(const initializer_list<T> &data){
		/*size_t i = 0;
		for(auto &at: data)
		{

			//i<size ? (array[i++] = at):;
			if(i<size)
			{
				array[i++] = at;
			}
		}*/
		cout<<"fixed_array initializer_list"<<endl;
		copy(data.begin(),data.end(),begin());
	}
	template<typename T1, size_t osize>
	fixed_array(const fixed_array &rh){
		cout<<"temp fixed_array = the value insted of copy"<<endl;
		copy(rh.begin(),rh.begin()+min(size,osize),begin());
	}


	template<typename T1, size_t osize>
	fixed_array& operator = (const fixed_array &rh){
		cout<<"temp operator = the value insted of copy"<<endl;
		copy(rh.begin(),rh.begin()+min(size,osize),begin());
		return *this;
	}
	template<typename T1, size_t osize>
	fixed_array(const fixed_array &&rh){
		cout<<"Move the value insted of copy"<<endl;
		begin()=rh.begin();
		rh.begin() = nullptr;
	}
	template<typename T1, size_t osize>
	fixed_array& operator = (const fixed_array &&rh){
		cout<<"temp move fixed_array = the value insted of copy"<<endl;
		begin()=rh.begin();
		rh.begin() = nullptr;
		return *this;
	}


	/*Copy Constructor*/

	fixed_array(const fixed_array &rh){
		cout<<" fixed_array = the value insted of copy"<<endl;
		copy(rh.begin(),rh.end(),begin());
	}



	fixed_array& operator = (const fixed_array &rh){
		cout<<" operator = the value insted of copy"<<endl;
		copy(rh.begin(),rh.end(),begin());
		return *this;
	}


	fixed_array(const fixed_array &&rh){
		cout<<"Move the value insted of copy"<<endl;
		copy(rh.begin(),rh.end(),begin());
		//begin()=rh.begin();
		//rh.begin() = nullptr;
	}

	fixed_array& operator = (const fixed_array &&rh){
		cout<<" move fixed_array = the value insted of copy"<<endl;
		begin()=rh.begin();
		rh.begin() = nullptr;
		return *this;
	}


	iterator begin(){return array;}
	iterator end(){return array+(size);}
	const_iterator begin()const {return array;}
	const_iterator end()const {return array+(size);}
	void display()
	{
		for(auto &at: array)
		{
			cout<<at<<endl;
		}
	}
};

int main()
{
	fixed_array<int, 4> v = {1,2,3,4,5};
	fixed_array<int, 4> v2(move(v));

	v2.display();
	return 0;
}
#endif
