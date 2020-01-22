int ps = 0;
int u = 1;
int d = 2;
int l = 3;
int r = 4;

int p_square = 5;
int p_triangle = 6;
int p_cross = 7;
int p_circle = 8;

int l1 = 9;
int r1 = 10;
int l2 = 11;
int r2 = 12;

int start = A1;
int select = A2;


void setup() {
  // put your setup code here, to run once:
 pinMode(ps,OUTPUT);
 pinMode(u,OUTPUT);
 pinMode(d,OUTPUT);
 pinMode(l,OUTPUT);
 pinMode(r,OUTPUT);
 pinMode(p_square,OUTPUT);
 pinMode(p_triangle,OUTPUT);
 pinMode(p_cross,OUTPUT);
 pinMode(p_circle,OUTPUT);
 pinMode(l1,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r2,OUTPUT);
 
 pinMode(start, OUTPUT);
 pinMode(select, OUTPUT); 
 
// 让14号口电位为正
 digitalWrite(ps, LOW);
 digitalWrite(u, LOW);
 digitalWrite(d, LOW);
 digitalWrite(l, LOW);
 digitalWrite(r, LOW);
 digitalWrite(p_square, LOW);
 digitalWrite(p_triangle, LOW);
 digitalWrite(p_cross, LOW);
 digitalWrite(p_circle, LOW);  
 digitalWrite(l1, LOW);  
 digitalWrite(r1, LOW);  
 digitalWrite(l2, LOW);  
 digitalWrite(r2, LOW); 
 digitalWrite(start, LOW);  
 digitalWrite(select, LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // 14号口被短路到地,也就是触发按钮按下事件 
    digitalWrite(ps,HIGH); 
    delay(500);
    digitalWrite(ps,LOW);  
    digitalWrite(u,HIGH); 
    delay(500);
    digitalWrite(u,LOW);  
    digitalWrite(d,HIGH);  
    delay(500);
    digitalWrite(d,LOW);
    digitalWrite(l,HIGH);
    delay(500);
    digitalWrite(l,LOW);
    digitalWrite(r,HIGH);
    delay(500);
    digitalWrite(r,LOW);
    digitalWrite(p_square,HIGH);
    delay(500);
    digitalWrite(p_square,LOW);
    digitalWrite(p_triangle,HIGH);
    delay(500);
    digitalWrite(p_triangle,LOW);
    digitalWrite(p_cross,HIGH);
    delay(500);
    digitalWrite(p_cross,LOW);
    digitalWrite(p_circle,HIGH);
    delay(500);
    digitalWrite(p_circle,LOW);       

    digitalWrite(l1,HIGH);
    delay(500);
    digitalWrite(l1,LOW); 

    digitalWrite(r1,HIGH);
    delay(500);
    digitalWrite(r1,LOW); 

    digitalWrite(l2,HIGH);
    delay(500);
    digitalWrite(l2,LOW); 

    digitalWrite(r2,HIGH);
    delay(500);
    digitalWrite(r2,LOW);       
    digitalWrite(start,HIGH);
    delay(500);
    digitalWrite(start,LOW);  

    digitalWrite(select,HIGH);
    delay(500);
    digitalWrite(select,LOW);      
}
