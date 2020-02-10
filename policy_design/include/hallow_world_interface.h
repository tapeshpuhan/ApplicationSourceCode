#ifndef HALLOW_WORLD_INTERFACE
#define HALLOW_WORLD_INTERFACE

template<typename OutputPolicy, typename LanguagePolicy>
class HallowWorld : public OutputPolicy, public LanguagePolicy
{
	public:
	
	void Run()
	{
		Print(Message());
	}
	
	private:
	using OutputPolicy::Print;
	using LanguagePolicy::Message;
};

#endif //HALLOW_WORLD_INTERFACE
