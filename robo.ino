#define IN3    9                 // Sentido Motor B
#define IN4    10                // Sentido Motor B
#define IN1    7                 // Sentido Motor A
#define IN2    8                 // Sentido Motor A
#define ENB    6                 // Habilita motor B  
#define ENA    5                 // Habilita motor A  
#define trigE   A1               //Trigger Sensor 2 ESQUERDA
#define trigD   A3               //Trigger Sensor 1 DIREITA
#define trigM   A5               //Trigger Sensor 3 MEIO
#define echoE   A0               //Echo Sensor 2 ESQUERDA
#define echoD   A2               //Echo Sensor 1 DIREITA
#define echoM   A4               //Echo Sensor 3 MEIO


void moverParaFrente(void);
void moverParaTras(void);
void virarParaEsquerda(void);
void virarParaDireita(void);
int sensorD(void);               // Retorna a distância
int sensorE(void);              
int sensorM(void);


int dist_D, dist_E, dist_M;


void setup()
{
  Serial.begin(9600);


  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(echoD, INPUT);
  pinMode(echoE, INPUT);
  pinMode(echoM, INPUT);
  pinMode(trigD, OUTPUT);
  pinMode(trigE, OUTPUT);
  pinMode(trigM, OUTPUT);


}


void loop()
{
  dist_D = sensorD();
  delay(10);
  dist_E = sensorE();
  delay(10);
  dist_M = sensorM();
  delay(10);


  Serial.print("Sen Dir: ");
  Serial.print(dist_D);
  Serial.print("\tSen Esq: ");
  Serial.print(dist_E);
  Serial.print("\tSen Meio: ");
  Serial.print(dist_M);
  Serial.println(" ");


  moverParaFrente();

  if ((dist_D < 12) && (dist_E < 12))
  {
    moverParaTras();
    delay(300);
  }
  
  if ((dist_D < dist_E) && (dist_M < 8))
  {
    moverParaTras();
    delay(300);
    virarParaEsquerda();
    delay(300);
  }


  if ((dist_E < dist_D) && (dist_M < 8))
  {
    moverParaTras();
    delay(300);
    virarParaDireita();
    delay(300);
  }


  if (dist_E < 10)
  {
    virarParaDireita();
    delay(300);
  }


  if (dist_D < 10)
  {
    virarParaEsquerda();
    delay(300);
  }
}


void moverParaFrente(void)
{
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);


  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void virarParaEsquerda(void)
{
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);


  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void virarParaDireita(void)
{
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void moverParaTras(void)
{
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


int sensorD(void)
{
  digitalWrite(trigD, LOW);
  delayMicroseconds(4);
  digitalWrite(trigD, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigD, LOW);


  long t = pulseIn(echoD, HIGH);
  int cm = t / 29 / 2; //Converte tempo para distancia
  return cm;
}


int sensorE(void)
{
  digitalWrite(trigE, LOW);
  delayMicroseconds(4);
  digitalWrite(trigE, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigE, LOW);


  long t = pulseIn(echoE, HIGH);
  int cm = t / 29 / 2; //Converte tempo para distancia
  return cm;
}


int sensorM(void)
{
  digitalWrite(trigM, LOW);
  delayMicroseconds(4);
  digitalWrite(trigM, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigM, LOW);


  long t = pulseIn(echoM, HIGH);
  int cm = t / 29 / 2; //Converte tempo para distancia
  return cm;
}






