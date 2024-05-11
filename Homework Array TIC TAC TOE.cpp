#include<iostream>
#include<string>
#include<math.h>
using namespace std;
	char cell[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int r,c; 
	int total=0;
	int num;
	string name1,name2;
	char pickSign='x';
	bool result=false;
		
void drawStructure ()
{	
	
	cout<<"\t     |     |"<<endl;
	cout<<"\t"<<cell[0][0]<<"    |"<<cell[0][1]<<"    |"<<cell[0][2]<<endl;
	cout<<"\t_____|_____|_____"<<endl;
	cout<<"\t     |     |"   <<endl;
	cout<<"\t"<<cell[1][0]<<"    |"<<cell[1][1]<<"    |"<<cell[1][2]<<endl;
	cout<<"\t_____|_____|_____"<<endl;
	cout<<"\t     |     |     "<<endl;
	cout<<"\t"<<cell[2][0]<<"    |"<<cell[2][1]<<"    |"<<cell[2][2]<<endl;
	cout<<"\t     |     |     "<<endl;
	
}

void checkTurn()
{	

		if(pickSign=='x'){
		cout<<"\t"<<name1<<", please enter:";
		cin>>num;
	}
	if(pickSign=='0'){
		cout<<"\t"<<name2<<", please enter:";
		cin>>num;
	}
	if(num==1){
		r=0;
		c=0;
	}
	if(num==2){
		r=0;
		c=1;
	}
	if(num==3){
		r=0;
		c=2;
	}
	if(num==4){
		r=1;
		c=0;
	}
	if(num==5){
		r=1;
		c=1;
	}
	if(num==6){
		r=1;
		c=2;
	}
	if(num==7){
		r=2;
		c=0;
	}
	if(num==8){
		r=2;
		c=1;
	}
	if(num==9){
		r=2;
		c=2;
	}
	else if(num<1||num>9){
		cout<<"Invalid number!"<<endl;
	}

	if(pickSign=='x'&&cell[r][c]!='x'){
		cell[r][c]='x';
		pickSign='0';
		total++;
		
	}
	else if(pickSign=='0'&&cell[r][c]!='0'){
		cell[r][c]='0';
		pickSign='x';
		total++;
	}
	
	return ;	
}

bool evaluateWin_Lost(){
		int reslut;
		for (int i = 0; i < 3; i++){
			if (cell[i][0] == cell[i][1] && cell[i][0] == cell[i][2]||
			cell[0][i] == cell[1][i] && cell[0][i] == cell[2][i]) {
				
				return true;
			}
		}	
	if (cell[0][0]==cell[1][1] && cell[1][1]==cell[2][2]||
		cell[0][2]==cell[1][1] && cell[1][1]==cell[2][0]){
			
			return true;
		}
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (cell[i][j]!='X' && cell[i][j]!='0'){
					
					return false;
				}
			}
		}		
		result==true;
		return false;
}
	
int main(){

	cout << "Please enter the first player name1:";cin>>name1;fflush(stdin);cin.clear();
	cout << "Please enter the second player name2:";cin>>name2;fflush(stdin);cin.clear();
	cout <<endl;
	cout << name1 << " is player1 => so he/she will play first" << endl;
	cout << name2 <<" is player2 => so he/she will play second" << endl; 
	while (!evaluateWin_Lost()){
		system("cls");
		drawStructure ();
		checkTurn();
		evaluateWin_Lost();
	}
	

	if(pickSign=='X' && result==false) {
		cout<<name2<<"is Wons!"<<endl;
	
	}
	else if(pickSign=='0'&&result==false){
		cout << name1 << " is Wins!!" << endl; 
		
	}
	if(pickSign=='X' && result==false){
		cout<<"\n\t"<<name2<<" : is Wins!!"<<endl;
	}
	else if(pickSign=='0' && result==false){
		cout<<"\n\t"<<name1<<" : is Wins!!"<<endl;
	}
	else{
		if(total>=9){
			cout<<"\n\tThere is no empty space."<<endl;
		}
			cout<<"\n\tThis game is draw!"<<endl;						
		}
				 
}
	