#define ENCODER_A 12 //Pin encoder A
#define ENCODER_B 14 //Pin encoder B

volatile int valor_encoder = 0; 

void encoder_isr() {
  //Lee el estado del encoder
  int A = digitalRead(ENCODER_A);
  int B = digitalRead(ENCODER_B);

  if ((A == HIGH) != (B == LOW)) {
    valor_encoder--;
  } else {
    valor_encoder++;
  }
  
}


void setup() {
  //Inicializa el puerto serial
  Serial.begin(115200);

  //Configura los pines del encoder y configura la interrupción al canal A
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), encoder_isr, RISING);

}



void loop() {
 
  Serial.println(valor_encoder);

}


//13-junio-2024
//Sentido horario (CW)          -> Aumenta el valor del encoder
//Sentido antihorario (CCW)     -> Disminuye el valor del encoder










