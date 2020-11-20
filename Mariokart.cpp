# include <iostream>
# include <unistd.h>
# include <cstdio>

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
  cout<<"Welcome to the volcano land. This is a wonderful land but it has 5 holes. Your mission is to pass all the holes.";
  cout<<"If you want to jump, press certain times of 'a' and then press Enter"<<endl;
  cout<<"YOu just need to make the decision on how many jump you will have"<<endl;
  cout<<"If you fail to jump in anyone of the 5 holes, you will lose the game"<<endl;
  cout<<"You need to make the jumping decision before you start running"<<endl;
  cout<<"For example, if you want to jump for 3 times during the running, you just need to press aaa and the press Enter before you start running"<<endl;
  cout<<"For example, if you press aabaa, you will lose the game"<<endl;
  cout<<"Ready? The game will start soon"<<endl;
  usleep(300000);
  int count=0;
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
  
  if (count>5){
    cout<<"You have passed all the hole"<<endl;
  }

}
int main(){
  run();
}
