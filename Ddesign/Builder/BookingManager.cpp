#include "BookingManager.h"
 
void BookingMgr::setTicketInfo(const tBookType type, const tBookingInfo &info)
{
	switch(type)
	{
		case tBookType::SILVER:
		
		_bookTypes.insert({type,make_shared<SilverType>()});
		_bookTypes[type]->SetPriceInfo(info.price);
		_bookTypes[type]->SetFacilityInfo(info.facility);
		_bookTypes[type]->SetRowNumber(info.rownumber);		
		break;
		
		case tBookType::GOLD:
		_bookTypes.insert({type,make_shared<GoldType>()});
		_bookTypes[type]->SetPriceInfo(info.price);
		_bookTypes[type]->SetFacilityInfo(info.facility);
		_bookTypes[type]->SetRowNumber(info.rownumber);
		break;
		
		case tBookType::DIAMOND:
		
		_bookTypes.insert({type,make_shared<DiamondType>()});
		_bookTypes[type]->SetPriceInfo(info.price);
		_bookTypes[type]->SetFacilityInfo(info.facility);
		_bookTypes[type]->SetRowNumber(info.rownumber);
		break;
		
		default:
		//do nothing
			break;
	}
}


tBookingInfo BookingMgr::getTcketinfo(const tBookType type)
{
	return _bookTypes[type]->BookingInfo();
}
