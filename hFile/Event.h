/***********************************************************************
 * Module:  Event.h
 * Author:  Administrator
 * Modified: 2013年7月9日 12:56:19
 * Purpose: Declaration of the class Event
 ***********************************************************************/

#if !defined(__Landlords_Event_h)
#define __Landlords_Event_h

class Button;

#include "CGameDlg.h"
#include "Button.h"

class Event
{
public:
   Event(int id, CGameDlg* dlg);
   void Paint(CDC* dc);         //画图
   void AddButton(Button* button);//添加button
   Button* ButtonAt(void);      //获得在某个位置的button
   void OnClick(int x, int y); //单击某个按钮产生的事件
   int GetID(void); //得到本事件的ID
   void DoWork(void); //事件的某些工作

protected:
private:
   int m_id;	//当前事件的id
   vector<Button*> buttons; //储存的按钮
   CGameDlg* dlg; //游戏的dlg


};

#endif