z1=2-j*3;
z2=-2+j*3;
z3=z1-z2; 
z4=z1/z2;


A1=2;
A2=4;
w=1000*pi;
f=w/(2*pi);
T=1/f;


t=linspace(0,2*T,100);



v1=A1*cos(w*t);
v2=A2*cos(w*t+pi/4);



plot(t,v1+v2);
z5=2+j*0;
z6=2.83+j*2.83;

