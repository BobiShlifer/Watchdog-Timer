long result = 0;

void setup()
{
Serial.begin(9600);
WDTCSR = (1 << WDCE) | (1 << WDE); // Watchdog Change Enable(WDCE) 
WDTCSR = (1 << WDE) | (1 << WDP2)| (1 << WDP1)| (1 << WDP0);
}

void loop()
{
if(Serial.available() > 0){ 
asm("wdr"); 
long value = Serial.parseInt();
result += value;
Serial.println(result);
Serial.read();
}
}
