#include "Poly.h"

Poly::Poly()
{
	Head = Tail = nullptr;
}

Poly::Poly(const int coeff[], const int power[], int size, string name)
{
	Head = Tail = NULL;
	Node* tmp;
	int i;
	for (i = 0; i < size; i++)
	{
		tmp = new Node(coeff[i], power[i]);
		addNode(tmp);
	}
}

void Poly::destroy()
{
	Node* tmp = Head;
	while (tmp != NULL)
	{
		Head = (Head->get_next());
		delete tmp;
		tmp = Head;
	}
	Tail = Head = NULL;
}

Poly::~Poly()
{
	destroy();
}

Poly::Poly(const Poly& poly)
{
	Head = Tail = NULL;
	Node* tmp = poly.Head;
	Node* node;
	while (tmp != NULL)
	{
		node = new Node(*tmp);
		addNode(node);
		tmp = (tmp->get_next());
	}
}

void Poly::addNode(Node* node)
{
	if (this->Head == NULL) { Head = Tail = node; return; }

	Node* ptr1 = Head, *ptr2 = (Head->get_next());

	if ((node->get_deg()) == (ptr1->get_deg()))
	{
		ptr1->set_coeff((ptr1->get_coeff()) + (node->get_coeff()));
		return;
	}
	else if ((node->get_deg()) < (ptr1->get_deg()))
	{
		node->set_next(Head);
		Head = node;
		return;
	}

	while (ptr2 != NULL)
	{
		if ((node->get_deg()) == (ptr2->get_deg()))
		{
			ptr2->set_coeff((ptr2->get_coeff()) + (node->get_coeff())); return;
		}
		else if ((node->get_deg()) < (ptr2->get_deg()))
		{
			ptr1->set_next(node);
			node->set_next(ptr2);
			return;
		}
		ptr1 = ptr2;
		ptr2 = (ptr2->get_next());
	}
	ptr1->set_next(node);
	Tail = node;
}

Node* Poly::getHead()
{
	return Head;
}

Node* Poly::getTail()
{
	return Tail;
}

void Poly::setHead(Node* node)
{
	Head = node;
}

void Poly::setTail(Node* node)
{
	Tail = node;
}

void Poly::operator=(const Poly& poly)
{
	destroy();
	Node* tmp = poly.Head;
	Node* node;
	while (tmp != NULL)
	{
		node = new Node(*tmp);
		addNode(node);
		tmp = (tmp->get_next());
	}
}

void Poly::merge(Poly& poly)
{
	Node* ptr1, *ptr2, *p;
	ptr1 = this->Head;
	ptr2 = poly.Head;

	if (poly.Head == NULL) return;

	if (ptr1->get_deg() == ptr2->get_deg())
	{
		ptr1->set_coeff(ptr1->get_coeff() + ptr2->get_coeff());
		p = ptr2;
		ptr2 = ptr2->get_next();
		delete p;
		p = ptr1;
		ptr1 = ptr1->get_next();
	}
	else if (ptr1->get_deg() < ptr2->get_deg())
	{
		p = ptr1;
		ptr1 = ptr1->get_next();
	}
	else
	{
		Head = p = ptr2;
		ptr2 = ptr2->get_next();
	}
	while ((ptr1 != NULL) && (ptr2 != NULL))
	{
		if (ptr1->get_deg() == ptr2->get_deg())
		{
			ptr1->set_coeff(ptr1->get_coeff() + ptr2->get_coeff());
			p->set_next(ptr1);
			p = ptr2;
			ptr2 = ptr2->get_next();
			delete p;
			p = ptr1;
			ptr1 = ptr1->get_next();
		}
		else if (ptr1->get_deg() < ptr2->get_deg())
		{
			p->set_next(ptr1);
			p = ptr1;
			ptr1 = ptr1->get_next();
		}
		else
		{
			p->set_next(ptr2);
			p = ptr2;
			ptr2 = ptr2->get_next();
		}
	}
	if (ptr2 == NULL)
	{
		p->set_next(ptr1);
		poly.Head = poly.Tail = NULL;
	}
	else if (ptr1 == NULL)
	{
		p->set_next(ptr2);
		Tail = poly.Tail;
		poly.Head = poly.Tail = NULL;
	}
}

void Poly::Delete(int n)
{
	Node* ptr = Head, *dl = Head;
	if (Head == NULL) return;
	if (Head->get_deg() == n)
	{
		Head = Head->get_next();
		delete dl;
		return;
	}
	dl = Head->get_next();
	while (dl != NULL)
	{
		if (dl->get_deg() == n)
		{
			if (dl->get_next() == NULL) Tail = ptr;
			ptr->set_next(dl->get_next());
			delete dl;
			return;
		}
		ptr = dl;
		dl = dl->get_next();
	}
}

int Poly::Degree()
{
	return Tail->get_deg();
}

int Poly::Eval(int n)
{
	int sum(0), mult(1), i;
	Node* ptr = Head;
	while (ptr != NULL)
	{
		mult = 1;
		for (i = 0; i < ptr->get_deg(); i++)
			mult *= n;
		mult *= ptr->get_coeff();
		sum += mult;
		ptr = ptr->get_next();
	}
	return sum;
}

ostream& operator<<(ostream& os, const Poly& poly)
{
	Node* tmp = poly.Head;
	while (tmp != NULL)
	{
		if (tmp == poly.Tail) { os << *tmp; return os; }
		os << *tmp << " + ";
		tmp = (tmp->get_next());
	}
	os << "Empty Polynomial.";  return os;
}

istream& operator>>(istream& is, Poly& poly)
{
	char ch;
	ch = '+';
	Node* tmp;
	while (ch == '+')
	{
		tmp = new Node;
		is >> tmp;
		if (tmp->get_coeff() == 0) { delete tmp; continue; }
		poly.addNode(tmp);
		ch = is.get();
	}
	return is;
}

Poly operator+(const Poly& poly1, const Poly& poly2)
{
	Poly total;
	if (poly1.Head == NULL) return poly2;
	if (poly2.Head == NULL) return poly1;
	Node* node, *ptr;
	ptr = poly1.Head;
	while (ptr != NULL)
	{
		node = new Node(*ptr);
		total.addNode(node);
		ptr = (ptr->get_next());
	}
	ptr = poly2.Head;
	while (ptr != NULL)
	{
		node = new Node(*ptr);
		total.addNode(node);
		ptr = (ptr->get_next());
	}
	return total;
}

void read_poly(Poly& F)
{
	int choice; string filename;
	cout << "\n   Enter the method to read a polynomial and store it : "
		<< "\n\n   1) From a file."
		<< "\n   2) From user keyboard." << endl
		<< "\n\n   Your choice : "; cin >> choice;
	while (cin.fail() || choice < 1 || choice > 2)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n   Invalid input .. choose the method : "; cin >> choice;
	}
	if (choice == 1)
	{
		cout << "\n   Enter the filename(path) to read a polynomial (ex: filename.txt) : "; cin >> filename;
		ifstream input_file(filename, ios::in);
		if (input_file.is_open())
		{
			input_file >> F;
			input_file.close();
			cout << "\n   The polynomial was read successfully." << endl;
		}
		else cout << "\n\n   Sorry .. failed in open the file." << endl;
	}
	else if (choice == 2)
	{
		cout << "\n   Write a polynomial without spaces (ex: 2x^2+3x^0) : "; cin >> F;
		cout << "\n\n   The polynomial was read successfully." << endl;
	}
}