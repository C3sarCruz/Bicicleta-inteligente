/**
░█████╗░░█████╗░░██████╗░█████╗░░█████╗░
██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔══██╗
██║░░╚═╝███████║╚█████╗░██║░░╚═╝██║░░██║
██║░░██╗██╔══██║░╚═══██╗██║░░██╗██║░░██║
╚█████╔╝██║░░██║██████╔╝╚█████╔╝╚█████╔╝
░╚════╝░╚═╝░░╚═╝╚═════╝░░╚════╝░░╚════╝░

██╗███╗░░██╗████████╗███████╗██╗░░░░░██╗░██████╗░███████╗███╗░░██╗████████╗███████╗
██║████╗░██║╚══██╔══╝██╔════╝██║░░░░░██║██╔════╝░██╔════╝████╗░██║╚══██╔══╝██╔════╝
██║██╔██╗██║░░░██║░░░█████╗░░██║░░░░░██║██║░░██╗░█████╗░░██╔██╗██║░░░██║░░░█████╗░░
██║██║╚████║░░░██║░░░██╔══╝░░██║░░░░░██║██║░░╚██╗██╔══╝░░██║╚████║░░░██║░░░██╔══╝░░
██║██║░╚███║░░░██║░░░███████╗███████╗██║╚██████╔╝███████╗██║░╚███║░░░██║░░░███████╗
╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚══════╝╚══════╝╚═╝░╚═════╝░╚══════╝╚═╝░░╚══╝░░░╚═╝░░░╚══════╝ 
  
  INTEGRANTES
    Maria Guadalupe Puente Gonzalez
    Cesar Guerrero Cruz
*/

//LIBRERIAS PARA LA PANTALLA_OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//LIBRERIA DE SONIDO
#include <pitches.h>

//LIBRERIAS PARA LA CONEXION A WIFI
#include <WiFi.h>
#include <PubSubClient.h>

//LIBRERIA DHT
#include <DHT.h>

//DECLARANDO PROPIEDADES DE LA OLED
#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels

//  DECLARANDO VARIABLES PARA ULTRASONICO Y BUZZER
#define TRIG_PIN   13 // ESP32 pin GPIO26 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN   25 // ESP32 pin GPIO25 connected to Ultrasonic Sensor's ECHO pin
#define BUZZER_PIN 32 // ESP32 pin GPIO17 connected to Piezo Buzzer's pin
#define DISTANCE_THRESHOLD 20 // centimeters

//DECLARANDO DHT
#define DHTPIN 23
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//DECLARANDO LED RGB_1
#define RED_PIN 17
#define GREEN_PIN 5
#define BLUE_PIN 18

//DECLARANDO LED RGB_2
#define RED_PIN_2 2
#define GREEN_PIN_2 4
#define BLUE_PIN_2 16

//  NOTAS PARA LA MELODIA
int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

//  CANCIÓN
int noteDurations[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

/*
**DECLARANDO CONSTANTES
*/

// VARIABLES PARA OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Variable valuePayload
String valuePayload = "false";

//HUMEDAD
float currentHumidity = 0;

//MOVIMIENTO
const int pirPin  = 15;
bool pirStatus  = false;

//LED RGB_1 HUMEDAD
const int ledRGB = 18;

//ULTRASONICO
bool ultraStatus = false;

//HUMO
bool humoStatus = false;
int PIN_MQ2 = 14;


// Configuración de la conexión WiFi
const char* ssid = "asustadoPotter"; // Cambiar esto por la SSID de la red Wifi
const char* password = "niunpoco"; // Cambiar esto por la contraseña

// Configuración del cliente MQTT
// Constantes para la comunicacion mqqt con la ip del broker y el puerto de Mosquitto
const char* mqttServer = "192.168.0.8";
const int mqttPort = 1883;
//  Constantes de cada sensor y su topico
const char* mqttTopic = "/bicicleta/";
const char* mqttTemperatura = "/bicicleta/temperatura";
const char* mqttHumo = "/bicicleta/humo";
const char* mqttDistancia = "/bicicleta/distancia";
const char* mqttPir = "/bicicleta/pir";
const char* mqttLedRgb = "/bicicleta/ledRgb";
const char* mqttOled = "/bicicleta/oled";
const char* mqttBuzzer = "/bicicleta/buzzer";

//  Variables para la coneccion Wifi y MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// Función para conectar a WiFi
void conectarWifi() {
  Serial.print("Conectando a WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado!");
}

// Función para conectar al broker MQTT
void conectarBroker() {
  Serial.print("Conectando al broker: ");
  Serial.println(mqttServer);
  while (!client.connected()) {
    Serial.print("Intentando conectar al cliente MQTT...");
    if (client.connect("ArduinoClient")) {
      Serial.println("Conectado!");
      client.subscribe(mqttTopic);
      client.subscribe(mqttLedRgb);
      client.subscribe(mqttOled);
      client.subscribe(mqttBuzzer);
      client.setCallback(callback);
    } else {
      Serial.println("Error de conexión");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

/*
**  Función Led RGB Estatus
*/
void ledRGBStatus(){
  if(valuePayload.equalsIgnoreCase("true")){
    Serial.println("### Prendiendo foquito");
    digitalWrite(ledRGB, HIGH);  
  }else{
    Serial.println("### Apagando foquito");
    digitalWrite(ledRGB, LOW);
  }  
}

/*
**  Metodo Setup
*/
void setup(){ 
  Serial.begin(115200);

  //INICIALIZANDO PINES DE ENTRADA Y SALIDA A SENSORES Y ACUADORES

  //ULTRASONICO
  pinMode(TRIG_PIN, OUTPUT); // Configura el pin TRIG como salida
  pinMode(ECHO_PIN, INPUT);  
  
  //LED RGB1
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  //LED RGB 2
  pinMode(RED_PIN_2, OUTPUT);
  pinMode(GREEN_PIN_2, OUTPUT);
  pinMode(BLUE_PIN_2, OUTPUT);

  //HUMO
  pinMode(PIN_MQ2, INPUT);

  //PIR
  pinMode(pirPin, INPUT);
  
  //Humedad
  dht.begin();
  
 
  // Iniciar la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

   
  //CONEXIÓN AL BROKER Y TOPICO MQTT
  conectarWifi();
  client.setServer(mqttServer, mqttPort);
  conectarBroker();
}

/*
**  Metodo loop
*/
void loop() {
  /*
  **  CONEXION A WIFI
  */
  if (!client.connected()) {
    conectarBroker();
  }
  client.loop(); 

  //  Variables de lectura de sensores
  float dist = ultra(); // Llama a la función ultra
  int mq2Estado = digitalRead(PIN_MQ2); //  Lectura de sensor humo
  int pirLectura = digitalRead(pirPin); //  Lectura de sensor pir

  /*
  **  OLED CON GRAFICA DEL SENSOR PIR
  */
  //  Llamar la función humo condición
  humoCondicion();

  //  Llamar la función temperatura condición
  temperaturaCondicion();

  //  Limpiar la pantalla Oled
  display.clearDisplay(); 
  
  // Declarar el estilo que tendrá el texto mostrado
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.drawRect(0, 20, 128, 10, WHITE);  //  Dibujar la grafica de barra
  int barWidth = map(pirLectura, 0, 4095, 0, 128);  //  Inicializar variable barWidth para mapear los valores del sensor Pir
  display.fillRect(0, 20, barWidth, 10, WHITE); //  Dibujar los datos del sensor Pir en la grafica
  //  Pintar los datos de los sensores
  display.print("Movimiento: "); 
  display.println(pirLectura);
  display.println(" ");
  display.println(" ");
  display.println(" ");
  display.println("   ||");
  display.print("Humedad: ");
  display.print(currentHumidity);
  display.print(" | ");
  display.print("Humo: ");
  display.print(mq2Estado);
  display.print(" | ");
  display.print("Distancia: ");
  display.print(String(ultra()));
  display.display();
  

  // Actualización de los datos de sensores y publicación en MQTT cada 10 segundos
  static unsigned long lastPublishTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastPublishTime > 5000) {
    lastPublishTime = currentTime;

    // Leer los valores de los sensores
    mq2Estado = digitalRead(PIN_MQ2);
    int pirLectura = digitalRead(pirPin);
    currentHumidity = dht.readHumidity();

    // Crear un mensaje JSON para cada sensor
    String payloadTemperatura = String(currentHumidity);
         
    if (client.publish(mqttTemperatura, payloadTemperatura.c_str())) {
      Serial.println("Mensaje publicado con éxito");
      Serial.print("Temperatura: ");
      Serial.println(payloadTemperatura);
    } else {
      Serial.println("Error al publicar el mensaje");
    }

    String payloadHumo = String(mq2Estado);
    

    if (client.publish(mqttHumo, payloadHumo.c_str())) {
      Serial.println("Mensaje publicado con éxito");
      Serial.print("Humo: ");
      Serial.println(payloadHumo);
    } else {
      Serial.println("Error al publicar el mensaje");
    }

    
    String playloadDistancia = String(ultra());
         
    if (client.publish(mqttDistancia, playloadDistancia.c_str())) {
      Serial.println("Mensaje publicado con éxito");
      Serial.print("Distancia: ");
      Serial.println(playloadDistancia);
    } else {
      Serial.println("Error al publicar el mensaje");
    }


    String playloadPir = String(pirLectura);
         
    if (client.publish(mqttPir, playloadPir.c_str())) {
      Serial.println("Mensaje publicado con éxito");
      Serial.print("Movimiento: ");
      Serial.println(playloadPir);
    } else {
      Serial.println("Error al publicar el mensaje");
    }
  }

  delay(1000);
  // Mantener la conexión MQTT activa
}


/*
**  Función ultra
*/
float ultra() {
  digitalWrite(TRIG_PIN, LOW); // Asegúrate de que el pin TRIG esté en LOW
  delayMicroseconds(2000);         // Espera 2 microsegundos
  digitalWrite(TRIG_PIN, HIGH); // Envía un pulso de 10us
  delayMicroseconds(1000);       
  digitalWrite(TRIG_PIN, LOW);

  long duracion = pulseIn(ECHO_PIN, HIGH); // Lee la duración del pulso en el pin ECHO
  float distancia = (duracion * 0.0343) / 2; // Calcula la distancia en cm
  return distancia;
} 

/*
**  Función ultrasonico (condicón para activar/desactivar buzzer)
*/
float ultrasonico(){
   Serial.println("ESTA LEYENDO ESTE METODO"); 
   float distancia = ultra();
  if(distancia < DISTANCE_THRESHOLD){
    Serial.println("LA DISTANCIA FUE MENOR");
    buzzer();
  }else{
    Serial.println("LA DISTANCIA FUE MAYOR");
    noTone(BUZZER_PIN);
  }
  delay(5000); // Espera 100 ms
}

/*
**  Función buzzer
*/
void buzzer() {
  // Iterar sobre las notas de la melodia
  int size = sizeof(noteDurations) / sizeof(int);

  for (int thisNote = 0; thisNote < size; thisNote++) {
    // Para calcular la duración de la nota, toma un segundo dividido por el tipo de nota.
    // Ejemplo: negra = 1000/4, corchea = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // Para distinguir las notas, establece un tiempo mínimo entre ellas.
    // La duración de la nota + 30% parece funcionar bien:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    // Detiene la reproducción del tono:
    noTone(BUZZER_PIN);
  }
}

/*
**  Metodo Set Color
*/
void setColor(int red, int green, int blue) { //  Declarar colores del led RGB
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}


/*
**  Metodo Set Color2 para el segundo led RGB
*/
void setColor2(int red, int green, int blue) {
  analogWrite(RED_PIN_2, red);
  analogWrite(GREEN_PIN_2, green);
  analogWrite(BLUE_PIN_2, blue);
}

/*
**  Función Humo Condición
*/
void humoCondicion(){
  //  Declara la variable mq2Estado para leer los datos del sensor
  int mq2Estado = digitalRead(PIN_MQ2);
  if(mq2Estado == 1){ //  Hace la condición miestras que el dato del sensor sea 1 el color esta en rojo
    setColor(255, 0, 0); // ROJO
  }else{  //  En caso contrario el color del led cambia a azul
    setColor(0, 0, 255); // AZUL
    delay(1000);
  }
}

/*
**  Función Temperatura Condicón
*/
void temperaturaCondicion(){
  //  Declara la variable currenHumidity para leer los datos del sensor
  int currentHumidity = dht.readHumidity();
  if (currentHumidity <= 50) {//  Hace la condición miestras que el dato del sensor sea 50 el color esta en azul
    setColor2(0, 0, 255); // AZUL
  } else {  //  En caso contrario el color del led cambia a rojo
    setColor2(255, 0, 0); // ROJO
    delay(1000);
  } 
}

/*
**  Función Callback
*/
void callback(char* topic, byte* payload, unsigned int length){
  //  Se inicializa la variable value payload vacia
  valuePayload = "";
  
  // Ciclo for
  for(int i=0;i<length;i++) {
    valuePayload += (char)payload[i];
  }
  Serial.println("Conectando al topico:");
  Serial.println(topic);
  Serial.println(valuePayload);
  if(valuePayload.equalsIgnoreCase("buzzer-true")){
    Serial.println("### PRENDIENDO BUZZER");
    //buzzer();
  }
  if(valuePayload.equalsIgnoreCase("buzzer-false")){
    Serial.println("### APAGANDO BUZZER");
    //noTone(BUZZER_PIN);
  }
  if(valuePayload.equalsIgnoreCase("led-rojo")){
    Serial.println("### PRENDIENDO LED");

  }
  if(valuePayload.equalsIgnoreCase("led-azul")){
    Serial.println("### APAGANDO LED");

  }
  if(valuePayload.equalsIgnoreCase("oled-true")){
    Serial.println("### PRENDIENDO OLED");

  }
  if(valuePayload.equalsIgnoreCase("oled-false")){
    
  }
}

