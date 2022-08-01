#pragma once
#include<iostream>
using namespace std;


struct Node                // 
{
private:
	int coefficient, degree;
	Node* next;

public:
	Node();
	Node(int, int);
	Node(const Node&);
	void set_next(Node*);
	Node* get_next();
	int get_coeff();
	int get_deg();
	void set_coeff(int);
	friend ostream& operator << (ostream&, const Node&);
	friend istream& operator >> (istream&, Node*);
};

int print_menu();