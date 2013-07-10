/***********************************************************************
 * Module:  Player.h
 * Author:  Administrator
 * Modified: 2013��7��10�� 8:04:11
 * Purpose: Declaration of the class Player
 ***********************************************************************/

#if !defined(__Landlords_Player_h)
#define __Landlords_Player_h

class CardsGroup;

#include <CardsGroup.h>

class Player
{
public:
   //���캯�����ֱ���������֣���ҵ�����id�����ƣ����Ѿ���������
   Player(char* name, int id, CardsGroup* handCards, CardsGroup* outCards);
   int GetID(void);//�õ���ǰ�û�������ID
   CString GetName(void);//�õ���ҵ�����
   int GetBaseScore(void);// �õ��׷�
   int GetTimes(void);//�õ�����
   CardsGroup* GetHandCards(void);//�õ������ϵ���
   CardsGroup* GetOutCards(void);//�õ��Ѿ�������
   int GetTotalScore(void);//�õ�����
   int GetGameScore(void);//�õ����ֵķ���
   int CalculateScore(void);//��Ϸ������������ҵĻ���
   BOOL SetLandlord(void);//�зֵ�ʱ�����õ���
   BOOL GetIsLandlord(void); //�ж��Լ��ǲ��ǵ���

protected:
private:
   CString m_name; //�������
   int m_baseScore;//��ҵĵ׷�
   int m_times;//��ҵı���
   int m_totalScore; //�ܵĻ���
   CardsGroup* m_handCards;//�����ϵ�����
   CardsGroup* m_outCards;// �Ѿ���������
   int m_id;//��ҵ�����id
   BOOL m_isLandlord; //��¼����Ƿ��ǵ���


};

#endif