#include<iostream>
using namespace std;

namespace family{
	class Tree {

		string name;
		int sex=0;
		int level=0;
		Tree *father = NULL;
		Tree *mother = NULL;


		public:
		Tree *ptr=NULL;

		Tree( string text );
		Tree( );
		Tree& addFather( string text, string text2 );
		Tree& addMother( string text, string text2 );
		string relation( string text );
		string find( string text );
		void display();
		void remove( string text );
		


		void print(Tree *p);
		void search(Tree *t, string n);
		void searchR(Tree *t,string n);
		void searchF(Tree *t, int sex, int lev);
		void so();
	};
}


