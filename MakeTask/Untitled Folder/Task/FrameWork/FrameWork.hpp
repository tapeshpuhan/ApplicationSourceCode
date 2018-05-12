/*
 * FrameWork.hpp
 * This class Provide Support to other classes
 *  Created on: 04-Mar-2018
 *      Author: tapesh
 */

#include "../BaseType.h"
#include "memory"
using namespace std;

/*
 * Singletone template class to make
 * Required method to create assesses by single instance
 */
template<typename C>
class Singletone
{
private:
	/*
	 * declare default copy constructor and assignemt
	 * operator.
	 */
	Singletone(const Singletone<C> &);
	Singletone<C>& operator=(const Singletone<C> &);
	static std::shared_ptr<C> _instance;

protected:
	Singletone(){}
public:
	static shared_ptr<C> & Instance()
	{
		if(_instance==nullptr)
		{
			//allocate memory
			_instance = std::make_shared<C>();
		}
		return _instance;
	}
	virtual ~Singletone()
	{
		//Deallocate memory
		_instance.reset();
	}
};
//Definition of instance
template<typename C> shared_ptr<C> Singletone<C>::_instance = nullptr;

/*
 * Created Generic MsgQueue to communicate msg beetween two threads
 */
template<class msg>
class MsgQueue : public Singletone<MsgQueue<msg>>
{
private:
	std::deque<msg> qInfo;
	mutable std::mutex mut;

public:
	//push data into queue
	void push(const msg &data)
	{
		try
		{
#if Debug
			cout<<"MsgQueue Push"<<endl;
#endif
			std::lock_guard<std::mutex> lk(mut);
			qInfo.push_back(data);

		}
		catch(...)
		{
			std::cout<<"ERROR: Queue Push Error cached"<<std::endl;
		}
	}
	//Pop into Queue
	std::pair<bool,msg> pop()
	{
		try
		{
#if Debug
			cout<<"MsgQueue Pop"<<endl;
#endif
			std::lock_guard<std::mutex> lk(mut);
			msg ms;
			if(qInfo.empty())
			{
				std::cout<<"INFO: List is empty"<<std::endl;
				//return a dummy  pointer instead off null
				static msg ms;
				return pair<bool,msg>(false,ms);
			}
			ms = qInfo.front();
			qInfo.pop_front();
			return std::move(pair<bool,msg>(true,ms));
		}
		catch(...)
		{
			std::cout<<"ERROR: Queue Pop Error cached"<<std::endl;
			static msg ms;
			return pair<bool,msg>(false,ms);
		}
	}

};

struct FilePos:public Singletone<FilePos>
{
	void setFilepos(std::string file, u32Int pos)
	{
		std::lock_guard<std::mutex> lk(mut);
		mFilePos[file] = pos;
	}
	u32Int getFilepos(std::string file)
	{
		std::lock_guard<std::mutex> lk(mut);
		return mFilePos[file];
	}
private:
	std::map<string,u32Int> mFilePos;
	mutable std::mutex mut;
};
/*
 * Created MUtex and Conditional variable
 * to synchronize between threads
 */
struct Mutex:public Singletone<Mutex>
{
	std::mutex _mutex;
	std::condition_variable _cond;
};

/*
 * A util class which can perform common operations
 * Across
 */
struct Utils:public Singletone<Utils>
{
	/*
	 * getToken method to get vector of string from the line
	 * separated by delimiter
	 * in case of error it will update empty vector
	 */
	void getToken(const std::string &sStr,const std::string &del,
			std::vector<string> &oInfo)
	{
		oInfo.clear();//clear the output vector
		if(!sStr.empty())//check String is not empty
		{
			//get first position of the input string  is not a delimiter
			std::string::size_type fPos = sStr.find_first_not_of(del,0);
			//get position of the delimiter
			std::string::size_type nPos = sStr.find_first_of(del,fPos);

			while((fPos != std::string::npos) || (nPos != std::string::npos))
			{
				//get the token from the string and push into vector
				oInfo.push_back(sStr.substr(fPos,nPos-fPos));
				//Continue the loop by finding next position of delimiter
				fPos = sStr.find_first_not_of(del,nPos);
				nPos = sStr.find_first_of(del,fPos);
			}
		}
	}

	//A function which will check the input string is
	// is floating point
	bool is_double(std::string str)
	{
		unsigned int f_c=0;
		unsigned int l_c = 0;
		bool ret = false;
		if(str.length())
		{
			for(std::string::const_iterator it = str.begin(); it!=str.end();it++)
			{
				if(!std::isdigit(*it) && !isspace(*it))
				{
					if((*it=='+')&&(*it=='-')&&l_c==0)
					{
						//donothing
					}
					else
					{
						if(*it == '.'&&f_c==0)
						{
							f_c++;
						}
						else
						{
							return false;
						}
					}
				}
				l_c++;
			}
			ret = true;
		}
		return ret;
	}
};
