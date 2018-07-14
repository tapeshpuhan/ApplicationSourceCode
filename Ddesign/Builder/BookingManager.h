#ifndef TichetBookmgr_H_
#define TichetBookmgr_H_

 #include "TicketBooking.h"
 #include <map>
 class BookingMgr
 {
	 std::map<tBookType,shared_ptr<BookingType>> _bookTypes;
	public:
	 BookingMgr(){}
	 void setTicketInfo(const tBookType type, const tBookingInfo &info);
	 tBookingInfo getTcketinfo(const tBookType type);
 };
#endif
