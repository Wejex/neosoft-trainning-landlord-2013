/***********************************************************************
 * Module:  Player.h
 * Author:  Administrator
 * Modified: 2013年7月10日 8:04:11
 * Purpose: Declaration of the class Player
 ***********************************************************************/

#if !defined(__Landlords_Player_h)
#define __Landlords_Player_h

class CardsGroup;

#include <CardsGroup.h>

class Player
{
public:
   //构造函数，分别是玩家名字，玩家的网络id，手牌，和已经出来的牌
   Player(char* name, int id, CardsGroup* handCards, CardsGroup* outCards);
   int GetID(void);//得到当前用户的网络ID
   CString GetName(void);//得到玩家的名字
   int GetBaseScore(void);// 得到底分
   int GetTimes(void);//得到倍数
   CardsGroup* GetHandCards(void);//得到在手上的牌
   CardsGroup* GetOutCards(void);//得到已经出的牌
   int GetTotalScore(void);//得到积分
   int GetGameScore(void);//得到当局的分数
   int CalculateScore(void);//游戏结束后清算玩家的积分
   BOOL SetLandlord(void);//叫分的时候设置地主
   BOOL GetIsLandlord(void); //判断自己是不是地主

protected:
private:
   CString m_name; //玩家名字
   int m_baseScore;//玩家的底分
   int m_times;//玩家的倍数
   int m_totalScore; //总的积分
   CardsGroup* m_handCards;//在手上的牌组
   CardsGroup* m_outCards;// 已经出的牌组
   int m_id;//玩家的网络id
   BOOL m_isLandlord; //记录玩家是否是地主


};

#endif