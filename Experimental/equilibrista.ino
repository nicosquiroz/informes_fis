
# include < PIDv1.h >
double Setpoint, Input, Output;

//la siguiente linea activa el PID y sus variables
//en la siguiente linea tenemos los valores asignados a las variables de PID
//siendo Kp=4.3, Ki=0 y Kd=0.1 PID myPID(Input, Output, Setpoint,4.3,0.4,0.1, DIRECT); #include¡math.h¿

#include¡stdio.h¿
#include ¡Servo.h¿
#define AX 5 //relaciona el dato de la aceleracion en el eje x con el puerto 5
#define AY 4 //relaciona el dato de la aceleracion en el eje x con el puerto 4
#define AZ 3 //relaciona el dato de la aceleracion en el eje x con el puerto 3

int valx,valy,valz; //definimos las variables que vamos a usar double b;
double angulo; //aqui se guarda el valor del angulo que usaremos
Servo myservo; // crea un objeto servo para controlar el servo
int val;



void setup() {

myservo.attach(9); // attaches the servo on pin 9 to the servo object //recibimos la sen ̃al de las respectivas entradas 

pinMode(AX,INPUT);
pinMode(AY,INPUT);
pinMode(AZ,INPUT);

Serial.begin(9600);
Input = angulo; //asignamos a input el valor de langulo para que lo reciba PID 
Setpoint = 0; // este es el angulo que permanecera constante 
myPID.SetMode(AUTOMATIC); //enciende el PID
}


void loop() {
float a;
for (int i=0;i¡10;i++) {
valx+=analogRead(AX);delay(1); //a valx le asigna lo que lee en AX y espera un segundo para leer el siguiente dato, ya que se necesita una variacion de tiempo para obtener una aceleracion. 
valy+=analogRead(AY);delay(1);
valz+=analogRead(AZ);delay(1);
}


valx=valx/10;
valy=valy/10;
valz=valz/10;
delay(195); //espera 195 milisegundos para volver a tomar datos
b=(double) ((valx-320))/((valy-320)); //se obtiene el cuociente entre las dos aceleraciones 
a=atan(b); // este es el valor del angulo, una vez qe se saca el arcotangente
double angulo; //se define la variable para el angulo
angulo=a/3.14*180; //convierte el valor a angulo


Serial.print(.A: ”);
Serial.println(angulo); // imprime los valores del angulo para ir verificando 
//se vuelven a cero todos los valores


valx=0;
valy=0;
valz=0;

Input = angulo;
myPID.Compute(); //se inicia el PID

Serial.print(.output pid: ”);
Serial.print(Output); //imprime para ver los valores que salen del PID 

Output=map(Output,-90,90,69,111);
myservo.write(Output); //ingresamos al servo el valor que sale del PID para mover el motor
}
