// Author: Jonathan Cobaleda Cabrera

/* Este programa controla la orientación del panel solar para mirar hacia el sol.
Esto significará que el panel solar producirá energía con la máxima eficiencia.
Lo hace comparando la cantidad de luz que incide en la parte superior e inferior del panel solar girando el panel solar en el eje x hacia la luz.
La luz será detectada por resistores dependientes de la luz (LDR.
Lo mismo sucede con los lados izquierdo y derecho del panel y con la rotación del panel solar en el eje z.
La tolerancia entre los sensores se puede ajustar mediante una resistencia variable para evitar que el panel solar intente mirar constantemente hacia el sol.*/



// Carga en libreria para los servomotores
#include <Servo.h>

void UpDown();// inicializar la función para mover el sensor hacia arriba y hacia abajo
void LeftRight();// inicializar la función para mover el sensor hacia arriba y hacia abajo

Servo servo1;
Servo servo2;



void setup() {
  servo1.attach(9);// Conectar el servo 1 al pin de interfaz 9
  servo2.attach(10); // Conectar el servo 2 al pin de interfaz 10
  
  servo1.write(90); // Establece el ángulo del servo 1 a 90 grados
  servo2.write(90); // Establece el ángulo del servo 2 a 90 grados
}

void loop(){
 int Tolerence = 0;
 int sensorTop = analogRead(A0);//Entrada LDR superior en el pin analógico 0
 int sensorBottom = analogRead(A1);// Entrada LDR inferior en el pin analógico 1
 int sensorLeft = analogRead(A3);// Entrada LDR izquierda en el pin analógico 3
 int sensorRight = analogRead(A4);// Entrada LDR derecha en el pin analógico 4

 int sensorTest1 = sensorTop - sensorBottom;// Compara la diferencia en la parte superior e inferior.
 int sensorTest2 = sensorBottom - sensorTop;//Compara la diferencia en la parte inferior e superior.
 int sensorTest3 = sensorLeft - sensorRight;// Compara la diferencia entre izquierda y derecha.
 int sensorTest4 = sensorRight - sensorLeft;// Compara la diferencia entre derecha y izquierda.
   
 int TolerenceValue = analogRead(A2);// Lee el valor de la resistencia variable para obtener la tolerancia
 Tolerence = (TolerenceValue * (5.0 / 1023.0))*2;// Valor de tolerancia y cambia el valor entre 1 y 10


 if ((sensorTest1 >= 0)&&(sensorTest1 >= Tolerence)) // verifica si la prueba del sensor 1 es mayor o igual a la tolerancia y si la prueba del sensor 1 es un número positivo
 	{
  	 UpDown(sensorTop, sensorBottom);// llama a la función para mover el panel solar hacia arriba o hacia abajo hacia el sol. También pase los valores de los sensores superior e inferior.
 	}	
  
 if((sensorTest2 >= 0)&&(sensorTest2 >= Tolerence)) // verifica si la prueba del sensor 2 es mayor o igual a la tolerancia y si la prueba del sensor 2 es un número positivo
 	{
 	 UpDown(sensorTop, sensorBottom);// llama a la función para mover el panel solar hacia arriba o hacia abajo hacia el sol. También pase los valores de los sensores superior e inferior.
 	}
 
 if((sensorTest3 >= 0)&&(sensorTest3 >= Tolerence)) // verifica si la prueba del sensor 3 es mayor o igual a la tolerancia y si la prueba del sensor 3 es un número positivo
 	{
     LeftRight(sensorLeft, sensorRight);// llama a la función para mover el panel solar hacia la izquierda o hacia la derecha hacia el sol. También pase los valores de los sensores izquierdo y derecho
 	}
 
 if((sensorTest4 >= 0)&&(sensorTest4 >= Tolerence)) // verifica si la prueba del sensor 4 es mayor o igual a la tolerancia y si la prueba del sensor 4 es un número positivo
  	{
  	LeftRight(sensorLeft, sensorRight);// llama a la función para mover el panel solar hacia la izquierda o hacia la derecha hacia el sol. También pase los valores de los sensores izquierdo y derecho
  	} 
 
 delay(10); //espere 10 milisegundos antes de volver al inicio del ciclo principal.
}

// función para comprobar en qué dirección moverse hacia arriba o hacia abajo y girar hacia el sol. También tome el valor de arriba y abajo del bucle principal y no devuelva nada.
void UpDown(int sensorTop, int sensorBottom){
  
  int pos1= servo1.read();// lee el ángulo actual del servo 1
    
  if(sensorTop < sensorBottom) // comprueba si el sensor inferior es mayor que el superior antes de entrar en el bucle.
    { 
     pos1 = --pos1; // cambiar el ángulo por -1
    }
  	 else// si la parte inferior no es mayor que la parte superior, ingrese este ciclo
     {
      pos1 = ++pos1;// cambiar el ángulo en +1
     }
  servo1.write(pos1); // El nuevo ángulo al servo 1
}

// función para verificar en qué dirección moverse hacia la izquierda o hacia la derecha y girar hacia el sol. También tome el valor de izquierda y derecha del bucle principal y no devuelva nada.
void LeftRight(int sensorLeft, int sensorRight){
  
 int pos2= servo2.read();// lee el ángulo actual del servo 1
  
 if(sensorLeft < sensorRight)// Comprueba si el sensor izquierdo es mayor que el derecho antes de entrar en el bucle.
   { 
    pos2 = --pos2;// cambiar el ángulo por -1
   }
  	else//si la izquierda no es mayor que la derecha entonces entra en este loop
    {
     pos2 = pos2 + 1;// cambiar el ángulo por +1
    }
  servo2.write(pos2); // El nuevo ángulo al servo 1
}
