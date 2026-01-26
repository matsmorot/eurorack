#include <MsTimer2.h>//timer count
#include <avr/io.h> //for fast PWM
#include <ezLED.h>

ezLED led(12);

int PWM = 0;
int constant[256];
int clk_led = 13;
int moon_led = 12;
int moon_led_state = LOW;
bool clk_check, clk_in, mode;
bool old_clk_in = 0;
unsigned long clk_count;
int clk_time1, clk_time2, clk_time_ave, buf_dt, search_dt, cmp1, cmp2,divide;

void setup() {
  TCCR1B &= B11111000;//fast pwm setting
  TCCR1B |= B00000001;//fast pwm setting

  pinMode(1, INPUT_PULLUP); // JACK CHECK
  pinMode(2, INPUT); //CLK IN
  pinMode(9, OUTPUT); //delay time control
  //pinMode(moon_led, OUTPUT);//delay time LED
  pinMode(clk_led, OUTPUT);//clk LED

  led.toggle();

  for (int i = 0; i <= 255; i++) {
    constant[i] = 776.48 * pow(i, -0.6586);//prepare clock sync time table
  }
  clk_count = 0;
  
  //Serial.begin(9600);//for calibration
  
  MsTimer2::set(1, timer_count); // timer count per 1 msec
  MsTimer2::start();//
}

void timer_count() {
  clk_count ++;
}

void loop() {
  led.loop();
  clk_check = digitalRead(1);
  old_clk_in = clk_in;
  clk_in = digitalRead(2);//read external clock signal
  
  //digitalWrite(moon_led, PWM);
  digitalWrite(clk_led, clk_in);//LED light sync external clock signal
  
  if (old_clk_in == 0 && clk_in == 1) {
    clk_time2 = clk_time1;
    clk_time1 = clk_count;
    clk_time_ave = (clk_time2 + clk_time1) / 2;
    clk_count = 0;
  }

  if (clk_check == 0) {
    mode = 0; //clock sync mode
    
    divide = map(min(1023, analogRead(1) + analogRead(5)), 0, 1023, 1, 6);
    buf_dt = clk_time_ave / divide;

    if (buf_dt > 80) {
      for ( search_dt = 255; search_dt >= 0 ; search_dt-- ) {// quantize
        if ( buf_dt < constant[search_dt] && buf_dt >= constant[search_dt + 1]) {
          cmp1 = constant[search_dt] - buf_dt; //Detect closest note
          cmp2 = buf_dt - constant[search_dt + 1];//Detect closest note
          break;
        }
      }
      if (cmp1 <= cmp2) {//Detect closest note
        PWM = max(5, search_dt + 1);
        PWM = min(PWM, 255);
      }
      else if (cmp2 < cmp1) {//Detect closest note
        PWM = max(5, search_dt);
        PWM = min(PWM, 255);
      }
    }
    else if (buf_dt <= 80) {//glitch noise countermeasure
      PWM = 255;
    }
  } else if (clk_check == 1){// when no clock input
    mode = 1; //no sync mode
    PWM = map(min(1023, analogRead(1) + analogRead(5)), 0, 1023, 1, 255);
  }

  analogWrite(9, PWM);
  //Serial.print(analogRead(1));// for calibration
  //Serial.print(",");// for calibration
  //Serial.print(PWM);// for calibration
  //Serial.println("");// for calibration
}