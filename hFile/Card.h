/***********************************************************************
 * Module:  Card.h
 * Author:  Administrator
 * Modified: 2013年7月9日 10:10:51
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
   int GetValue(void);	//得到牌的大小
   int GetColor(void);	//得到牌的花色
   int GetWidth(void); 	//得到牌的宽度
   int GetHeight(void);	//得到牌的高度
   int GetX(void); 	//得到牌的x坐标
   int GetY(void); 	//得到牌的y坐标
   BOOL IsSelected(void);	//牌是否被选中
   void SetPos(int x, int y);	//设置牌的位置
   void SelectCard(BOOL isSelect);	//用来选牌
   void SetPicture(char* pathName);	//导入图片
   void Paint(CDC* dc);		//界面绘画	
   static bool IsLarger(Card& card1, Card& card2);	//card1是不是大于card2
   static bool IsSmaller(Card& card1, Card& card2);	//card1是不是小于card2
protected:
private:
   int m_x;	//x坐标
   int m_y;	//y坐标
   int m_width; 	//定义牌的宽度
   int m_height; 	//定义牌的高度
   BOOL m_isSelected;	//定义牌是否被选中
   int m_id;	//定义牌的ID
   CBitmap m_picture; //图片


};

#endif