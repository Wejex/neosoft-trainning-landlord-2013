/***********************************************************************
 * Module:  Button.h
 * Author:  Administrator
 * Modified: 2013年7月9日 10:16:38
 * Purpose: Declaration of the class Button
 ***********************************************************************/

#if !defined(__Landlords_Button_h)
#define __Landlords_Button_h

class Button
{
public:
   Button();
   BOOL IsContain(int x, int y); //坐标是否在button上
   BOOL IsDisable(void); //button是否激活
   void SetRect(CRect& rect); //设置button所在区域
   void SetPicture(char* path); //设置button的图片
   void Paint(CDC* dc);  //画出button
   void DoWork(void); // button发生事件
   void SetDisable(BOOL isDisable); //设置button的可用性

protected:
private:
   CRect m_rect;  //设置button的位置
   CBitmap m_pircture; //图片
   BOOL m_isDisable; //button是否激活


};

#endif