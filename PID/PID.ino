//Variables globales
float x1 = 0,x2 = 0,x3 = 0, errorSat, ierrorBC;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

float myPID(float error){
  //Step
  float dt = 0.001;

  //Ganancias
  float kp = 155.63;
  float ki = 73.65;
  float kd = 45.38;
  int N = 100, pwm;
  float kb = 2.2095;
  float k1, derror, ierror, CV, CVsinSat;

  //Derivada del error
  derror = N*(-x1+error);
  x1 = x1+(derror*dt);

  //Integral del error
  ierror = x2;
  x2 = x2+(error*dt);

  //Calalculo del PID
  CV = kp*error+ki*ierror+kd*derror+ierrorBC;

  CVsinSat = CV;

  //Acota el valor del PID
  if (CV>=100){
    CV = 100;
  }else if (CV<=0){
    CV = 0;
  }

  //Backcalculation
  errorSat = CV-CVsinSat;
  x3 = x3+(errorSat*dt);
  ierrorBC = x3*kb;

  //Conversión %->pwm
  pwm = int(2.55*CV);

  //Acota el valor del pwm
  if(pwm<=50){
    pwm=0;
  }

  return pwm;
}