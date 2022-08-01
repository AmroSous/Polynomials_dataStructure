#include"Poly.h"
#include<cstdlib>

int main()
{
	Poly F;
	int choice; string filename;
	cout << "\t\t\t                ====< POLYNOMIALS PROGRAM >====" << endl;
	cout << "\n   Description : This program deals with polynomials\n   and provides several operations on them." << endl;
	cout << "\n   --------------------------------------------------------------------------------" << endl;

	read_poly(F);
	system("cls");

	while(1)                    // loop of the menu
	{
		choice = print_menu();
		system("cls");
		if (choice == 9) break;

		switch (choice)
		{
		case 1:
		{
			read_poly(F);
		}
		break;
		case 2:
		{
			cout << "\n   print the polynomial : "
				<< "\n\n   1) on the screen."
				<< "\n   2) on a file."
				<< "\n\n   choose from options : "; cin >> choice;
			while(cin.fail() || choice < 1 || choice > 2)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n   Invalid input .. please choose from options : "; cin >> choice;
			}
			if (choice == 1) { cout << "\n   F(x) = " << F << endl; }
			else if (choice == 2)
			{
				cout << "\n   Enter the filename(path) to print the polynomial (ex: filename.txt) : "; cin >> filename;
				ofstream output_file(filename, ios::out);
				if (output_file.is_open())
				{
					output_file << "F(x) = " << F;
					output_file.close();
					cout << "\n\n   The polynomial was printed successfully.";
				}
				else cout << "\n\n   Sorry .. failed in open the file.";
			}
		}
		break;
		case 3:
		{
			Node* node = new Node;
			cout << "\n   Enter the node you want to append (ex: 3x^1) : "; cin >> node;
			F.addNode(node);
			cout << "\n\n   The node was added successfully.\n\n";
			cout << "\n   F(x) = " << F << endl;
		}
		break;
		case 4:
		{
			int x;
			cout << "\n   Enter the power of the node you want to delete : "; cin >> x;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n   Invalid input .. enter the power of the node you want to delete : "; cin >> x;
			}
			F.Delete(x);
			cout << "\n\n   The node was deleted successfully.\n\n";
			cout << "\n   F(x) = " << F << endl;
		}
		break;
		case 5:
		{
			int x;
			cout << "\n   Enter the value of x to evaluate F(x) : "; cin >> x;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n   Invalid input .. enter the value of x : "; cin >> x;
			}
			cout << "\n   F(" << x << ") = " << F.Eval(x) << endl;
		}
		break;
		case 6:
		{
			Poly G, H;
			cout << "\n   We need to read another polynomial.\n";
			read_poly(G);
			H = F + G;
			cout << "\n   F(x) = " << F << endl;
			cout << "\n   G(x) = " << G << endl;
			cout << "\n   (F+G)(x) = " << H << endl;
		}
		break;
		case 7:
		{
			cout << "\n   The degree of F(x) is : " << F.Degree() << endl;
		}
		break;
		case 8:
		{
			Poly G;
			cout << "\n   We need to read another polynomial.\n";
			read_poly(G);
			F.merge(G);
			cout << "\n   F(x) = " << F << endl;
			cout << "\n   G(x) = " << G << endl;
		}
		break;
		}

		cout << "\n   Press enter to choose another choice .. ";
		cin.ignore();
		cin.get();
		system("cls");
	}

	cout << "\n\n   Ok .. Thank you .\n\n" << endl;    // if exit

	return EXIT_SUCCESS;
}