#pragma once
#include"Node.h"
#include<string>
#include<fstream>

class Poly
{
private:
	Node* Head, * Tail;

public:
	Poly();
	Poly(const int[], const int[], int, string);
	void destroy();
	~Poly();
	Poly(const Poly&);
	void addNode(Node*);
	Node* getHead();
	Node* getTail();
	void setHead(Node*);
	void setTail(Node*);
	friend ostream& operator << (ostream&, const Poly&);
	friend istream& operator >> (istream&, Poly&);
	friend Poly operator + (const Poly&, const Poly&);
	void operator = (const Poly&);
	void merge(Poly&);
	void Delete(int);
	int Degree();
	int Eval(int);
};

void read_poly(Poly&);