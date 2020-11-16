void draw()
{
	static int x=0,scr=0;
	if(x==56 && t<4){
	    gameOver=true;
	scr=0;
	speed=40;
	window(36,8,60,9);
	cout<<"Game Over";
	getch();
	window(36,8,60,9);
	cout<<"         ";
	}
	window(74-x,20,80-x,25);
	a=rand%3;
	if (a==0){
	    for (int i=0;i<=10;i++){
	    for (int j=0;j<=10:j++){
	        if (j==10){
	            cout<<"*"<<endl;
	        }
	        else{
	            cout<<"*";
	        }
	    }
	}
	}
	else if (a==1){
	    for (int i=0;i<=5;i++){
	    for (int j=0;j<=5;j++){
	        if (j==10){
	            cout<<"*"<<endl;
	        }
	        else{
	            cout<<"*";
	        }
	    }
	}
	}
	else if (a==2){
	    for (int i=0;i<=10;i++){
	        for (int j=i;j<=10;j++){
	            if (j==10){
	                cout<<"*"<<endl;
	            }
	            else{
	                cout<<"*";
	            }
	        }
	    }
	}
	
	x=x+1;
	if(x==73){
	x=0;
	scr=scr+1;
	window(70,2,80,3);
	cout<<"     ";
	window(70,2,80,3);
	cout<<scr;
	if(speed>20)
		speed--;
	}
}
