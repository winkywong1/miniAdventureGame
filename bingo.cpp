# include <iostream>
# include <fstream>
using namespace std;

int bingo(){
  ifstream fin;
  fin.open("bingo.txt");
  if (fin.fail()){
    cout<<"error in file opening"<<endl;
    exit(1);
  }
  string msg;
  while (getline(fin,msg)){
    cout<<msg<<endl;
  }
  fin.close();
  int card[25],user[25];
  srand(time(NULL));
  for (int i=0;i<25;i++){
    int a=rand()%50;
    card[i]=a;
  }

  int input1, input2;
  int sum, diff, prod, quo;
  for (int i=0;i<5;i++){
    cin>>input1>>input2;
    sum=input1+input2;
    prod=input1*input2;
    if (input1>input2){
      diff=input1-input2;
    }
    else {
      diff=input2-input1;
    }
    if (input1>input2){
      quo=input1/input2;
    }
    else {
      quo=input2/input1;
    }
    user[5*i]=sum;
    user[5*i+1]=diff;
    user[5*i+2]=input1;
    user[5*i+3]=input2;
    user[5*i+4]=sum+diff;
  }

  cout<<"This is the number on our card"<<endl;
  for (int i=0;i<25;i++){
    if (i==4 || i==9 || i==14 || i==19 || i==24){
      cout<<card[i]<<endl;
    }
    else{
      cout<<card[i]<<" ";
    }
  }

  cout<<endl<<endl;

  cout<<"This is the number on your card"<<endl;
  for (int i=0;i<25;i++){
    if (i==4 || i==9 || i==14 || i==19 || i==24){
      cout<<user[i]<<endl;
    }
    else{
      cout<<user[i]<<" ";
    }
  }

  cout<<endl<<endl;
  char x='x';
  for (int i=0;i<25;i++){
    for (int j=0;j<25;j++){
      if (card[i]==user[j]){
        card[i]=0;
      }
    }
  }

  cout<<"This is the number of our card after comparing with your card"<<endl;
  for (int i=0;i<25;i++){
    if (i==4 || i==9 || i==14 || i==19 || i==24){
      cout<<card[i]<<endl;
    }
    else{
      cout<<card[i]<<" ";
      life+=5;
    }
  }


}

int main(){
  bingo();
}
