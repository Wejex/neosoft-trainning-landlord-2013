/***********************************************************************
 * Module:  Card.h
 * Author:  Administrator
 * Modified: 2013��7��9�� 10:10:51
 * Purpose: Declaration of the class Card
 ***********************************************************************/

#if !defined(__Landlords_Card_h)
#define __Landlords_Card_h

class Card
{
public:
   Card(int id); 
   Card(Card& card);
   ~Card();
   int GetValue(void);	//�õ��ƵĴ�С
   int GetColor(void);	//�õ��ƵĻ�ɫ
   int GetWidth(void); 	//�õ��ƵĿ��
   int GetHeight(void);	//�õ��Ƶĸ߶�
   int GetX(void); 	//�õ��Ƶ�x����
   int GetY(void); 	//�õ��Ƶ�y����
   BOOL IsSelected(void);	//���Ƿ�ѡ��
   void SetPos(int x, int y);	//�����Ƶ�λ��
   void SelectCard(BOOL isSelect);	//����ѡ��
   void SetPicture(char* pathName);	//����ͼƬ
   void Paint(CDC* dc);		//����滭	
   static bool IsLarger(Card& card1, Card& card2);	//card1�ǲ��Ǵ���card2
   static bool IsSmaller(Card& card1, Card& card2);	//card1�ǲ���С��card2
protected:
private:
   int m_x;	//x����
   int m_y;	//y����
   int m_width; 	//�����ƵĿ��
   int m_height; 	//�����Ƶĸ߶�
   BOOL m_isSelected;	//�������Ƿ�ѡ��
   int m_id;	//�����Ƶ�ID
   CBitmap m_picture; //ͼƬ


};

#endif