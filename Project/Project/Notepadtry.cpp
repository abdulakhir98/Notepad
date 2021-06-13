#include<iostream>
#include<fstream>
#include <windows.h>
#include <conio.h> 
using namespace std;

int x = 0;
int y = 0;

struct node
{
	char letter;
	node*next;
	node*prev;
	node*up;
	node*down;
};

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;		coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class TwoDDLLADT
{
	node * first, *cursor;

public:
	TwoDDLLADT();
	~TwoDDLLADT();
	void Insert(char c); 	
	void Print(); 
	void Save(); 
	void Load();
	bool Delete(); //delete a character wherever the pointer cursor is pointing.
	bool Up(); 
	bool Down(); 
	bool Left(); 
	bool Right(); // functions control the movement of the pointer cursor

};

TwoDDLLADT::TwoDDLLADT() {
	node *dummy = new node;
	dummy->up = 0;
	dummy->down = 0;
	dummy->prev = 0;
	dummy->next = 0;
	dummy->letter = 0;

	first = dummy;
	cursor = dummy;
}

TwoDDLLADT::~TwoDDLLADT() {
	node * a = first;
	node * d = first->down;
	while (first != 0) {
		while (a != 0) {
			first = first->next;
			delete a;
			a = first;
		}
		first = d;
		a = first;
		if (first != 0) {
			d = first->down;
		}
	}
	cursor = 0;
	system("CLS");
}

void TwoDDLLADT::Insert(char c) {
	node *temp = new node;
	temp->letter = c;
	temp->next = 0;
	temp->prev = 0;
	temp->up = 0;
	temp->down = 0;

	node *dummy = new node;
	dummy->up = 0;
	dummy->down = 0;
	dummy->prev = 0;
	dummy->next = 0;
	dummy->letter = 0;

	if (temp->letter != 13)
	{
		node *current = cursor;
		node *below = cursor->down;
		node *move = cursor->next;
		node *above = cursor->up;
		while (current->prev != 0)
		{
			current = current->prev;
		}
		if (cursor->letter != 13) {
			if (move != 0)
			{
				move->prev = temp;
				temp->next = move;
				cursor->next = temp;
				temp->prev = cursor;
				cursor = temp;
				x = x++;
			}
			else
			{
				cursor->next = temp;
				temp->prev = cursor;
				cursor = temp;
				x = x++;
			}
			if (above != 0)
			{
				move = cursor;
				above = above->next;
				while (above != 0 && move != 0)
				{
					above->down = move;
					move->up = above;
					above = above->next;
					move = move->next;
				}
			}
			if (above != 0) {
				while (above != 0) {
					above->down = 0;
					above = above->next;
				}
			}
			if (move != 0) {
				while (move != 0) {
					move->up = 0;
					move = move->next;
				}
			}
			if (below != 0)
			{
				move = cursor;
				below = below->next;
				while (below != 0 &&move != 0)
				{
					move->down = below;
					below->up = move;
					move = move->next;
					below = below->next;
				}
			}
			if (below != 0) {
				while (below != 0) {
					below->up = 0;
					below = below->next;
				}
			}
			if (move != 0) {
				while (move != 0) {
					move->down = 0;
					move = move->next;
				}
			}
		}
		else {
			temp->prev = cursor->prev;
			cursor->prev->next = temp;
			temp->next = cursor;
			cursor->prev = temp;
			x = x++;
			if (above != 0)
			{
				move = temp;
				while (above != 0 && move != 0)
				{
					above->down = move;
					move->up = above;
					above = above->next;
					move = move->next;
				}
			}
			if (above != 0) {
				while (above != 0) {
					above->down = 0;
					above = above->next;
				}
			}
			if (move != 0) {
				while (move != 0) {
					move->up = 0;
					move = move->next;
				}
			}
			if (below != 0)
			{
				move = temp;
				while (below != 0 && move != 0)
				{
					move->down = below;
					below->up = move;
					move = move->next;
					below = below->next;
				}
			}
			if (below != 0) {
				while (below != 0) {
					below->up = 0;
					below = below->next;
				}
			}
			if (move != 0) {
				while (move != 0) {
					move->down = 0;
					move = move->next;
				}
			}
		}
	}
	else if (temp->letter == 13) {
		node *current = cursor;
		node *below = cursor->down;
		node *move = cursor->next;
		node *above = cursor->up;
		while (current->prev != 0)
		{
			current = current->prev;
			x = x--;
		}
		if (move == 0 && current->down == 0) {
			cursor->next = temp;
			temp->prev = cursor;
			current->down = dummy;
			dummy->up = current;
			cursor = dummy;
			y = y++;
		}
		else if (move != 0 && current->down == 0) {
			cursor->next = temp;
			temp->prev = cursor;
			if (above != 0) {
				above = above->next;
				if (above != 0)
				{
					temp->up = above;
				}
			}
			current->down = dummy;
			dummy->up = current;
			cursor = dummy;
			move->prev = dummy;
			dummy->next = move;
			current = current->next;
			while (current != 0 && move != 0) {
				current->down = move;
				move->up = current;
				current = current->next;
				move = move->next;
			}
			while (current != 0) {
				current->down = 0;
				current = current->next;
			}
			while (move != 0) {
				move->up = 0;
				move = move->next;
			}
			y = y++;
		}
		else if (move->letter == 13 && current->down->next->letter == 13 && above !=0) {
			node*n = current->down;
			node*k = move;
			cursor->next = temp;
			temp->prev = cursor;
			above->next->down = temp;
			current->down = dummy;
			dummy->up = current;
			cursor = dummy;
			move->prev = dummy;
			dummy->next = move;
			current = current->next;
			while (current != 0 && move != 0) {
				current->down = move;
				move->up = current;
				current = current->next;
				move = move->next;
			}
			while (current != 0) {
				current->down = 0;
				current = current->next;
			}
			while (move != 0) {
				move->up = 0;
				move = move->next;
			}
			while (k != 0 && n != 0) {
				k->prev->down = n;
				n->up = k->prev;
				k = k->next;
				n = n->next;
			}
			while (k != 0) {
				k->down = 0;
				k = k->next;
			}
			while (n != 0) {
				n->up = 0;
				n = n->next;
			}
			y = y++;
		}
		else if (move != 0 && current->down != 0) {
			node*n = current->down;
			node*k = move;
			cursor->next = temp;
			temp->prev = cursor;
			current->down = dummy;
			dummy->up = current;
			cursor = dummy;
			move->prev = dummy;
			dummy->next = move;
			current = current->next;
			while (current != 0 && move != 0) {
				current->down = move;
				move->up = current;
				current = current->next;
				move = move->next;
			}
			while (current != 0) {
				current->down = 0;
				current = current->next;
			}
			while (move != 0) {
				move->up = 0;
				move = move->next;
			}
			while (k != 0 && n != 0) {
				k->prev->down = n;
				n->up = k->prev;
				k = k->next;
				n = n->next;
			}
			while (k != 0) {
				k->down = 0;
				k = k->next;
			}
			while (n != 0) {
				n->up = 0;
				n = n->next;
			}
			y = y++;
		}
	}	
}

void TwoDDLLADT::Print() {
	node *row = first;
	node *col = first;
	while (row != 0)
	{
		while (col != 0)
		{
			if (col->letter == 13)
			{
				cout << endl;
				break;
			}
			else if (col->letter == 0) {
				col = col->next;
			}
			else
			{
				cout << col->letter;
				col = col->next;
			}
		}
		row = row->down;
		col = row;
	}
}

void TwoDDLLADT::Save() {
	ofstream myfile("notepad.txt");
	if (myfile.is_open())
	{
		node *row = first;
		node *col = first;
		while (row != 0)
		{
			while (col != 0)
			{
				if (col->letter == 13)
				{
					myfile << endl;
					break;
				}
				else if (col->letter == 0) {
					col = col->next;
				}
				else
				{
					myfile << col->letter;
					col = col->next;
				}
			}
			row = row->down;
			col = row;
		}
	}
	else
		cout << "Unable to open file";
}

void TwoDDLLADT::Load() {
	ifstream myfile("notepad.txt");
	if (myfile.is_open())
	{
		node * a = first;
		node * d = first->down;
		while (first != 0) {
			while (a != 0) {
				first = first->next;
				delete a;
				a = first;
			}
			first = d;
			a = first;
			if (first != 0) {
				d = first->down;
			}
		}
		system("CLS");

		node *dummy = new node;
		dummy->up = 0;
		dummy->down = 0;
		dummy->prev = 0;
		dummy->next = 0;
		dummy->letter = 0;

		cursor = dummy;
		first = dummy;

		char word;
		myfile.get(word);
		while (!myfile.eof())
		{
			if (word == 10) {
				word = 13;
			}
			Insert(word);
			myfile.get(word);
		}
		x = 0;
		y = 0;
		cursor = first;
		system("CLS");
		Print();
		gotoxy(x, y);
		myfile.close();
	}
	else cout << "Unable to open file";
}

bool TwoDDLLADT::Delete() {	
	if (first->next == 0)
		return false;
	else if (cursor->letter == 0 && cursor->up == 0 ) {
		return false;
	}
	else if (cursor->letter != 0)
	{
		node *move = cursor->next;
		node *behind = cursor->prev;
		node *above = cursor->up;
		node *below = cursor->down;
		node *current = cursor;
		while (current->prev != NULL)
		{
			current = current->prev;
		}
		if (move == NULL && behind->letter == 0)///at first
		{
			behind->next = 0;
			x = x--;
			delete cursor;
			cursor = behind;
			if (above != 0)
			{
				above->down = 0;
			}
			if (below != 0)
			{
				below->up = 0;
			}
		}
		else if (move != NULL && behind->letter == 0)///at first
		{
			behind->next = move;
			move->prev = behind;
			x = x--;
			delete cursor;
			cursor = behind;
			if (above != 0)
			{
				above->down = 0;
			}
			if (below != 0)
			{
				below->up = 0;
			}
		}
		else if (move == NULL && behind->prev != NULL)///at last
		{
			behind->next = 0;
			x = x--;
			delete cursor;
			cursor = behind;
			if (above != 0)
			{
				above->down = 0;
			}
			if (below != 0)
			{
				below->up = 0;
			}
		}
		else if (move != NULL && behind->prev != 0)///inbetween values
		{
			behind->next = move;
			move->prev = behind;
			delete cursor;
			cursor = behind;
			x = x--;
			node *k = move;
			while (above != 0 && move != 0)
			{
				above->down = move;
				move->up = above;
				above = above->next;
				move = move->next;
			}
			while (above != 0)
			{
				above->down = 0;
				above = above->next;
			}
			while (move != 0)
			{
				move->up = 0;
				move = move->next;
			}
			while (below != 0 && k != 0)
			{
				k->down = below;
				below->up = k;
				k = k->next;
				below = below->next;
			}
			while (below != 0)
			{
				below->up = 0;
				below = below->next;
			}
			while (k != 0)
			{
				k->down = 0;
				k = k->next;
			}
		}
	}
	else if (cursor->letter == 0 && cursor->up != 0)
	{
		node *move = cursor->next;
		node *above = cursor->up;
		node *below = cursor->down;
		node *current = cursor;
		while (current->prev != NULL)
		{
			current = current->prev;
		}
		if (move == 0) {
			node * c = cursor->up;
			current = cursor->up;
			while (c->letter != 13) {
				c = c->next;
				x = x++;
			}
			y = y--;
			current->down = 0;
			delete cursor;
			cursor = c;
			c = c->prev;
			delete cursor;
			c->next = 0;
			cursor = c;
			x = x--;
		}
		else if (move != 0) {
			node *a = above;
			node *b = below;
			node *m = move;
			current = cursor->up;
			while (a->letter != 13) {
				a = a->next;
				x = x++;
			}
			y = y--;
			delete cursor;
			cursor = a;
			a = a->prev;
			delete cursor;
			a->next = m;
			m->prev = a;
			cursor = a;
			x = x--;
			while (above != 0 && b != 0) {
				above->down = b;
				b->up = above;
				above = above->next;
				b = b->next;
			}
			while (above != 0) {
				above->down = 0;
				above = above->next;
			}
			while (b != 0) {
				b->up = 0;
				b = b->next;
			}
		}
	}
	return true;
}

bool TwoDDLLADT::Up()
{
	int a = x;
	if (first == 0)
		return false;
	node *kp = cursor;
	if (kp->prev == 0 && kp->up == 0)
	{
		return false;
	}
	while (kp->prev != 0)
	{
		if (kp->up != 0)
			break;
		kp = kp->prev;
		a = a--;
	}
	if (kp == 0)
		return false;
	if (kp->up == 0) {
		return false;
	}
	else if (kp->up->letter == 13) {
		kp = kp->up;
		kp = kp->prev;
		y = y--;
		a = a--;
		x = a;
		cursor = kp;
	}
	else {
		kp = kp->up;
		x = a;
		y = y--;
		cursor = kp;
	}
	return true;
}

bool TwoDDLLADT::Down()
{	
	int a = x;
	if (first == 0)
		return false;
	node *cd = cursor;
	if (cd->prev == 0 && cd->down == 0)
		return false;
	while (cd->prev != 0)
	{
		if (cd->down != 0)
			break;
		cd = cd->prev;
		a = a--;
	}
	if (cd == 0)
		return false;
	if (cd->down == 0) {
		return false;
	}
	else if (cd->down->letter == 13) {
		cd = cd->down;
		cd = cd->prev;
		a = a--;
		x = a;
		y = y++;
		cursor = cd;
		return true;
	}
	else 
	{
		cd = cd->down;
		x = a;
		y = y++;
		cursor = cd;
		return true;
	}
}

bool TwoDDLLADT::Right() {
	int a = x;
	if (first == 0)
		return false;
	node *cr = cursor;
	if (cr->next == 0) {
		return false;
	}
	else if (cr->next->letter == 13)
	{
		node *crl = cr;
		while (crl->prev != 0) {
			crl = crl->prev;
			a = a--;
		}
		if (crl->down == 0) {
			return false;
		}
		else {
			crl = crl->down;
			cr = crl;
			y = y++;
			x = a;
			cursor = cr;
			return true;
		}
	}
	else {
		cr = cr->next;
		cursor = cr;
		x = x++;
		return true;
	}
}

bool TwoDDLLADT::Left()
{
	int a = x;
	if (first == 0)
		return false;
	node *cl = cursor;
	if (cl->prev == 0)
	{
		node *cll = cl;
		while (cll->prev != 0) {
			cll = cll->prev;
			a = a--;
		}
		if (cll->up == 0) {
			return false;
		}
		else
		{
			cll = cll->up;
			while (cll->next->letter != 13)
			{
				cll = cll->next;
				a = a++;
			}
			cl = cll;
			y = y--;
			x = a;
			cursor = cl;
			return true;
		}
	}
	else if (cl->prev != 0)
	{
		cl = cl->prev;
		cursor = cl;
		x = x--;
	}
	return true;
}

int main()
{
	TwoDDLLADT notepad;
	while (1) {
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 'H') {
				notepad.Up();
				gotoxy(x, y);
			}
			else if (c == 'K') {
				notepad.Left();
				gotoxy(x, y);
			}
			else if (c == 'M') {
				notepad.Right();
				gotoxy(x, y);
			}
			else if (c == 'P') {
				notepad.Down();
				gotoxy(x, y);
			}

		}
		else if (c == 8) {
			notepad.Delete();
			system("CLS");
			notepad.Print();
			gotoxy(x, y);
		}
		else if (c == 'S') {
			notepad.Save();
		}
		else if (c == 'L') {
			notepad.Load();
		}
		else if (c == 'Q') {
			return 0;
		}
		else {
			notepad.Insert(c);
			system("CLS");
			notepad.Print();
			gotoxy(x, y);
		}
	}

}
