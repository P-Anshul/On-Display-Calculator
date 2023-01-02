#include<simplecpp>
struct button{
    // x is X cordinate, y is Y cordinate,w is width, h is height
    int x,y,w,h;
    button(const char*name,int xx,int yy,int ww,int zz){
        x=xx;y=yy;w=ww;h=zz;
        Rectangle(x,y,w,h).imprint();
        Text(x,y,name).imprint();
        //making button
    }
    bool in(int click){
        int cx=click/65536,cy=click%65536;
        return(abs(cx-x)<=w-10 && abs(cy-y)<=h-15);
        //checking is the click is inside button or not
    }
};

main_program{
    initCanvas("CALCULATOR BY ANSHUL",250,350);
    double a[2]={0,0},b[2]={70,190},temp=0;
    int i=0;
    char y;
    Text t3(125,150,"CALCULATOR BY ANSHUL");
    wait(1);
    t3.reset(190,50,"");      // to display result
    Text t1(70,30,"");      // to print 1st input
    t1.imprint();
    Text t2(190,30,"");     // to print 2nd input
    t2.imprint();
    Text t4;                  //to print operator(+,-,*,/)
    t4.imprint();
    Rectangle(125,40,190,60).imprint();  //display
    button b1("7",50,100,40,40);         //buttons
    button b2("8",100,100,40,40);
    button b3("9",150,100,40,40);
    button b4("/",200,100,40,40);
    button b5("4",50,150,40,40);
    button b6("5",100,150,40,40);
    button b7("6",150,150,40,40);
    button b_("*",200,150,40,40);
    button b8("1",50,200,40,40);
    button b9("2",100,200,40,40);
    button b10("3",150,200,40,40);
    button b11("+",200,200,40,40);
    button b12("0",50,250,40,40);
    button b13("Exit",100,250,40,40);
    button b14("=",150,250,40,40);
    button b15("-",200,250,40,40);
    button b16("CE",50,300,40,40);
    button b17("Ac",100,300,40,40);
    button b18("",150,300,40,40);
    button b19("",200,300,40,40);
    while(true){
        int key=getClick();      //taking input from mouse click
        if(b1.in(key)){
            a[i]=a[i]*10+7;       // taking button inputs and varifying
        }
        else if(b2.in(key)){
            a[i]=a[i]*10+8;
        }
        else if(b3.in(key)){
            a[i]=a[i]*10+9;
        }
        else if(b5.in(key)){
            a[i]=a[i]*10+4;
        }
        else if(b6.in(key)){
            a[i]=a[i]*10+5;
        }
        else if(b7.in(key)){
            a[i]=a[i]*10+6;
        }
        else if(b8.in(key)){
           a[i]=a[i]*10+1;
        }
        else if(b9.in(key)){
           a[i]=a[i]*10+2;
        }
        else if(b10.in(key)){
           a[i]=a[i]*10+3;
        }
        else if(b12.in(key)){
            a[i]=a[i]*10+0;
        }
        else if(b16.in(key)){
            a[i]=int(a[i]/10);
        }
        else if(b4.in(key)){
            y='/';
            a[1]=0;
            if(i==0){
                t4.reset(130,30,"/");
                i++;
            }
            else{
                a[0]=temp;      //if it is repeated time calculation
                i=1;
                t4.reset(130,30,"/");
                t2.reset(b[0],30,temp);
            }
        }
        else if(b_.in(key)){
            y='*';
            a[1]=0;
            if(i==0){
                t4.reset(130,30,"*");
                i++;
            }
            else{
                a[0]=temp;
                i=1;
                t4.reset(130,30,"*");
                t2.reset(b[0],30,temp);
            }
        }
        else if(b11.in(key)){
            y='+';
            a[1]=0;
            if(i==0){
                t4.reset(130,30,"+");
                i++;
            }
            else{
                a[0]=temp;
                i=1;
                t4.reset(130,30,"+");
                t2.reset(b[0],30,temp);
            }
        }
        else if(b15.in(key)){
            y='-';
            a[1]=0;
            if(i==0){
                t4.reset(130,30,"-");
                i++;
            }
            else{
                a[0]=temp;
                i=1;
                t4.reset(130,30,"-");
                t2.reset(b[0],30,temp);
            }
        }
        else if(b17.in(key)){
            a[0]=0;a[1]=0;i=0;
            t1.reset(b[i],30,a[1]);
            t4.reset(130,30," ");
        }
        else if(b13.in(key)){
            break;
        }
        t1.reset(b[1],30,a[1]);
        t2.reset(b[0],30,a[0]);
        if(y=='+'){            //perfoming operations
            temp=a[0]+a[1];
        }
        else if(y=='-'){
            temp=a[0]-a[1];
        }
        else if(y=='*'){
            temp=a[0]*a[1];
        }
        else if(y=='/'){
            temp=a[0]/a[1];
        }
        if(b14.in(key)){//= key
            a[0]=temp;
            i=0;
        }
        t3.reset(190,50,temp);
    }
    Rectangle r(125,175,250,350);          //ShutDown of calculator
    r.setColor(COLOR("blue"));
    r.setFill();
    r.imprint();
    Text t(125,150,"THANKS FOR USING MY CALCULATOR");
    t.setColor(COLOR("red"));
    t.imprint();
    wait(5);
    return 0;
}
