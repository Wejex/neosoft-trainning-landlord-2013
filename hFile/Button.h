/***********************************************************************
 * Module:  Button.h
 * Author:  Administrator
 * Modified: 2013��7��9�� 10:16:38
 * Purpose: Declaration of the class Button
 ***********************************************************************/

#if !defined(__Landlords_Button_h)
#define __Landlords_Button_h

class Button
{
public:
   Button();
   BOOL IsContain(int x, int y); //�����Ƿ���button��
   BOOL IsDisable(void); //button�Ƿ񼤻�
   void SetRect(CRect& rect); //����button��������
   void SetPicture(char* path); //����button��ͼƬ
   void Paint(CDC* dc);  //����button
   void DoWork(void); // button�����¼�
   void SetDisable(BOOL isDisable); //����button�Ŀ�����

protected:
private:
   CRect m_rect;  //����button��λ��
   CBitmap m_pircture; //ͼƬ
   BOOL m_isDisable; //button�Ƿ񼤻�


};

#endif