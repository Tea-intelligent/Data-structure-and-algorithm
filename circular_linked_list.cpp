
#include <iostream>
using namespace std;

//------------------------NODE STRUCTURE----------------------//
struct node {
	int data;        //Data of the node (int type)
	node* pnext;     //Pointer to the next pointer

};
//-----------------------LIST STRUCTURE----------------------//
struct list {
	node* phead;     // Pointer to the first node
	node* ptail;     // Pointer to the last node
};
//----------------------Create node function-------------------//
node* createnode(int x) {
	node* p = new node;
	if (p == NULL) exit(1);
	else {
		p->data = x;
		p->pnext = NULL;
		return p;
	}
}
//---------------------Create list function-----------------//
void createlist(list& l) {
	l.phead = NULL;
	l.ptail = NULL;
}

//--------------------Add node to the head of the list-------//
void addhead(list& l, node* p) {
	if (l.phead == NULL) {
		l.phead = p;
		l.ptail = l.phead;
	}
	else {
		p->pnext = l.phead;
		l.phead = p;
		l.ptail->pnext = l.phead;
	}
}
//-------------------Add node to the tail of the list----------//
void addtail(list& l, node* p) {
	if (l.phead == NULL) {
		l.phead = p;
		l.ptail = l.phead;
	}
	else {
		p->pnext = l.phead;
		l.ptail->pnext = p;
		l.ptail = p;
	}
}

//-----------------Input the list---------------------//
void input(list& l) {
	int n;
	int x;
	do {
		cout << "Input the number of node you want to create:";
		cin >> n;
	} while (n < 0);
	for (int i = 0; i < n; i++) {
		cout << "Input the value of data:";
		cin >> x;
		node* p = createnode(x);
		addhead(l, p);
	}
}
//--------------------Print out the list---------------//
void output(list l) {
	node* p = l.phead;
	int n=0;
	while( n < 2) {
		cout << p->data << ",";
		if (p->pnext == l.phead) {
			n++;
			cout << " " << endl;
		}
		p = p->pnext;
	}
}

//-------------------input a node after a node Q---------//
void insertafterQ(list&l, node* p, node* q) {     
	if (q != NULL) {
		p->pnext = q->pnext;
		q->pnext = p;
		if (l.ptail == q) {
			addtail(l,p);
		}
	}
	else {
		addhead(l, p);
	}
} 
//--------Delete the head node-------------------//
int removehead(list& l,int x) {      
	node* p;
	if (l.phead != NULL) {
		p = l.phead;
		x = p->data;
		l.phead = l.phead->pnext;
		l.ptail->pnext = l.phead;
		delete p;
		if (l.phead == NULL)
			l.ptail = NULL;

		return 1;

	}
	return 0;
}
//-----------Delete a node after node Q---------------//
int removeafterQ(list& l, node* q, int x) {   
	node* p;
	if (q != NULL) {
		p = q->pnext;
		if (p != l.phead) {
			if (p == l.ptail)
				l.ptail = q;
			q->pnext = p->pnext; x = p->data;
			delete p;
			l.ptail->pnext = l.phead;
			
		}
		else { removehead(l, 0); }
		return 1;
	}
	else { 
	return 0; 
	}
}
//-------Delete a node with data == x--------//
int RemoveX(list& l, int x)     //xoa phan tu co data=x
{
	node* p, * q = NULL; p = l.phead; int n=0;
	while (p->data != x)
	{
		if (p == l.phead && n!=0) {
			p = NULL;
			break;
		}
		q = p;
		p = p->pnext;
		n++;
		
	}
	if (p == NULL)
		return 0;
	if (p != NULL)
		removeafterQ(l, q, x);
	else 
		removehead(l, x);
	return 1;
}
node* search(list l, int x) {     //tim kiem 
	node* p=l.ptail;
	int n = 0;
	while (p->data != x) {
		if (p == l.phead && n != 0) {
			p = NULL;
			break;
		}
		p->pnext;
		n++;
	}
	return p;
}
//---------------swapping function----------------//
void swap(node* p, node* q) {     //ham hoan vi de sap xep ds
	int a = p->data;
	p->data = q->data;
	q->data = a;
}
//--------------Sort list------------------------//
void selectionsort(list& l)   //sap xep danh sach
{
	node* p, * q, * min;
	p = l.phead;
	while (p != l.ptail)
	{

		min = p;
		q = p->pnext;
		while (q != l.phead)
		{
			if (q->data < p->data)
				min = q;
			q = q->pnext;
		}
		swap(min, p);
		p = p->pnext;
	}
}


int main(){
	list l;
	createlist(l);
	input(l);


	while(1){
		cout<<"What do you want to do:"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"1. Add node to the head"<<endl;
		cout<<"2. Add node to the tail"<<endl;
		cout<<"3. Delete the head node"<<endl;
		cout<<"4. Delete the node with a specific value"<<endl;
		cout<<"5.Sort list"<<endl;
		cout<<"6. Print list"<<endl;
		int choice;
		int data=0;
		cin>>choice;
		if(choice == 0){
			break;
		}
		else{
			switch(choice){
				case 1:
				{
					cout<<"Input data:";
					cin>>data;
					node *p = createnode(data);
					addhead(l,p);
					break;
				}
				case 2:
				{
				 	cout<<"Input data:";
					cin>>data;
					node *p = createnode(data);
					addtail(l,p);
					break;
				}
				case 3:
				{
					removehead(l,0);
					break;
				}
				case 4:
				{
					cout<<"Input data:";
					cin>>data;
					RemoveX(l,data);
					break;
				}
				case 5:
				{
					selectionsort(l);
					break;
				}
				case 6:
				{
					output(l);
					break;
				}
				default:
				{
					cout<<"not a valid input"<<endl;
					break;
				}
			}
		}
	}
}

