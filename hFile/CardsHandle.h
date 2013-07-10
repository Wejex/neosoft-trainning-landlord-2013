/***********************************************************************
 * Module:  CardsHandle.h
 * Author:  Administrator
 * Modified: 2013��7��9�� 10:28:08
 * Purpose: Declaration of the class CardsHandle
 ***********************************************************************/

#if !defined(__Landlords_CardsHandle_h)
#define __Landlords_CardsHandle_h

#include <CardsGroup.h>

class CardsHandle
{
public:
   CardsHandle();
   BOOL IsLegal(CardsGroup cards1, CardsGroup cards2);	//�����ǲ��ǺϷ���cards1���ϼҳ����ƣ�cards2�ǵ�ǰ������
   CardsGroup* MakeCardsGroup(int* cardsID);	//��������

protected:
private:

};

#endif