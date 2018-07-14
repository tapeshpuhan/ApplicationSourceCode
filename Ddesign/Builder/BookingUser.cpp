#include "BookingManager.h"
#include "BookingConfig.h"

int main()
{
	//std::unique_ptr<BookingMgr> Mgr = std::unique_ptr<BookingMgr>();
	std::unique_ptr<BookingMgr> Mgr (new BookingMgr());
	tBookingInfo info, outInfo;
	
	info.price = GoldPrice;
	info.facility = GoldFacility;
	info.rownumber = GoldRowNumber;
	
	Mgr->setTicketInfo(tBookType::GOLD, info);
	
	outInfo = Mgr->getTcketinfo(tBookType::GOLD);
	
	std::cout<<" Price :: "<<outInfo.price<<endl
			 <<" Facility :: "<<outInfo.facility<<endl
			 <<" Row Number :: "<<outInfo.rownumber<<endl;
	return 0;
}
