/***********************************************************************
 * Module:  CardsHandle.h
 * Author:  Administrator
 * Modified: 2013年7月9日 10:28:08
 * Purpose: Declaration of the class CardsHandle
 ***********************************************************************/

#if !defined(__Landlords_CardsHandle_h)
#define __Landlords_CardsHandle_h

#include <CardsGroup.h>

class CardsHandle
{
public:
   CardsHandle();
   BOOL IsLegal(CardsGroup cards1, CardsGroup cards2);	//出牌是不是合法，cards1是上家出的牌，cards2是当前出的牌
   CardsGroup* MakeCardsGroup(int* cardsID);	//制造牌组

protected:
private:

};

#endif