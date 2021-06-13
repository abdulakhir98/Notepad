//#include<iostream>
//#include<fstream>
//#include <windows.h>
//#include <conio.h> 
//using namespace std;
//
//int x = 0;
//int y = 0;
//
//struct node
//{
//	char letter;
//	node*next;
//	node*prev;
//	node*up;
//	node*down;
//};
//
//void gotoxy(int x, int y)
//{
//	COORD coord;
//	coord.X = x;		coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//class TwoDDLLADT
//{
//	node * first, *cursor;
//
//public:
//	TwoDDLLADT();
//	~TwoDDLLADT();
//	void Insert(char c); 	
//	void Print(); 
//	void Save(); 
//	void Load();
//	bool Delete(); //delete a character wherever the pointer cursor is pointing.
//	bool Up(); 
//	bool Down(); 
//	bool Left(); 
//	bool Right(); // functions control the movement of the pointer cursor
//
//};
//
//TwoDDLLADT::TwoDDLLADT() {
//	first = 0;
//	cursor = 0;
//}
//
//TwoDDLLADT::~TwoDDLLADT() {
//
//}
//
//void TwoDDLLADT::Insert(char c) {
//	node *temp = new node;
//	temp->letter = c;
//	temp->next = 0;
//	temp->prev = 0;
//	temp->up = 0;
//	temp->down = 0;
//	if (first == 0) {
//		first = temp;
//		cursor = temp;
//		x = x++;
//	}
//	else if (temp->letter != 13)
//	{
//		node *move = cursor->next;
//		node *above = cursor->up;
//		node *current = cursor;
//		while (current->prev != 0)
//		{
//			current = current->prev;
//		}
//		node *below = cursor->down;
//		if (current == cursor) {
//			current = 0;
//		}
//		if (cursor->letter != 13) {
//			if (move != 0)
//			{
//				move->prev = temp;
//				temp->next = move;
//				cursor->next = temp;
//				temp->prev = cursor;
//				cursor = temp;
//				x = x++;
//			}
//			else
//			{
//				cursor->next = temp;
//				temp->prev = cursor;
//				cursor = temp;
//				x = x++;
//			}
//			if (above != 0)
//			{
//				move = cursor;
//				above = above->next;
//				while (above != 0 && move != 0)
//				{
//					above->down = move;
//					move->up = above;
//					above = above->next;
//					move = move->next;
//				}
//			}
//			while (above != 0) {
//				above->down = 0;
//				above = above->next;
//			}
//			while (move != 0) {
//				move->up = 0;
//				move = move->next;
//			}
//			if (below != 0)
//			{
//				move = cursor;
//				below = below->next;
//				while (below != 0 && move != 0)
//				{
//					move->down = below;
//					below->up = move;
//					move = move->next;
//					below = below->next;
//				}
//			}
//			while (below != 0) {
//				below->up = 0;
//				below = below->next;
//			}
//			while (move != 0) {
//				move->down = 0;
//				move = move->next;
//			}
//		}
//		else {
//			temp->prev = cursor->prev;
//			cursor->prev->next = temp;
//			temp->next = cursor;
//			cursor->prev = temp;
//			x = x++;
//			if (above != 0)
//			{
//				move = temp;
//				while (above != 0 && move != 0)
//				{
//					above->down = move;
//					move->up = above;
//					above = above->next;
//					move = move->next;
//				}
//			}
//			while (above != 0) {
//				above->down = 0;
//				above = above->next;
//			}
//			while (move != 0) {
//				move->up = 0;
//				move = move->next;
//			}
//			if (below != 0)
//			{
//				move = temp;
//				while (below != 0 && move != 0)
//				{
//					move->down = below;
//					below->up = move;
//					move = move->next;
//					below = below->next;
//				}
//			}
//			while (below != 0) {
//				below->up = 0;
//				below = below->next;
//			}
//			while (move != 0) {
//				move->down = 0;
//				move = move->next;
//			}
//		}
//	}
//	else if (temp->letter == 13) {
//		node *move = cursor;
//		node *above = cursor->up;
//		node *current = cursor;
//		while (current->prev != 0)
//		{
//			current = current->prev;
//		}
//		node *below = cursor->down;
//		if (current == cursor) {
//			current = 0;
//		}
//		if (move == 0 && current->down == 0) {
//			cursor->next = temp;
//			temp->prev = cursor;
//			cursor = temp;
//			y = y++;
//		}
//		else if (move != 0 && current->down == 0) {
//			cursor->next = temp;
//			temp->prev = cursor;
//			cursor = temp;
//			current->down = move;
//			move->up = current;
//			move = move->next;
//			current = current->next;
//			while (current != 0 && move != 0) {
//				current->down = move;
//				move->up = current;
//				current = current->next;
//				move = move->next;
//			}
//			while (current != 0) {
//				current->down = 0;
//				current = current->next;
//			}
//			while (move != 0) {
//				move->up = 0;
//				move = move->next;
//			}
//			y = y++;
//		}
//		else if (move != 0 && current->down != 0) {
//			node*n = current->down;
//			node*k = move;
//			cursor->next = temp;
//			temp->prev = cursor;
//			current = current->next;
//			while (current != 0 && move != 0) {
//				current->down = move;
//				move->up = current;
//				current = current->next;
//				move = move->next;
//			}
//			while (current != 0) {
//				current->down = 0;
//				current = current->next;
//			}
//			while (move != 0) {
//				move->up = 0;
//				move = move->next;
//			}
//			while (k != 0 && n != 0) {
//				k->prev->down = n;
//				n->up = k;
//				k = k->next;
//				n = n->next;
//			}
//			while (k != 0) {
//				k->down = 0;
//				k = k->next;
//			}
//			while (n != 0) {
//				n->up = 0;
//				n = n->next;
//			}
//			y = y++;
//		}
//	}
//}
//
//void TwoDDLLADT::Print() {
//	node *row = first;
//	node *col = first;
//	while (row != 0)
//	{
//		while (col != 0)
//		{
//			if (col->letter == 13)
//			{
//				cout << endl;
//				break;
//			}
//			else
//			{
//				cout << col->letter;
//				col = col->next;
//			}
//		}
//		row = row->down;
//		col = row;
//	}
//}
//
//void TwoDDLLADT::Save(){
//
//}
//
//void TwoDDLLADT::Load() {
//
//}
//
//bool TwoDDLLADT::Delete() {
//	return true;
//}
//
//bool TwoDDLLADT::Up()
//{
//	int a = x;
//	if (first == 0)
//		return false;
//	node *kp = cursor;
//	if (kp->prev == 0 && kp->up == 0)
//	{
//		return false;
//	}
//	while (kp->prev != 0)
//	{
//		if (kp->up != 0)
//			break;
//		kp = kp->prev;
//		a = a--;
//	}
//	if (kp == 0)
//		return false;
//	if (kp->up == 0) {
//		return false;
//	}
//	else if (kp->up->letter == 13) {
//		kp = kp->up;
//		kp = kp->prev;
//		y = y--;
//		a = a--;
//		x = a;
//		cursor = kp;
//	}
//	else {
//		kp = kp->up;
//		y = y--;
//		cursor = kp;
//	}
//	return true;
//}
//
//bool TwoDDLLADT::Down()
//{
//	int a = x;
//	if (first == 0)
//		return false;
//	node *cd = cursor;
//	if (cd->prev == 0 && cd->down == 0)
//		return false;
//	while (cd->prev != 0)
//	{
//		if (cd->down != 0)
//			break;
//		cd = cd->prev;
//		a = a--;
//	}
//	if (cd == 0)
//		return false;
//	if (cd->down == 0) {
//		return false;
//	}
//	else if (cd->down->letter == 13) {
//		cd = cd->down;
//		cd = cd->prev;
//		a = a--;
//		x = a;
//		y = y++;
//	}
//	else
//	{
//		cd = cd->down;
//		y = y++;
//		x = a;
//		cursor = cd;
//	}
//	return true;
//}
//
//bool TwoDDLLADT::Right() {
//	int a = x;
//	if (first == 0)
//		return false;
//	node *cr = cursor;
//	if (cr->next == 0) {
//		return false;
//	}
//	else if (cr->next->letter == 13)
//	{
//		node *crl = cr;
//		while (crl->prev != 0) {
//			crl = crl->prev;
//			a = a--;
//		}
//		if (crl->down == 0) {
//			return false;
//		}
//		else {
//			crl = crl->down;
//			cr = crl;
//			y = y++;
//			x = a;
//			cursor = cr;
//			return true;
//		}
//	}
//	else {
//		cr = cr->next;
//		cursor = cr;
//		x = x++;
//		return true;
//	}
//}
//
//bool TwoDDLLADT::Left()
//{
//	if (first == 0)
//		return false;
//	node *cl = cursor;
//	if (cl->prev == 0)
//	{
//		node *cll = cl;
//		while (cll->prev != 0) {
//			cll = cll->prev;
//		}
//		if (cll->up == 0) {
//			return false;
//		}
//		else
//		{
//			cll = cll->up;
//			while (cll->next->letter != 13)
//			{
//				cll = cll->next;
//				x = x++;
//			}
//			cl = cll;
//			y = y--;
//			cursor = cl;
//			return true;
//		}
//	}
//	else if (cl->prev != 0)
//	{
//		cl = cl->prev;
//		cursor = cl;
//		x = x--;
//	}
//	return true;
//}
//
//int main()
//{
//	TwoDDLLADT notepad;
//	while (1) {
//		char c = _getch();
//		if (c == -32)
//		{
//			c = _getch();
//			if (c == 'H') {
//				notepad.Up();
//				gotoxy(x, y);
//			}
//			else if (c == 'K') {
//				notepad.Left();
//				gotoxy(x, y);
//			}
//			else if (c == 'M') {
//				notepad.Right();
//				gotoxy(x, y);
//			}
//			else if (c == 'P') {
//				notepad.Down();
//				gotoxy(x, y);
//			}
//
//		}
//		else {
//			notepad.Insert(c);
//			system("CLS");
//			notepad.Print();
//			gotoxy(x, y);
//		}
//		//else if c is delete or backspace	
//		//else if c is S for save
//		//else if c is L for load
//
//	}
//}
