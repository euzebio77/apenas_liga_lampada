int readBluetooth;//Variável que irá receber o valor enviado do celular para o Bluetooth
boolean stateLamp=false;//Estado da lâmpada iniciada &quot;false&quot;, indicando lâmpada desligada;
int lamp=13;//LED da porta 13
 
void setup(){
   Serial.begin(9600);//Inicia comunicação serial
   pinMode(lamp,OUTPUT);//Definindo o pino 13 como saída
}
 
void loop(){
    if(Serial.available()){
    readBluetooth = Serial.read();
    if(readBluetooth == 'a'){
        if(stateLamp){ //Se stateLamp for true:
           digitalWrite(lamp,LOW);//Desliga a lâmpada
           stateLamp=false;//Guarda o estado para false(lâmpada apagada)
        }
        else{//Senão:
            digitalWrite(lamp,HIGH);//Liga a lâmpada
            stateLamp=true;//Guarda o estado para true(lâmpada acesa)
        }
     }
   }
}
