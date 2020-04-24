#include "FamilyTree.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>

using namespace std;
using namespace family;

Tree *tmp=NULL;
Tree *p=NULL;
Tree *pr=NULL;

int x=0;
int y=0;



			Tree::Tree ( string name )
			{
				this->name = name;
				this->sex = 3;
				this->father=NULL;
				this->mother=NULL;
				
			}
			
			Tree& Tree::addFather( string name, string name2 )
			{

					try
					{

						if ( relation(name) == "unrelated" )
							throw std::invalid_argument("Not found this person");


						search(this,name);
						if(ptr->father == NULL)
						{
							x=ptr->level+1;
							ptr->father=new Tree(name2);
							ptr->father->sex=1;
							ptr->father->level=x;
						} else {
							ptr=NULL;
							throw std::invalid_argument("Person exist allredy");
						}
						x=0;
						ptr=this;	
					}
					catch(const std::exception& e)
					{
						std::cerr << e.what() << '\n';

						throw;
					}
					
							

			return *this;

			}


			void Tree::search(Tree *t, string n)
			{
				
				try
				{
					if(t != NULL)
					{
					search(t->father, n);	
					search(t->mother, n);
					if(t->name == n)
						ptr = t;
					}
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() <<"ereeeeeee"<< '\n';
					
				}
				
				
			}

			void Tree::searchR(Tree *t,string n) 
			{
				
				try
				{		
					if(t != NULL)
					{
						searchR(t->father, n);						
						searchR(t->mother, n);
						
						if(t->name == n)
						{
							x=t->level;
							y=t->sex;
						}
							
					}
					
					
				}
				catch(const char* string)
				{
					cout << "CAUGHT IT:" <<string<< endl;
				}
				
				
			}
			void Tree::searchF(Tree *t, int sex, int lev) 
			{
				
				try
				{		
					if(t != NULL)
					{
							searchF(t->father, sex, lev);						
							searchF(t->mother, sex, lev);
						
						if(t->sex == sex && t->level == lev)
						{
							pr=t;
						}
							
					}
					
					
				}
				catch(const char* string)
				{
					cout << "CAUGHT IT:" <<string<< endl;
				}
				
				
			}


			void Tree::print(Tree *p)
			{
				
				if(p!= NULL)
				{
					cout<<p->name<<endl;
					print(p->father);
					print(p->mother);
					
				}
				p=this;
			}
			

			Tree& Tree::addMother( string name, string name2 )
			{
					if ( relation(name) == "unrelated" )
							throw std::invalid_argument("Not found this person");

					try
					{

						search(this,name);
						if(ptr->mother == NULL)
						{
							x=ptr->level+1;
							ptr->mother=new Tree(name2);
							ptr->mother->sex=2;
							ptr->mother->level=x;
						}else{ 
							ptr=NULL;
							throw std::invalid_argument("Person exist allredy");
						}
						x=0;
						ptr=this;	
					}
					catch(const std::exception& e)
					{
						std::cerr << e.what() << '\n';
						throw;
					}
					
							

			return *this;

			};

			string Tree::relation( string text )
			{
				string rela="";
				searchR(this,text);
				x--;
				while(x>1)
				{
					rela+="great-";
					x--;
				} 
				if(x==1)
				{
					rela+="grand";
				}

				if(y == 1)
				{
					rela+="father";
				}
				else if(y == 2)
				{
					rela+="mother";
				}
				else if(y == 3)
				{
					rela="me";
				}
				else
				{
					rela="unrelated";
				}
				
				x=y=0;	
				return rela;
			}

			string Tree::find( string text )
			{

				/*if ( relation(text) == "unrelated" )
					return "unrelated";*/
				try {
					int c=0;
					int g = 1;
					string tmp_name = "";

					//g = 0;
				

					for(int i=0; i<text.size(); i++)
						if(text[i]=='m')
							g = 2;

					if(text == "me")
						return this->name;
					if(text == "father" && this->father != NULL)
						return this->father->name;
					if(text == "mother" && this->mother != NULL)
						return this->mother->name;
					
					for(int i=1; i<text.size()+1; i+=6)
						c++;
					cout<<"sex="<<g<<" level="<<c<<endl;
					pr = NULL;
					searchF(this, g, c);
					
					g=c=0;

						if ( pr != NULL && relation(pr->name) == text ) {
							return pr->name;
						} else {
							throw std::invalid_argument("Not exist person.>>>>>>");
						}
					
					pr=NULL;
					
					
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw;
					return "unrelated";
					
				}

			}

			void Tree::display()
			{
				print(this);
			}

			void Tree::remove( string text )
			{

				if ( relation(text) == "unrelated" )
					throw std::invalid_argument("Not found this person");

				

			}
