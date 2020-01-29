/*CONTROLADOR MIDI ACIONADO POR IR
Roberto Gomes  19/01/2020
*/

#include <MIDI.h> //https://github.com/FortySevenEffects/arduino_midi_library
#include <IRremote.h> //https://github.com/z3t0/Arduino-IRremote

//FFA857 botão avança      *Nota: Essa é código do botão. 
//FFE01F botão retroceder

MIDI_CREATE_DEFAULT_INSTANCE();

int Volume[] = {0, 20, 40, 65, 75, 87, 97, 107, 117, 127}; // degraus de volume
int count = 0;  //Variável de incremento e decremento
int RECV_PIN = 3; // pino que recebe sinal do sensor IR receptor
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {

  irrecv.enableIRIn(); 
  MIDI.begin();
  Serial.begin(115200);

}
void loop() {
  if (irrecv.decode(&results)) {
    if ((results.value == 0xFFA857 ) && (count < 9)) {
      count++;
      //Serial.println(Volume[count]);
      MIDI.sendControlChange(2 , Volume[count] , 1); //(Command,value,channel)
    }
    if ((results.value == 0xFFE01F) && (count > 0)) {
      count--;
      //Serial.println(Volume[count]);
      MIDI.sendControlChange(2 , Volume[count] , 1);
    }

    irrecv.resume();
  }
}
