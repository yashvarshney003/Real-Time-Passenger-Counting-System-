#include <SoftwareSerial.h>
SoftwareSerial s(4,7);
 int ldr_min_val = 400;
int sensor1= 0;
int sensor2= 0;
int sensor3= 0;
int sensor4= 0;
int step_old= 10;
int steps = 10;
int step_old1= 10;
int steps1 = 10;
int pulse_count1 = 0;
 int person_count = 0;
int pulse_count = 0;
int person_count1 = 0;
int total_person = 0;
int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;
int ldr1_value = 0;
int ldr2_value = 0;
int ldr3_value = 0;
int ldr4_value = 0;
void setup()
{
  Serial.begin(9600);
  s.begin(9600);
   
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(ldr3,INPUT);
  pinMode(ldr4,INPUT);
}

void loop()
{
  ldr1_value = analogRead(ldr1);
   ldr2_value = analogRead(ldr2);
   ldr3_value = analogRead(ldr3);
   ldr4_value = analogRead(ldr4);
 Serial.println(ldr1_value);
   Serial.println(ldr2_value);
Serial.println(ldr3_value);
Serial.println(ldr4_value);
    if(ldr1_value < ldr_min_val)
  { 
   sensor1 = 1; 
    }
   else{
    sensor1 = 0;
    }
 if(ldr2_value < ldr_min_val)
  {  sensor2 = 1; }
   else{
    sensor2 = 0;
    }
    if(ldr3_value < ldr_min_val)
  { sensor3 = 1; 
    }else{
    sensor3 = 0;
    }
if(ldr4_value < ldr_min_val)
  { sensor4 = 1; 
    }
   else{
    sensor4 = 0;
    }

       if(sensor1 == 1 && sensor2 == 1){
             steps = 0;
          if(step_old == 1){
             pulse_count-- ;
                                                                              }
                                                                              if(step_old == 3){
                                                                                pulse_count++;
                                                                              }
                                                                              step_old = 0;
                                                                            }

                                                                                  if(sensor1 == 0 && sensor2 == 1){
                                                                                    steps = 1;
                                                                                    if(step_old == 2){
                                                                                      pulse_count--;
                                                                                    }
                                                                                    if(step_old == 0){
                                                                                      pulse_count++;
                                                                                    }
                                                                                    step_old = 1;
                                                                                  }

                                                                                        if(sensor1 == 0 && sensor2 == 0){
                                                                                        steps = 2;
                                                                                        if(step_old == 3){
                                                                                          pulse_count--;
                                                                                        }
                                                                                        if(step_old == 1){
                                                                                          pulse_count++;
                                                                                        }
                                                                                        step_old = 2;
                                                                                      }
                                                                                    
                                                                                          if(sensor1 == 1 && sensor2 == 0){
                                                                                            steps = 3;
                                                                                            if(step_old == 0){
                                                                                              pulse_count--;
                                                                                            }
                                                                                            if(step_old == 2){
                                                                                              pulse_count++;
                                                                                            }
                                                                                            step_old = 3;
                                                                                          }
  
if(sensor3 == 1 && sensor4 == 1){
    steps1 = 0;
    if(step_old1 == 1){
      pulse_count1-- ;
    }if(step_old1 == 3){
      pulse_count1++;
    }step_old1 = 0;
  } if(sensor3 == 0 && sensor4 == 1){
    steps1 = 1;
    if(step_old1 == 2){
      pulse_count1--;}
    if(step_old1 == 0){
      pulse_count1++;
    }step_old1 = 1;
  }if(sensor3 == 0 && sensor4 == 0){
    steps1 = 2;
    if(step_old1 == 3){
      pulse_count1--;}
    if(step_old1 == 1){
      pulse_count1++;}
    step_old1 = 2;
  }if(sensor3 == 1 && sensor4 == 0){
    steps1 = 3;
    if(step_old1 == 0){
      pulse_count1--;}
      if(step_old1 == 2){
      pulse_count1++;}
      step_old1 = 3;}

  
  
  if(pulse_count<0){
    if(pulse_count1<= 0){
    
  pulse_count = 0;
  }
  }
if(pulse_count1<0){ 
  if(pulse_count<= 0){
  pulse_count1 = 0;
  }
}

  person_count = pulse_count/4;
  person_count1 = pulse_count1/4;
   total_person = 0 ;
   total_person= person_count + person_count1;
  




  
  Serial.print(" number of people in the bus");
  Serial.println(total_person);
  if(s.available()>0)
{
 s.write(total_person);
 delayMicroseconds(200);
}
}
