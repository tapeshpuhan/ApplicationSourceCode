#ifndef TichetBooking_H_
#define TichetBooking_H_

#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

enum class  tBookType
{
	SILVER,
	GOLD,
	DIAMOND
};

/*
 * This Application is part of 
 * sevice Provider .
 * As per modularity purpose can be put in separate 
 * file abd the Director object can be acess 
 * by client software
 * */
struct tBookingInfo
{
	string price;
	string facility;
	string rownumber;
};

//Interface Class for Building a Booking type
class BookingType
{
	
	public:
	//Interface to set Price Information
	virtual void SetPriceInfo(const string &price){}
	//Interface to set Facility Information
	virtual void SetFacilityInfo(const string &fac){}
	//Interface to set Row  Information
	virtual void SetRowNumber(const string &row){}
	//Interface to set Price Information
	virtual tBookingInfo BookingInfo()=0;
	virtual ~BookingType(){};
	
	protected:
	BookingType(){}
	tBookingInfo _BookingInfo;
};

//Concrite class for booking type

class SilverType : public BookingType
{
	public:
	 void SetPriceInfo(const string &price);
	 void SetFacilityInfo(const string &fac) ;
	 void SetRowNumber(const string &row) ;
	 tBookingInfo BookingInfo() override;
};


class GoldType : public BookingType
{
	public:
	 void SetPriceInfo(const string &price);
	 void SetFacilityInfo(const string &fac) ;
	 void SetRowNumber(const string &row) ;
	 tBookingInfo BookingInfo() override;
};


class DiamondType : public BookingType
{
	public:
	 void SetPriceInfo(const string &price);
	 void SetFacilityInfo(const string &fac) ;
	 void SetRowNumber(const string &row) ;
	 tBookingInfo BookingInfo() override;
};
/*
 * Booking manager is the interface availabe to 
 * client sofware , which is the director of booking design
 * pattern
 * */
#endif
