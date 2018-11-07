#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <fstream>
using namespace std;

	
int counter=0;
string str;
static stack<char> values;
static bool check= false;
static char lex;

static char f='n';

void B();
void IT(); 
void IT_Tail();
char get();
void L();
void AT_Tail();
void AT();
void OT();
void OT_Tail();



int main(){
	
	fstream myfile;
	myfile.open("expression.txt");
	if(!myfile.eof()){
		getline(myfile,str);
		
	}
	
	B();

	myfile.close();
	
	
return 0;}
			
		
	 char get(){
		
		lex =str.at(counter++);
		
		cout<<lex;

		if( lex== 'T'){
			return lex;
		}
		else if(lex == 'F'){
			return lex;
		}

		else if(lex == '-'){
			lex = str.at(counter++);
			if( lex == '>'){
				cout<<lex;
		  		return 'I';
			}
			else{
				cout<<"expected '>'"<<endl;
			}
    		}
		

		else if (lex =='.'){
			return lex;
		}
		
		else if( lex =='v'){
			return lex;
		}
		else if( lex =='('){
			return lex;
		}
		else if( lex ==')'){
			return lex;
		}
		else if( lex =='~'){
			return lex;
		}
		else if( lex == '&'){
			return lex;
		}

		else if(lex =='-'){
			return lex;
		}
		else if(lex =='\n'){
			return lex;
		}
		else{
			cout<<"error!\n"<<endl;
			cout<<"expected v, &, T, F, ->, but got  "<<lex; 
			return lex;

		}
  }
  void A(){
	    if(check == false){
	      lex= get();
	      check = true;
	    }
	    if(f == '~'){
	      //cout<<"Negation";
	      if(lex == 'F'){
		values.push('T');
	      }
	      else{
		values.push('F');
	      }
	      f='e';
	      check=false;
	      return;
	    }
	    else if((lex == 'T')||( lex == 'F')){

	      values.push(lex);
	      check = false;
	      return;
	    }
	    else if(lex == '('){
	      check = false;
	      IT();
	      if (check == false){
	         lex = get();
	         check= true;
	      }
	   
	      if(lex == ')'){
		check = false;
		return;
	      }
	       
	    }
	    return;
   

  }
  void L(){
    
    
	    if (check == false){
		lex = get();
		check= true;
	    }
	    A();
	    if(lex=='~'){
	      
	      check= false;
	      f = lex;
	      L();
	      return;
	    } 
	    
	    return;
	  }

  void AT_Tail(){
	
      char e;
      char d;
      if(check == false){
        lex = get();
        check = true;
      }
      if(lex == '&'){
          lex = get();
          d= values.top();
  
          values.pop();
        //  cout<<d;
          
          L();
          e= values.top();
          values.pop();
         // cout<<e;

          if((d == 'T')&& (e == 'T')){
            values.push('T');
            
          }
          else if((d == 'T')&& (e == 'F')){
            values.push('F');
            
          }
          else if((d == 'F')&& (e == 'T')){
            values.push('F');
            
          }
          else if((d == 'F') &&(e == 'F')){
            values.push('F');
          }
          //check = false;
          AT_Tail();
          
      }
    return;
  }

  void AT(){
  
    L();
    AT_Tail();
    return;
  }

  void OT_Tail(){
	
      char e; 
      char d;
      if (check== false){
        lex= get();
        check = true;
      }
      if(lex == 'v'){
          lex= get();
          d = values.top();
          values.pop();
          //cout<<d;
          AT();
          e = values.top();
          values.pop();
          //cout<<e;
          if ((e == 'T')&&(d == 'T')){
              values.push('T');
          }
          else if ((e == 'T')&&(d == 'F')){
              values.push('T');
          }
          else if ((e == 'F')&& (d == 'T')){
              values.push('T');
          }
          else if ((e == 'F')&& (d == 'F')){
              values.push('F');
          }
        OT_Tail();

      }
    return;
  }
  void IT_Tail(){

      char e;
      char d;
      if(check == false){
        lex= get();
        check = true;
      }
      
      if( lex== 'I'){
         
         lex = get();
         d = values.top();
         values.pop();
         //cout<<d;
         L();
         e = values.top();
         values.pop();
         //cout<<e;
          if ((d == 'T')&& (e== 'T')){
              values.push('T');
          }
          else if ((d == 'T')&& (e == 'F')){
              values.push('F');
              
          }
          else if ((d == 'F')&&(e == 'T')){
              values.push('T');
          }
          else if ((d == 'T')&&(e == 'T')){
              values.push('T');
          }
          else{
            values.push('T');
          }
        //check = false;
        IT_Tail();
        
      }
    return;
  }

  void OT(){
    
    AT();
    OT_Tail();
    return;

  }


  void IT(){
    
    OT();
    IT_Tail();
    return;
    
  }

  void B(){
	
      char e;
      
      
      IT();
      if(check == false){
        lex= get();
        check = true;
      }
    
      if (lex == '.'){
          e=values.top();
          cout<<"\n"<<e<<endl;
          return;
          
      }

      
  }


	

