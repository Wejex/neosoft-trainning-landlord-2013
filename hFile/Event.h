/***********************************************************************
 * Module:  Event.h
 * Author:  Administrator
 * Modified: 2013��7��9�� 12:56:19
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
   void Paint(CDC* dc);         //��ͼ
   void AddButton(Button* button);//���button
   Button* ButtonAt(void);      //�����ĳ��λ�õ�button
   void OnClick(int x, int y); //����ĳ����ť�������¼�
   int GetID(void); //�õ����¼���ID
   void DoWork(void); //�¼���ĳЩ����

protected:
private:
   int m_id;	//��ǰ�¼���id
   vector<Button*> buttons; //����İ�ť
   CGameDlg* dlg; //��Ϸ��dlg


};

#endif