#include <LedControl.h>

LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=125;

int seq1[] = {0,1,2,3,4,5,6,7};
int seq2[] = {0,1,2,3,4,5,6,7};
int seq3[] = {0,1,2,3,4,5,6,7};
int seq1_2[] = {0,1,2,3,4,5,6,7};
int seq2_3[] = {0,1,2,3,4,5,6,7};
int seq1_2_3[] = {0,1,2,3,4,5,6,7};
//array len - 1
int arraylen = 7;

int cnt = 0;

//store the state of the switches 0 = normal,1 = reset,2 = pingpong
int dir[] = {0,0,1,2,0,0,0,0};

int mode = 0;

int stepamt = 1;

int steps[] = {1,0,-1};

void setup() {
  // put your setup code here, to run once:
lc.shutdown(0,false);

lc.setIntensity(0,8);

lc.clearDisplay(0);

Serial.begin(115200);
Serial.println(arraylen);
}




void loop() {
  // put your main code here, to run repeatedly:
if(cnt == 0 & dir[cnt] == 0){
  mode = 0;
}
else if(dir[cnt] == 1){
  mode = 1;
}
else if(dir[cnt] == 2){
  mode = 2;
}


stepamt = steps[mode];

Serial.println(mode);
display_word(seq1[cnt],cnt);
//Serial.println(steps[mode]);
cnt = cnt + stepamt;
switch(mode){
  case 0:
  if ( cnt == 8){
    cnt = 0;
  }
  break;

  case 1:
    cnt = 0;
  break;

  case 2:
  if(cnt < 0){
    cnt = 7;
  }
  break;
}


delay(delaytime);
  }




void display_word(int disp, int add){
  lc.clearDisplay(0);
lc.setChar(0, add, disp, false);
}