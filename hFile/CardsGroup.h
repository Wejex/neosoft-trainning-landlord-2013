/***********************************************************************
 * Module:  CardsGroup.h
 * Author:  Administrator
 * Modified: 2013年7月9日 10:21:32
 * Purpose: Declaration of the class CardsGroup
 ***********************************************************************/

#if !defined(__Landlords_CardsGroup_h)
#define __Landlords_CardsGroup_h

class Card;

#include <Card.h>

class CardsGroup
{
public:
   CardsGroup(int x, int y);//构造函数,(x,y)为牌组左上角坐标
   int GetX(void); //得到牌组的x坐标
   int GetY(void); //得到牌组的y坐标
   int GetSize(void); //得到牌组内牌的数量

   Card* GetCard(int index);//获得某个位置的牌

   void SelectCard(int x, int y);//是否选择到某个位置的牌（单击的时候选择）
   void SelectCard(int index); //是否选择到某个位置的牌
   void TakeSelectedCard(CardsGroup* cardsGroup);//从牌组里拿出一个牌组到另外一个牌组（出牌）
   void GetSelectedCard(CardsGroup* cardsGroup); //在牌组里面得到选择的牌，（出牌的时候判断牌型用到）
   void Push(Card* card);//将牌放入牌组
   void SetPos(int x, int y);//设置牌组的位置
   void Clean(void); //清空牌组
   void Paint(CDC* dc, int n, BOOL style); //画出牌组
   void SortODN(void); //降序排序
   void SortOUP(void);//升序排序

   Card** card;

protected:
private:
   int m_x; //x坐标
   int m_y;//y坐标
   vector< Card* > m_cards; //储存牌组里的牌


};

#endif