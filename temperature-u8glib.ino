
#include <U8glib.h> 

#define OLED_SDA 4
U8GLIB_SSD1306_128X64 u8g = U8GLIB_SSD1306_128X64(OLED_SDA);
#include <DHT.h>
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {  
  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1); // Instructs the display to draw with a pixel on. 

  dht.begin();
}

void loop() {  
  u8g.firstPage();
  do {  
    draw();
  } while( u8g.nextPage() );
  delay(1000);   
}
  
void draw(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); //in degrees by default

   u8g.setPrintPos(0,50); 
u8g.print( "hum: ");
u8g.print( h);

  u8g.setPrintPos(0,10); 
u8g.print( "temp: ");
u8g.print( t);
u8g.print( "");

 // String s = printf("Player %d", h);
 // u8g.print( 0, 20, s);
  //u8g.drawStr( 0, 40, "temperature: "+ t);
}
