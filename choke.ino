#define qtd 4 //4 pinos,4 notas

byte notas_choke[] = {78, 80, 82, 63}; //notas
byte choke_pin[] = {51, 49, 47, 53}; //pinos do arduino

void setup() {
  Serial.begin(115200);
  for (int cont = 0; cont < qtd; cont++) {
    pinMode(choke_pin[cont], INPUT_PULLUP);
  }
}

void loop() {
  for (int c = 0; c < qtd; c++) {
    if(digitalRead(choke_pin[c])==LOW){
      Serial.write(137);Serial.write(notas_choke[c]);Serial.write(127);
      Serial.write(153);Serial.write(notas_choke[c]);Serial.write(0);  
    }
  }
}
