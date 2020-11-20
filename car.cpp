# include <iostream>
# include <unistd.h>
# include <cstdio>
# include "car.h"
# include <fstream>

using namespace std;

bool gameover(int i){
  if (i>5){
    return true;
  }
  else{
    return false;
  }
}

void jump(){
  //system("clear");
  for (int i=0;i<=3;i++){
    cout<<" "<<endl;
  }
  cout<<"                                                   "<<"ooooo"<<endl;
  for (int i=0;i<=2;i++){
    cout<<" "<<endl;
  }
}

void run(){
  ifstream fin;
  fin.open("car1.txt");
  if (fin.fail()){
    cout<<"error in file opening"<<endl;
    exit(1);
  }
  string msg;
  while (getline(fin,msg)){
    cout<<msg<<endl;
  }
  fin.close();
  usleep(3000000);
  int count=0;
  //Each while loop represent several continuous pictures appearing one-by-one to create the animation effects
  //The animation will repeat for 5 times.
  //The text shown in the interface will be cleared periodically and new pictre will appear immediately
  while (!gameover(count)){
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"  ####################  ####################  ####################  ####################"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"#  ####################  ####################  ####################  ###################"<<endl;
    usleep(100000);


    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"##  ####################  ####################  ####################  ##################"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"###  ####################  ####################  ####################  #################"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"####  ####################  ####################  ####################  ################"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"#####  ####################  ####################  ####################  ###############"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"######  ####################  ####################  ####################  ##############"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"#######  ####################  ####################  ####################  #############"<<endl;
    usleep(100000);


    char x=getchar();
    if (x=='a'){
      system("clear");
      for (int i=0;i<=3;i++){
        cout<<" "<<endl;
      }
      cout<<"                                                   "<<"ooooo"<<endl;
      for (int i=0;i<=1;i++){
        cout<<" "<<endl;
      }
      cout<<"########  ####################  ####################  ####################  ############"<<endl;
      usleep(300000);
    }
    else{
      system("clear");
      for (int i=0;i<=5;i++){
        cout<<" "<<endl;
      }
      cout<<"                                                   "<<"ooooo"<<endl;
      cout<<"########  ####################  ####################  ####################  ############"<<endl;
      cout<<"gameOver"<<endl;
      cout<<"You have already dropped into the hole."<<endl;
      break;
      usleep(1000000);
    }


    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"########  ####################  ####################  ####################  ############"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"#########  ####################  ####################  ####################  ###########"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"##########  ####################  ####################  ####################  ##########"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"###########  ####################  ####################  ####################  #########"<<endl;
    usleep(100000);

    //usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"############  ####################  ####################  ####################  ########"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"#############  ####################  ####################  ####################  #######"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"##############  ####################  ####################  ####################  ######"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"###############  ####################  ####################  ####################  #####"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"################  ####################  ####################  ####################  ####"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"#################  ####################  ####################  ####################  ###"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"##################  ####################  ####################  ####################  ##"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"###################  ####################  ####################  ####################  #"<<endl;
    usleep(100000);
    system("clear");
    for (int i=0;i<=5;i++){
      cout<<" "<<endl;
    }
    cout<<"                                                   "<<"ooooo"<<endl;
    cout<<"####################  ####################  ####################  ####################  "<<endl;
    usleep(100000);
    system("clear");
    count++;
  }
  //after 5 times of looping, if the player order 5 jump, he/she will win
  if (count>5){
    cout<<"You have passed all the hole"<<endl;
  }

}
int main(){
  run();
}
