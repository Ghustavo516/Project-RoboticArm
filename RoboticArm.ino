
#include <VarSpeedServo.h> 

String readString;
int posx = 90; 
int posy = 90; 
int posz = 80; 
int posw = 90; 
int posc = 90; 
int posb = 90; 
int intensidade = 10;
int CalcEixosY;
int ajuste = 9; 
int tempoLocomocao = 1200;

//Declaração dos eixos X (BASE)
#define EixoX_PWM A0
VarSpeedServo MG995_ServoX; 

//Declaração dos eixos Y (BRAÇO)
#define EixoY1_PWM A1
VarSpeedServo MG995_ServoY1;

#define EixoY2_PWM A2
VarSpeedServo MG995_ServoY2;

//Declaração dos eixos Z (ANTEBRAÇO)
#define EixoZ_PWM A3
VarSpeedServo MG995_ServoZ;

//Declaração dos eixos W (PULSO)
#define EixoW_PWM A4
VarSpeedServo MG995_ServoW;

//Declaração dos eixos C (TORÇÃO PULSO)
#define EixoC_PWM A5
VarSpeedServo SG90_ServoC;

//Declaração dos eixos B (GARRA)
#define EixoB_PWM 9

VarSpeedServo SG90_ServoB;

void setup(){
  MG995_ServoX.attach(EixoX_PWM);
  MG995_ServoY1.attach(EixoY1_PWM);
  MG995_ServoY2.attach(EixoY2_PWM);
  MG995_ServoZ.attach(EixoZ_PWM);
  MG995_ServoW.attach(EixoW_PWM);
  SG90_ServoC.attach(EixoC_PWM);
  SG90_ServoB.attach(EixoB_PWM);

  Serial.begin(9600);
  Serial.println("Digite help para ver os comandos"); 
}

void loop(){
  Apresentation();
}

void Apresentation(){
  //Inicialização
   delay(tempoLocomocao);
   Base(90, 30);
   Braco(90, 15);
   Antebraco(90, 30);
   Pulso(90, 30);
   delay(tempoLocomocao);
   torcaoPulso(60, 30);
   delay(tempoLocomocao);
   Garra(10, 90);
   delay(tempoLocomocao);

   //Coordenadas para obter objeto
   Base(0, 30);
   delay(1000);
   Braco(120, 10);
   delay(500);
   Antebraco(180, 30);
   delay(tempoLocomocao);
   Pulso(35, 30);
   delay(tempoLocomocao);
   Braco(110, 10);
   delay(tempoLocomocao);
   Pulso(20, 30);
   delay(tempoLocomocao);
   Antebraco(170, 30);
   delay(tempoLocomocao);
   Garra(90, 255);
   delay(tempoLocomocao);
   Pulso(45, 30);
   delay(tempoLocomocao);
   Braco(100, 30);
   delay(tempoLocomocao);
   Braco(98, 30);
   delay(3000);

   //Garra pegando objeto
   Garra(30, 150);
   delay(3000);

   //Iniciando processo para levar objeto ate destino
   Pulso(90, 30);
   delay(tempoLocomocao);
   Antebraco(110, 30);
   delay(tempoLocomocao);
   Base(90, 50);
   delay(tempoLocomocao);
   torcaoPulso(0, 30);
   delay(1500);
   torcaoPulso(180, 30);
   delay(1500);
   torcaoPulso(0, 30);
   delay(1500);
   torcaoPulso(180, 30);
   delay(1500);
   torcaoPulso(0, 30);
   delay(1500);
   torcaoPulso(180, 30);
   delay(1500);
   torcaoPulso(60, 30);
   delay(tempoLocomocao);
   Braco(95, 30);
   delay(tempoLocomocao);

   //Finalizando entrega de objeto ao destinatario
   Antebraco(175, 15);
   delay(tempoLocomocao);
   Pulso(58, 15);
   delay(tempoLocomocao);
   Garra(90, 255);
   delay(2000);

   //Saida do braço
   Pulso(90, 50);
   delay(tempoLocomocao);
   Antebraco(110, 50);
   delay(tempoLocomocao);
   Antebraco(100, 15);
   delay(tempoLocomocao);
   Garra(10, 255);
   delay(tempoLocomocao);

   //dancinhha
   Braco(120, 15);
   delay(tempoLocomocao);
   Antebraco(180, 15);
   delay(tempoLocomocao);
   Pulso(150, 15);
   delay(tempoLocomocao);
   
   torcaoPulso(60, 7);
   delay(800);
   Base(90, 15);
   delay(800);
   
   torcaoPulso(0, 7);
   delay(800);
   Base(180, 15);
   delay(800);

   torcaoPulso(180, 7);
   delay(800);
   Base(0, 15);
   delay(tempoLocomocao);

   torcaoPulso(0, 7);
   delay(800);
   Base(180, 15);
   delay(800);

   torcaoPulso(180, 7);
   delay(800);
   Base(0, 15);
   delay(tempoLocomocao);
   
   //Saida do braço
   
   delay(tempoLocomocao);
   Pulso(90, 50);
   delay(tempoLocomocao);
   Braco(90, 20);
   delay(tempoLocomocao);
   Antebraco(110, 50);
   delay(tempoLocomocao);
   Antebraco(100, 15);
   delay(tempoLocomocao);
   Garra(10, 255);
   delay(tempoLocomocao);
   

   //Finalização
   Base(180, 30);
   delay(tempoLocomocao);
   Pulso(0, 50);
   delay(tempoLocomocao);
   Pulso(90, 50);
   delay(tempoLocomocao);
   Pulso(0, 50);
   delay(tempoLocomocao);
   Pulso(90, 50);
   delay(tempoLocomocao);

   Base(90, 30);
   delay(tempoLocomocao);
   Pulso(0, 50);
   delay(tempoLocomocao);
   Pulso(90, 50);
   delay(tempoLocomocao);
   Pulso(0, 50);
   delay(tempoLocomocao);
   Pulso(90, 50);
   delay(tempoLocomocao);

   Base(0, 30);
   delay(tempoLocomocao);
   Pulso(0, 50);
   delay(tempoLocomocao);
   Pulso(90, 50);
   delay(tempoLocomocao);
   Pulso(0, 50);
   delay(tempoLocomocao);
   Pulso(90, 50);
   delay(tempoLocomocao);
   Base(90, 30);
  
   delay(5000);
}
  
void Base(int anguloX, int velocidadeBase){
  MG995_ServoX.write(anguloX, velocidadeBase);
  Serial.println("eixo X em: ");
  Serial.println(anguloX);
}

void Braco(int anguloY, int velocidadeBraco){
  //Função responsavel por fazer o calculo dos eixos e deixar pronto para atuação
  CalcEixosY = (179 - anguloY);
  CalcEixosY -= ajuste;
  MG995_ServoY1.write(anguloY, velocidadeBraco);
  MG995_ServoY2.write(CalcEixosY, velocidadeBraco);
  Serial.println("eixo Y em: ");
  Serial.println(anguloY);
}

void Antebraco(int angulo_anteBraco, int velocidade_anteBraco){
  MG995_ServoZ.write(angulo_anteBraco, velocidade_anteBraco); 
  Serial.println("eixo Z em: ");
  Serial.println(angulo_anteBraco);
  MG995_ServoZ.attach(EixoZ_PWM);
}

void Pulso(int angulo_pulso, int velocidade_pulso){
  MG995_ServoW.write(angulo_pulso, velocidade_pulso); 
  Serial.println("eixo W em: ");
  Serial.println(angulo_pulso);
}
void torcaoPulso(int angulo_torcaoPulso, int velocidade_torcaoPulso){
  SG90_ServoC.write(angulo_torcaoPulso, velocidade_torcaoPulso); 
  Serial.println("eixo C em: ");
  Serial.println(angulo_torcaoPulso);
}

void Garra(int angulo_garra, int velocidade_garra){
  SG90_ServoB.write(angulo_garra, velocidade_garra); 
  Serial.println("eixo B em: ");
  Serial.println(angulo_garra);
}
