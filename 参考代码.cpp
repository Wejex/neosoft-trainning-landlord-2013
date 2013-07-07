
//从位图载入到表面的代码;

/*
	if (!pMy_Draw->Load_Bitmap_File(&pMy_Draw->bitmap,"desk.bmp"))
	{
	    return(0);
	}
// lock the surface
	lpddsbackground->Lock(NULL,&pMy_Draw->ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT,NULL);

// get video pointer to primary surfce
	       
	DWORD *image_buffer = (DWORD *)pMy_Draw->ddsd.lpSurface;
// process each line and copy it into the primary buffer
	for (int index_y = 0; index_y < Screen_Height; index_y++)
    {
		for (int index_x = 0; index_x < Screen_Width; index_x++)
        {
        // get BGR values
        UCHAR blue  = (pMy_Draw->bitmap.buffer[index_y*Screen_Width*3 + index_x*3 + 0]),
              green = (pMy_Draw->bitmap.buffer[index_y*Screen_Width*3 + index_x*3 + 1]),
              red   = (pMy_Draw->bitmap.buffer[index_y*Screen_Width*3 + index_x*3 + 2]);

        // this builds a 32 bit color value in A.8.8.8 format (8-bit alpha mode)
        DWORD pixel = _RGB32BIT(0,red,green,blue);

        // write the pixel
        image_buffer[index_x + (index_y*pMy_Draw->ddsd.lPitch >> 2)] = pixel;

        } // end for index_x

    } // end for index_y

// now unlock the primary surface
	if (FAILED(lpddsbackground->Unlock(NULL)))
	{
		return(0);
	}

// unload the bitmap file, we no longer need it
	pMy_Draw->Unload_Bitmap_File(&pMy_Draw->bitmap);
*/
///////////////////////////////////////////////////////////////////////////////////

//渲染一个表面!COOL!

/*  渲染的例子;可以改变画像颜色;
DDRAW_INIT_STRUCT(ddsd); 

// lock the primary surface
if (FAILED(lpddsbackground->Lock(NULL, &ddsd,
                    DDLOCK_WAIT,
                   NULL)))
   return(0);


int lpitch32 = (int)(ddsd.lPitch >> 2);
UINT *video_buffer = (UINT *)ddsd.lpSurface;


	for (int index_y = 0; index_y < SCREEN_HEIGHT; index_y++)
    {
		for (int index_x = 0; index_x < SCREEN_WIDTH; index_x++)
        {
        // get BGR values
//        UCHAR blue  = (UCHAR)(video_buffer[index_x + (index_y*ddsd.lPitch >> 2)]) ,
//              green = (UCHAR)(video_buffer[index_x + (index_y*ddsd.lPitch >> 2)] >> 8),
//              red   = (UCHAR)(video_buffer[index_x + (index_y*ddsd.lPitch >> 2)] >> 16);

        // this builds a 32 bit color value in A.8.8.8 format (8-bit alpha mode)

//		green+=40;
//		blue-=30;


//        DWORD pixel = _RGB32BIT(0,red,green,blue);

        // write the pixel
//        video_buffer[index_x + (index_y*ddsd.lPitch >> 2)] = pixel;

		video_buffer[index_x + (index_y*ddsd.lPitch >> 2)] += 0x3000;

        } // end for index_x

    } // end for index_y      


if (FAILED(lpddsbackground->Unlock(NULL)))
   return(0);
*/


//	char buffer[256];   //记录键盘的缓冲区;	
//	HRESULT result = pDI_Keyborad->GetDeviceState(sizeof(buffer),(LPVOID)&buffer);  
//    if(result != DI_OK)
//	{
//		AfxMessageBox("取得键盘状态失败!");
//	}

///////////////////////////////////////////////////////////

//牌的布局代码;

/*
//中间的牌;
	if(person.counter < 20)
	{
//中间已出的牌;
	DDraw_Draw_Surface(person.frames[0], 
                       centerx1, centery1,
                       person.width,person.height,
                       lpddsback);
//中间没出的牌;
	if(counter%3 == 0)
	{
	DDraw_Draw_Surface(person.frames[0], 
                       centerx, centery-20,
                       person.width,person.height,
                       lpddsback);
	}
	else
	{
	DDraw_Draw_Surface(person.frames[0], 
                       centerx, centery,
                       person.width,person.height,
                       lpddsback);
	}

	centerx+=22;
	centerx1+=16;

	person.counter++;

	}
//左边的牌;
	if(counter < 20 )
	{
	DDraw_Draw_Surface(person.frames[1], 
                       leftx, lefty,
                       person.width,person.height,
                       lpddsback);
//左边已出的牌;
	DDraw_Draw_Surface(person.frames[0], 
                       leftx1, lefty1,
                       person.width,person.height,
                       lpddsback);

	lefty+=16;
	lefty1+=16;	
	}
//右边的牌;
	if(counter < 20 )
	{
		DDraw_Draw_Surface(person.frames[1], 
                       rightx, righty,
                       person.width,person.height,
                       lpddsback);
//已
		DDraw_Draw_Surface(person.frames[0], 
                       rightx1, righty1,
                       person.width,person.height,
                       lpddsback);

		righty1+=16;
		righty+=16;
		counter++;
	}
//左边刚出的牌
	if(counter2<12)
	{
	DDraw_Draw_Surface(person.frames[0], 
                       leftx2, lefty2,
                       person.width,person.height,
                       lpddsback);

	lefty2+=25;

//右边刚出的牌


	DDraw_Draw_Surface(person.frames[0], 
                       rightx2, righty2,
                       person.width,person.height,
                       lpddsback);

	righty2+=25;

//中间刚出的牌

	DDraw_Draw_Surface(person.frames[0], 
                       centerx2, centery2,
                       person.width,person.height,
                       lpddsback);
	centerx2+=25;

	counter2++;
	}
*/



	int Dealing_Cards_Center(int Current_x,
				int Card_Color,
				int Card_Value
							);


	int Dealing_Cards_Left(int Current_y);
	int Dealing_Cards_Right(int Current_y);


//发中间的牌;
int CDraw_Cards_Engine::Dealing_Cards_Center(int Current_x,int Card_Color,int Card_Value)
{
	int dx,dy,dx2,dy2,x_inc,y_inc,error;
	int x = Card_x,y = Card_y;

	dx = Current_x - Card_x;

	dy = Center_y0 - Card_y;
	
	if(dx>=0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx = -dx;
	}

	if(dy >= 0)
	{
		y_inc = 1;
	}
	else
	{
		y_inc = -1;
		dy = -dy;
	}

	dx2 = dx << 1;
	dy2 = dy << 1;

//这里只考虑dy > dx;

	error = dx2 - dy;
	for(int i=0;i<int(dy);i++)
	{
		if(i%80 == 0)
		{
			Redraw_Game();
			Draw_A_Card(x,y,Card_Color,Card_Value,lpddsback);
			while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));
		}

		if(error >= 0)
		{
			error-=dy2;
			x+=x_inc;
		}
			error+=dx2;
			y+=y_inc;
	}//end for~

	Redraw_Game();
	Draw_A_Card(x,y,Card_Color,Card_Value,lpddsback);
	while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));
	return 1;
}

//发左边的牌;
int CDraw_Cards_Engine::Dealing_Cards_Left(int Current_y)
{
	int dx,dy,dx2,dy2,x_inc,y_inc,error;
	int x = Card_x,y = Card_y;

	dx = Left_x0 - Card_x;

	dy = Current_y - Card_y;
	
	if(dx>=0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx = -dx;
	}

	if(dy >= 0)
	{
		y_inc = 1;
	}
	else
	{
		y_inc = -1;
		dy = -dy;
	}

	dx2 = dx << 1;
	dy2 = dy << 1;

	if(dx > dy)
	{
		error = dy2 - dx;
		for(int i=0;i<int(dx);i++)
		{
			if(i%140 == 0)
			{
				Redraw_Game();
				pMy_Draw->DDraw_Draw_Surface(lpddsbg_Cards[14], 
							x, y,
                       Cards_Width,Cards_Height,
                       lpddsback,1);

				while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));
			}

			if(error >= 0)
			{
				error-=dx2;
				y+=y_inc;
			}
			error+=dy2;
			x+=x_inc;
		}//end for~
	}
	else
	{
		error = dx2 - dy;
		for(int i=0;i<int(dy);i++)
		{
			if(i%140 == 0)
			{
				Redraw_Game();
				pMy_Draw->DDraw_Draw_Surface(lpddsbg_Cards[14], 
							x, y,
                       Cards_Width,Cards_Height,
                       lpddsback,1);

				while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));
			}

			if(error >= 0)
			{
				error-=dy2;
				x+=x_inc;
			}
			error+=dx2;
			y+=y_inc;
		}//end for~

	}

	Redraw_Game();
	pMy_Draw->DDraw_Draw_Surface(lpddsbg_Cards[14], 
							x, y,
                      Cards_Width,Cards_Height,
                       lpddsback,1);
	
	while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));

	return 1;
}

int CDraw_Cards_Engine::Dealing_Cards_Right(int Current_y)
{
	int dx,dy,dx2,dy2,x_inc,y_inc,error;
	int x = Card_x,y = Card_y;

	dx = Right_x0 - Card_x;

	dy = Current_y - Card_y;
	
	if(dx>=0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx = -dx;
	}

	if(dy >= 0)
	{
		y_inc = 1;
	}
	else
	{
		y_inc = -1;
		dy = -dy;
	}

	dx2 = dx << 1;
	dy2 = dy << 1;

	if(dx > dy)
	{
		error = dy2 - dx;
		for(int i=0;i<int(dx);i++)
		{
			if(i%140 == 0)
			{
				Redraw_Game();
				pMy_Draw->DDraw_Draw_Surface(lpddsbg_Cards[14], 
							x, y,
                       Cards_Width,Cards_Height,
                       lpddsback,1);

				while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));
			}

			if(error >= 0)
			{
				error-=dx2;
				y+=y_inc;
			}
			error+=dy2;
			x+=x_inc;
		}//end for~
	}
	else
	{
		error = dx2 - dy;
		for(int i=0;i<int(dy);i++)
		{
			if(i%140 == 0)
			{
				Redraw_Game();
				pMy_Draw->DDraw_Draw_Surface(lpddsbg_Cards[14], 
							x, y,
                       Cards_Width,Cards_Height,
                       lpddsback,1);

				while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));
			}

			if(error >= 0)
			{
				error-=dy2;
				x+=x_inc;
			}
			error+=dx2;
			y+=y_inc;
		}//end for~

	}

	Redraw_Game();
	pMy_Draw->DDraw_Draw_Surface(lpddsbg_Cards[14], 
							x, y,
                      Cards_Width,Cards_Height,
                       lpddsback,1);

	while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));
	return 1;
}


//CGame
//		pCDraw_Cards->Draw_A_Card(Left_x0,
//								  pGame_Map->Left0[counter].y,
//								  0,
//								  17,
//								  lpddsbg_Dealing);

//		pMy_Draw->DDraw_Draw_Surface(lpddsbg_Dealing,0,0, Screen_Width,Screen_Height, lpddsback,0); 


		
//		pCDraw_Cards->Draw_A_Card(pGame_Map->Center0[counter].x,
//								  Center_y0,
//								  pMy_Cards->Cards[counter].Color,
//								  pMy_Cards->Cards[counter].Value,
//								  lpddsbg_Dealing);

//		pMy_Draw->DDraw_Draw_Surface(lpddsbg_Dealing,0,0, Screen_Width,Screen_Height, lpddsback,0); 



//		pCDraw_Cards->Draw_A_Card(Right_x0,
//								  pGame_Map->Left0[counter].y,
//								  0,
//								  17,
//								  lpddsbg_Dealing);



//		pCDraw_Cards->Dealing_Cards_Center(Center_x0 + counter*Card_Distance1,
// 									   Lord_Cards.Cards[counter].Color,Lord_Cards.Cards[counter].Value);

//		pCDraw_Cards->Dealing_Cards_Center(Center_x0 + counter*Card_Distance1,
//									   Lord_Cards.Cards[counter+1].Color,Lord_Cards.Cards[counter].Value);

//		pCDraw_Cards->Dealing_Cards_Center(Center_x0 + counter*Card_Distance1,
// 									   Lord_Cards.Cards[counter+2].Color,Lord_Cards.Cards[counter].Value);

//		pCDraw_Cards->Dealing_Cards_Up(Lord_Card1_x);
//		pCDraw_Cards->Dealing_Cards_Up(Lord_Card2_x);
//		pCDraw_Cards->Dealing_Cards_Up(Lord_Card3_x);


int CGame::Clean_Up_Cards()
{
//	pLeft_Cards  = new CPlaying_Cards;    //左边玩家的牌对象;
//	pMy_Cards    = new CPlaying_Cards;	  //主机玩家的牌对象;
//	pRight_Cards = new CPlaying_Cards;	  //右边玩家的牌对象;
//	::Sleep(10000);


	


	for(int k=0;k<17;k++)
	{
		lpddsbg_Dealing->Blt(
			CRect(Center_x0 + k*Card_Distance1,
				  Center_y0,
				  Center_x0 + k*Card_Distance1 + Cards_Width,
				  Center_y0 + Cards_Height),      //目标区域;
			lpddsbg_Cards[pMy_Cards->Cards[k].Value - 3],  //源表面;
			CRect(pMy_Cards->Cards[k].Color*Cards_Width,
				  0,
				  pMy_Cards->Cards[k].Color*Cards_Width + Cards_Width,
				  Cards_Height),				  //源区域;
			DDBLT_WAIT | DDBLT_KEYSRC,
			NULL);

		pMy_Draw->DDraw_Draw_Surface(lpddsbg_Dealing,0,0, Screen_Width,Screen_Height, lpddsback,0); 

		while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));
	}
	return 1;
}

//其他精灵;
//角花
/*
	file = "bmp\\item\\left_top.bmp" ;

	lpddsbg_Person[0] = pMy_Draw->DDraw_Create_Surface(15,15,0,blue);

	pMy_Draw->BltBitmap_to_Surface(lpddsbg_Person[0],0,0,file,15,15);
//角花贴到角上;
	pMy_Draw->DDraw_Draw_Surface(lpddsbg_Person[0], 
                       0, 0,
                       15,15,
                       lpddsbg_Game,1);
	pMy_Draw->DDraw_Draw_Surface(lpddsbg_Person[0], 
                       1024-15, 0,
                       15,15,
                       lpddsbg_Game,1);

	pMy_Draw->DDraw_Draw_Surface(lpddsbg_Person[0], 
                       0, 768-15,
                       15,15,
                       lpddsbg_Game,1);
	pMy_Draw->DDraw_Draw_Surface(lpddsbg_Person[0], 
                       1024-15, 768-15,
                       15,15,
                       lpddsbg_Game,1);
//地主牌边框;
	file = "bmp\\item\\lord2.bmp" ;

	pMy_Draw->BltBitmap_to_Surface(lpddsbg_Game,
								   Lord_Card1_x - 11,
								   Lord_Card1_y - 9,
								   file,
								   288,
								   132);

	pMy_Draw->DDraw_Draw_Surface(lpddsbg_Game,0,0, Screen_Width,Screen_Height,lpddsback,0); 
	while (FAILED(lpddsprimary->Flip(NULL, DDFLIP_WAIT)));	
	Sleep(4000);
	*/