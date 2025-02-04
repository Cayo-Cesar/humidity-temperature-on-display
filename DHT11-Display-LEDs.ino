#include <Wire.h>                 
#include <Adafruit_GFX.h>          
#include <Adafruit_SSD1306.h>      
#include <DHT.h>                   

#define DHTPIN 5                   
#define DHTTYPE DHT11             

DHT dht(DHTPIN, DHTTYPE);         

// Configuração do display OLED (endereço I2C, largura e altura)
#define SCREEN_WIDTH 128           
#define SCREEN_HEIGHT 64           
#define OLED_RESET    -1          
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define RED_LED_PIN 18             // LED vermelho no pino D18
#define GREEN_LED_PIN 19           // LED verde no pino D19

void setup() {
  // Inicializa o display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao iniciar o display OLED"));
    while (true); // Fica travado se falhar
  }
  display.display(); // Exibe o conteúdo inicial
  delay(2000);        // Aguarda 2 segundos

  dht.begin();

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  float h = dht.readHumidity();          // Umidade
  float t = dht.readTemperature();       // Temperatura em Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Falha ao ler do sensor DHT"));
    return;
  }

  display.clearDisplay();

  display.setTextSize(1);                 // Tamanho do texto
  display.setTextColor(SSD1306_WHITE);    // Cor do texto
  display.setCursor(0, 0);                // Posição inicial do texto

  display.print(F("Temp: "));
  display.print(t);
  display.print(F(" C"));
  display.setCursor(0, 10);               // Move para a próxima linha
  display.print(F("Umid: "));
  display.print(h);
  display.print(F(" %"));

  if (t > 35 || h > 60) {
    // Temperatura > 35°C ou Umidade > 60% -> Acende LED vermelho
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else if (t < 35 && h >= 30 && h <= 60) {
    // Temperatura < 35°C e Umidade entre 30% e 60% -> Acende LED verde
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  } else {
    // Fora dos intervalos definidos -> Apaga ambos os LEDs
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
  }

  display.display();                     

  delay(2000);
}
