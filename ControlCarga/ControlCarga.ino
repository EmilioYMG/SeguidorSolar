#define swPanel 13  //Pin asociado al switch Q1
#define swCarga 12 //Pin asociado al switch Q2

#define btnPanel 14
#define btnCarga 27

#define btnPanelOn 26
#define btnCargaOn 25

bool Panel= 1;
bool Carga= 1;

void setup() {
  Serial.begin(115200);
  delay(50);
  //asignacion de los pines
  pinMode(swPanel, OUTPUT);
  pinMode(swCarga,OUTPUT);
  pinMode(btnPanel,INPUT);
  pinMode(btnCarga,INPUT);
  digitalWrite(swPanel,HIGH);
  digitalWrite(swCarga,HIGH);
  pinMode(btnPanelOn,INPUT);
  pinMode(btnCargaOn,INPUT);
  Serial.println("Panel y carga conectados");
}

void loop() {
  //Serial.println(digitalRead(btnPanel));
  //Serial.println(digitalRead(btnCarga));
  if (digitalRead(btnPanel)==1)
  {
    digitalWrite(swPanel,LOW);
    Serial.println("Panel desconectado");
  }
  if (digitalRead(btnCarga)==1)
  {
    digitalWrite(swCarga,LOW);
    Serial.println("Carga desconectado");
  }

  if (digitalRead(btnPanelOn)==1)
  {
    digitalWrite(swPanel,HIGH);
    Serial.println("Panel conectado");
  }
  if (digitalRead(btnCargaOn)==1)
  {
    digitalWrite(swCarga,HIGH);
    Serial.println("Carga conectado");
  }
delay(100);
}

