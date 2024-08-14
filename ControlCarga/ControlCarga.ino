#define swPanel 23  //Pin asociado al switch Q1
#define swCarga 22 //Pin asociado al switch Q2

#define btnPanel 1
#define btnCarga 3

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
  Serial.println("Panel y carga conectados");
}

void loop() {
  Serial.println("Panel y carga conectados");
  digitalRead(btnPanel);
  digitalRead(btnCarga);
  if (btnPanel==1)
  {
    digitalWrite(swPanel,LOW);
    Serial.println("Panel desconectado");
  }
  if (btnCarga==1)
  {
    digitalWrite(swCarga,LOW);
    Serial.println("Carga desconectado");
  }

}

