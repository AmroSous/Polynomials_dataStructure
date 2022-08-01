#include "Node.h"

Node::Node()
{
	coefficient = degree = 0;
	next = nullptr;
}

Node::Node(int coeff, int degg)
	: coefficient(coeff), degree(degg)
{
	next = nullptr;
}

Node::Node(const Node& node)
{
	coefficient = node.coefficient;
	degree = node.degree;
	next = NULL;
}

void Node::set_next(Node* node)
{
	next = node;
}

Node* Node::get_next()
{
	return next;
}

int Node::get_coeff()
{
	return coefficient;
}

int Node::get_deg()
{
	return degree;
}

void Node::set_coeff(int n)
{
	coefficient = n;
}

ostream& operator<<(ostream& os, const Node& node)
{
	if (node.coefficient == 0) { os << 0; return os; }
	if (node.degree == 0) os << node.coefficient;
	else
	os << node.coefficient << "x^" << node.degree;
	return os;
}

istream& operator>>(istream& is,Node* node)
{
	int num = 0;
	is >> num;
	if (is.fail())
	{
		is.clear();
		is.ignore(1000, '\n');
		num = 0;
	}
	node->coefficient = num;
	is.ignore();
	is.get();
	is >> num;
	if (is.fail())
	{
		is.clear();
		is.ignore(1000, '\n');
		num = 0;
	}
	node->degree = num;
	return is;
}

int print_menu()
{
	int choice;
	cout << "\n\n         ---> Menu <---" << endl;
	cout << "\n   1) Change the polunomial you enterd."
		<< "\n   2) Print the polynomial."
		<< "\n   3) Add a node to the polynomial."
		<< "\n   4) Delete a specified node from the polynomial."
		<< "\n   5) Evaluate the function at certain point."
		<< "\n   6) Add another polynomial to it and store the result in third one."
		<< "\n   7) Find the degree of the polynomial."
		<< "\n   8) Merging another polynomial into it."
		<< "\n   9) Exit." << endl
		<< "\n   Choose from the list : "; cin >> choice;
	while (cin.fail() || choice > 9 || choice < 1)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n   Invalid input .. choose from the list : "; cin >> choice;
	}
	return choice;
}
