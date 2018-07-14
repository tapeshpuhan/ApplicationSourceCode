#include "TicketBooking.h"

using namespace std;

void SilverType::SetRowNumber(const string &row)
{
	cout<<"Silver type Booking Row number starts from "<<row<<endl;
	_BookingInfo.rownumber = row;
}


void SilverType::SetPriceInfo(const string &price)
{
	cout<<"Silver type Booking price Is Range from "<<price<<endl;
	_BookingInfo.price = price;
}

void SilverType::SetFacilityInfo(const string &fac)
{
	cout<<"Silver type Booking facility info "<<fac<<endl;
	_BookingInfo.facility = fac;
}
tBookingInfo SilverType::BookingInfo()
{
	cout<<"silver type booking info "<<endl;
	return _BookingInfo;
}

// for Gold

void GoldType::SetRowNumber(const string &row)
{
	cout<<"GoldType type Booking Row number starts from "<<row<<endl;
	_BookingInfo.rownumber = row;
}


void GoldType::SetPriceInfo(const string &price)
{
	cout<<"GoldType type Booking price Is Range from "<<price<<endl;
	_BookingInfo.price = price;
}

void GoldType::SetFacilityInfo(const string &fac)
{
	cout<<"GoldType type Booking facility info "<<fac<<endl;
	_BookingInfo.facility = fac;
}
tBookingInfo GoldType::BookingInfo()
{
	cout<<"GoldType type booking info "<<endl;
	return _BookingInfo;
}

// Diamond type booking 
void DiamondType::SetRowNumber(const string &row)
{
	cout<<"GoldType type Booking Row number starts from "<<row<<endl;
	_BookingInfo.rownumber = row;
}


void DiamondType::SetPriceInfo(const string &price)
{
	cout<<"GoldType type Booking price Is Range from "<<price<<endl;
	_BookingInfo.price = price;
}

void DiamondType::SetFacilityInfo(const string &fac)
{
	cout<<"GoldType type Booking facility info "<<fac<<endl;
	_BookingInfo.facility = fac;
}
tBookingInfo DiamondType::BookingInfo()
{
	cout<<"DiamondType type booking info "<<endl;
	return _BookingInfo;
}


