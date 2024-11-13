/**@file Andar.ino  */

#include <Servo.h>

//Objetos dos motores
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

//Posições iniciais dos motores da esquerda
int pos2 = 95;
int pos6 = 60;
int pos8 = 40;
int pos4 = 40;

//Posições iniciais dos motores da direita
int pos1 = 65;
int pos5 = 100;
int pos7 = 19;
int pos3 = 120;

//Variaveis necessárias
int angpesodir = 10; //Ângulo do balanço
int angjoe = 15; //O quanto ele levanta o joelho no prep
int angpasso = 20; //O quanto ele levanta o joelho para andar

//Função necessárias
void stop();

void prep();

void andarFrente();

//Configuração inicial do arduino e dos motores
void setup() {

  //Inicialização dos motores da esquerda
    servo2.attach(52);
    servo4.attach(48);
    servo6.attach(44);
    servo8.attach(40);

  //Inicialização dos motores da direita
    servo1.attach(34);
    servo3.attach(30);
    servo5.attach(24);
    servo7.attach(22);

  //Posição inicial
    stop();
    delay(5000);

  //Preparar para o passo
    prep();
    delay(1);

}
 
void andarFrente(){

}

void stop(){
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  servo5.write(pos5);
  servo6.write(pos6);
  servo7.write(pos7);
  servo8.write(pos8);

  delay(1);
}
 
void prep(){

  //Peso para a perna esquerda OK
    for (int i = 0; i <= angpesodir; i++) {
    servo2.write(pos2 - i);
    servo8.write(pos8 - i);
    servo1.write(pos1 - i);
    servo7.write(pos7 - i);
    delay(50);

  }

  delay(1);

  //Contrair perna direita
   for(int j=0; j<=angjoe; j++) {
    servo3.write(pos3 + j);
    servo5.write(pos5 + j);
    delay(50);
  }

  delay(1);

  //Esticar perna esquerda
   for(int j=0; j<=angjoe; j++) {
    servo4.write(pos4 + j);
    servo6.write(pos6 + j);
    delay(50);
  }

  delay(1);
  // Retornar o servo 7 para a posição original
    for(int i=0; i <= angpesodir ; i++){
    servo7.write(pos7 - angpesodir + i);
    delay(50);
    }

  delay(1);

    for(int i=0; i<=angpesodir; i++){
      servo1.write(pos1 - angpesodir - i);
      delay(50);
    }

  //Peso para a perna direita
    for (int i = 0; i <= 2*angpesodir; i++) {
    servo2.write(pos2 - angpesodir + i);
    servo8.write(pos8 - angpesodir + 2*i);
    servo1.write(pos1 - 2*angpesodir + i);
    servo7.write(pos7 + i);
    delay(70);
  }

  delay(1);

  


//COISAS QUE NAO SAO DO PREP
  //Contrair perna esquerda
   for(int j=0; j<=angjoe; j++) {
    servo4.write(pos4 + angjoe - j);
    servo6.write(pos6 + angjoe - j);
    servo3.write(pos3 + angjoe - j);
    servo5.write(pos5 + angjoe - j);
    delay(70);
  }

  delay(1);

    for (int i = 0; i <= angpesodir; i++) {
    servo2.write(pos2 + angpesodir - i);
    servo8.write(pos8 + 3*angpesodir - 3*i);
    servo7.write(pos7 + 2*angpesodir-2*i);
    delay(50);
  }

  delay(1);

}

 /**  Loop principal do arduino
 * */
void loop() {
 //andarFrente();
 stop();
 prep();
}
