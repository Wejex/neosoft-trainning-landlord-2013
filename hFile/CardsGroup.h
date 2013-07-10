/***********************************************************************
 * Module:  CardsGroup.h
 * Author:  Administrator
 * Modified: 2013��7��9�� 10:21:32
 * Purpose: Declaration of the class CardsGroup
 ***********************************************************************/

#if !defined(__Landlords_CardsGroup_h)
#define __Landlords_CardsGroup_h

class Card;

#include <Card.h>

class CardsGroup
{
public:
   CardsGroup(int x, int y);//���캯��,(x,y)Ϊ�������Ͻ�����
   int GetX(void); //�õ������x����
   int GetY(void); //�õ������y����
   int GetSize(void); //�õ��������Ƶ�����

   Card* GetCard(int index);//���ĳ��λ�õ���

   void SelectCard(int x, int y);//�Ƿ�ѡ��ĳ��λ�õ��ƣ�������ʱ��ѡ��
   void SelectCard(int index); //�Ƿ�ѡ��ĳ��λ�õ���
   void TakeSelectedCard(CardsGroup* cardsGroup);//���������ó�һ�����鵽����һ�����飨���ƣ�
   void GetSelectedCard(CardsGroup* cardsGroup); //����������õ�ѡ����ƣ������Ƶ�ʱ���ж������õ���
   void Push(Card* card);//���Ʒ�������
   void SetPos(int x, int y);//���������λ��
   void Clean(void); //�������
   void Paint(CDC* dc, int n, BOOL style); //��������
   void SortODN(void); //��������
   void SortOUP(void);//��������

   Card** card;

protected:
private:
   int m_x; //x����
   int m_y;//y����
   vector< Card* > m_cards; //�������������


};

#endif