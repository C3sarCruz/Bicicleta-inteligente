# Casco-inteligente

# Integrantes: 
•	Maria Guadalupe Puente Gonzalez <br>
•	Cesar Guerrero Cruz

# Objetivo:
* Creación de un sistema de monitorio de ambiente para que los ciclistas puedan monitorear su alrededor o su progreso.

# Descripción:
El sistema contará con distintos sensores para capturar datos que se mostrará a los ciclistas para que estén al tanto de su avance o lo que está pasando a su alrededor. 
Contará con un sensor de temperatura que le indicara la temperatura del ambiente, sensor de a proximidad que indicara la a proximidad de los objetos que se encuentra en su recorrido, sensor de gas que nos indicará si hay gases tóxicos o peligrosos y un sensor de movimiento que permite detectar el actual movimiento que lleve el ciclista. También contara con actuadores que ayudaran a los sensores a pasar el mensaje que estén detectando, los actuadores que se utilizaran será un led, pantalla oled, buzzer y gauge

# Visión:
Nuestro producto esta dirigido a los usuarios que practiquen ciclismo, ya que el ciclismo es un deporte que implique correr riesgos por ello se genero esta idea que es un casco inteligente que busca monitorear el ambiente de los ciclistas ya que así se tendrá un mejor control y cuidado al momento de realizar esta actividad. 
El casco es una idea tecnológica que combina el internet de las cosas con el desarrollo y hardware para poder generar un producto innovador para nuestro público objetivo que son los ciclistas. 

# Necesidad que cubre:
El producto busca satisfacer las necesidades del usuario proporcionando un producto de calidad que pueda cumplir con las expectativas y requerimientos. El casco inteligente tiene diferentes beneficios para los ciclistas ya que les ayudara a cubrir aspectos de su ambiente al momento de realizar esta actividad.
Tomando como punto de partida lo anterior, se pretende crear un producto fácil de manipular y que tenga el papel de accesorio ya que será más sencillo utilizarlo, esta idea innovadora podrá revolucionar y mejorar el ciclismo

# Competencias en el mercado:
• Una smart bike es una bicicleta diseñada para entrenar en interiores. Muchas personas conocen las típicas bicis de gimnasio o de spinning, pero esta es diferente. Es un dispositivo enfocado a facilitar una experiencia lo más aproximada posible al rodar en bici en exterior.

• Un rodillo es un sistema que bloquea la rueda trasera de tu bici con la ayuda de un soporte y que te permite pedalear en casa. En la actualidad, los más populares son los rodillos interactivos de transmisión directa. Funcionan de la siguiente manera: se quita la rueda de la bici y se monta sobre el cassette instalado en el propio rodillo.

# ¿Qué tiene mejor nuestro proyecto que la competencia no?
Se mencionaron dos productos del mercado actual que son nuestra competencia, pero nuestra idea ofrece innovación, creatividad y la implementación de la tecnología y el internet de las cosas para generar este producto para nuestros usuarios potenciales. 
Buscamos automatizar una actividad que muchas personas realizan pero ofreciéndoles algo que pueda colaborar a que esta actividad sea más segura para los ciclistas, este producto es un accesorio que es fácil de usar y no es pesado, busca ser un producto de uso diario que no genere complicación alguna al momento de utilizarlo o al momento de estas realizando el ciclismo.

# Software empleado:
•	Node-RED es una herramienta de programación visual. Muestra visualmente las relaciones y funciones, y permite al usuario programar sin tener que escribir una lengua. Node-RED es un editor de flujo basado en el navegador donde se puede agregar o eliminar nodos y conectarlos entre sí con el fin de hacer que se comuniquen entre ellos.
	Version: Node-RED version: v3.1.9

•	Node. js es un entorno de ejecución JavaScript de código abierto y multiplataforma que se utiliza para desarrollar aplicaciones escalables del lado del servidor y de red
	Version: Node.js  version: v14.21.3

•	SQLite, SQLite es una herramienta de software libre, que permite almacenar información en dispositivos empotrados de una forma sencilla, eficaz, potente, rápida y en equipos con pocas capacidades de hardware, como puede ser una PDA o un teléfono celular. SQLite implementa el estándar SQL92 y también agrega extensiones que facilitan su uso en cualquier ambiente de desarrollo.
	Version: SQLite 10.3 (64 bits)

•	Arduino IDE, El entorno de desarrollo integrado de Arduino es una aplicación multiplataforma que está escrita en el lenguaje de programación Java. Este sofware es funcional para compilar codigo.
	Version: Arduino IDE 2.3.2

•	Thonny es un programa de desarrollo gratuito para PC que fue creado por un desarrollador independiente que lleva el mismo nombre. Es un entorno de desarrollo integrado (IDE) de código abierto que se puede utilizar para crear diversas aplicaciones utilizando el lenguaje de programación Python.
	Version: Thonny 4.0.2

•	Visual Studio e IDE más completo para desarrolladores de .NET y C++ en Windows para crear aplicaciones web, en la nube, de escritorio, móviles, servicios y juegos. 
	Version: Visual Studio 3.4.3

•	Wokwi es una fascinante herramienta consistente en un simulador de proyectos Arduino, que también sirve para microcontroladores ESP32 y STM32. Puede simular visualmente y mediante objetos y conexiones móviles las placas, cables y componentes y también ejecutar el código y mostrar qué es lo que hace.
	Versiones: Wokwi, la version el linea

•	TinkerCAD Diseños 3D es la herramienta que nos permitirá diseñar de la forma más sencilla objetos y piezas. Es un software CAD basado en una geometría sólida constructiva (CSG), que permite a los usuarios crear modelos mediante la combinación de objetos más simples.
Versiones: TinkerCAD, la version en linea.

• Flutter es un framework de código abierto desarrollado por Google para crear aplicaciones móviles, web y de escritorio:
        Aplicaciones móviles: Permite crear aplicaciones para Android e iOS con una sola base de código.
        Aplicaciones web: Permite crear aplicaciones web.
        Aplicaciones de escritorio: Permite crear aplicaciones para Windows y Mac, aunque aún está en fase experimental. 
  Version 3.24.2

# Librerias:
•	TFT_eSPI biblioteca de gráficos TFT para procesadores Arduino con optimización de rendimiento para RP2040, STM32, ESP8266 y ESP32.
Admite pantallas TFT utilizando controladores (ILI9341, etc.) que operan con hardware SPI o paralelo de 8/16 bits.<br>
Version: TFT_Espi 2.5.43 <br>

•	Librería en VHDL para controlar un sensor de temperatura y humedad DHT11 mediante protocolo serial OneWire. La librería realiza un muestreo cada dos segundos y realiza la operación de Checksum para compararlo con el Checksum del error y así comprobar la correcta transferencia de datos, en caso contrario se envía una señal de error la cual detiene el proceso de adquisición.<br>
Version: VHDL 1.1.0 

•         La librería #include <Wire.h> es una biblioteca de Arduino que permite a los programas comunicarse con dispositivos externos a través del protocolo Two Wire Interface (TWI o I2C).
versión 1.0

•        La librería Adafruit GFX es una biblioteca de gráficos para Arduino que se utiliza como clase base para otras bibliotecas de gráficos. Para usarla, es necesario instalarla junto con la biblioteca de visualización del hardware. 
Versión 1.0

•        La librería #include <Adafruit_SSD1306.h> es una biblioteca de controladores de pantalla que se utiliza para manejar la comunicación de pantalla, el mapeo de memoria y las rutinas de dibujo de bajo nivel. 
Version 2.4

•        La librería #include <WiFi.h> es una librería que se basa en WiFi.h de la biblioteca Arduino WiFi Shield y que es compatible con WiFi esp32.
Version 2.4

•	La librería #include <PubSubClient.h> es una biblioteca para Arduino y plataformas compatibles que permite implementar el protocolo MQTT (Message Queuing Telemetry Transport). 
Versiones 2.7

•	La librería #include <DHT.h> es una biblioteca utilizada en proyectos de Arduino para interactuar con sensores de temperatura y humedad de la serie DHT, como el DHT11 y DHT22. 
Versiones 1.40

# Hardware empleado:
| Nombre | Description | Imagen |
| --- | --- | --- |
| Sensor de Gas| son instrumentos que detectan la presencia de gases peligrosos en el aire. Su función principal es prevenir la exposición a gases tóxicos y combustibles.   | ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/GAS.jpg) |
| Sensor de temperatura    | Este sensor permitira medir la temperatura mediante una señal eléctrica determinada. Dicha señal puede enviarse directamente o mediante el cambio de la resistencia.     | ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/Sensor%20de%20temperatura.jpeg)|
| Sensor ultrasonico   | Su función es monitorear los movimientos de objetos en un espacio determinado.    | ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/Ultrasonico.png) |
| Buzzer    | El actuador Buzzer funcionara para evitar señales o aviso de emergencias  | ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/Buzzer.jpeg)|
| Leds    |  Leds para dar aviso a anomalias o cambios dentro del circuito  | ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/leds.jpeg)|
| ESP32   | Se trata de un microcontrolador que integra tecnologías WiFi y Bluetooth, que le proporcionan conectividad con internet u otros dispositivos.  | ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/nodemcu-esp32.jpg) | 
| Pantalla OLED   | Ofrecen ángulos de visión más amplios, lo que permite mostrar el contenido de la pantalla a varias personas a la vez.  | ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/OLED.webp) | 
| Sensor PIR | Los sensores infrarrojos pasivos (PIR) son dispositivos para la detección de movimiento. Son baratos, pequeños, de baja potencia, y fáciles de usar. Por esta razón son frecuentemente usados en juguetes, aplicaciones domóticas o sistemas de seguridad.  | ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/PIR.webp) | 
|Potenciómetro  | Un potenciómetro es un componente electrónico que sirve para controlar y ajustar la resistencia eléctrica en un circuito.  | ![](https://raw.githubusercontent.com/C3sarCruz/Bicicleta-inteligente/refs/heads/main/potenciometro.webp) | 
|Casco de ciclismo |Un casco de ciclismo es un elemento de seguridad diseñado para proteger la cabeza del ciclista en caso de un accidente| ![](https://raw.githubusercontent.com/C3sarCruz/Bicicleta-inteligente/refs/heads/main/Casco.webp) | 


# Historias de usuario:
**SPRINT 1 - HU1 - Desarrollo del Dashboard (Aplicación):** Yo como usuario Activo – Casco Inteligente Necesito que: El desarrollo de un Dashboard en el cual se visualice los datos que los sensores transmitan ya que estos sensores van a leer el ambiente en el cual se encuentran los ciclistas. 

Criterios de Aceptación:

•	Creación de una aplicación en la cual se visualicen los datos de los sensores.

•	Que el casto y la aplicación tengan una comunicación efectiva. 

**SPRITN 2 - HU2 – Desarrollo del circuito:** Yo como usuario Activo – Casco Inteligente Necesito que: El desarrollo del circuito el cual será el responsable de leer el comportamiento del ambiente en el que se encuentre el ciclista. 

Criterios de Aceptación:

•	Los sensores implementados hagan su funcionalidad correctamente.

•	Los actuadores implementados hagan su funcionalidad correctamente. 

**SPRINT 3 - HU3 – Integración del Dashboard y Circuito:** Yo como usuario Activo – Casco Inteligente Necesito que: se implemente el Dashboard y el circuito cumpliendo con los criterios establecidos, el casco y la aplicación web se deben de comunicarse de manera efectiva, los sensores y actuadores deben de cumplir con su función correctamente. 

Criterios de aceptación: 

•	Sensores y actuadores ya implementados en el casco.

•	Comunicación entre el casto y la aplicación de Flutter. 


# Prototipo del Dashboard

El prototipo del Dashboard en el cual se mostrará la lectura de los datos que los sensores capten, este dashboard es fácil de entender para los ciclistas, el dashboard tiene como finalidad ser atractivo para el usuario ya que es necesario generar una buena experiencia y para ello es necesario cumplir con los requerimientos. 
El dashboard cuenta con graficas con los datos de los sensores y un button para los actuadores. Cada grafica estará cambiando los datos ya que estarán cambiando constantemente dependiendo del ambiente.

![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/WhatsApp%20Image%202024-10-31%20at%2012.04.54%20PM.jpeg)

# Prototipo del Wearable
Prototipo del Wearable consiste en un casco el cual cuenta con sensores de humedad, gas, a proximidad y movimiento estos sensores generaran una lectura del ambiente en que se encuentre el ciclista y se mandara al dashboard. 
También contara con cuatro actuadores un led, pantalla oled, potenciómetro y un buzzer que trabajaran de la mano con los sensores.

![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/Wearable.jpeg)

# Beneficios del Casco Inteligente 
Beneficios del casco inteligente. 
•	Monitoreo del ambiente de un ciclista cuando realiza su actividad, para que la actividad sea más segura. 
•	En el Dashboard se mostrarán los datos que los sensores mandarán para el ciclista los pueda visualizar y ver si se encuentra en peligro o algo de su ambiente cambio. 
•	La creación de este casco inteligente es una gran oportunidad para poder automatizar el ciclismo haciendo lo más tecnológico y manteniendo a los que lo practican seguros.

# Arquitectura
La arquitectura en Capas.

* Esta arquitectura es la escogida debida ya que se divide en capas y cada una de ellas tiene una tarea en específico y pueden ser capas independientes, es decir cada capa puede estar diseñada para una tarea especifica y entre las capas pueden tener comunicación a través de una interfaz bien definida.
  
* Por ello se escogió esta arquitectura para el proyecto del casco inteligente ya que se podrá dividir en módulos independiente y tener comunicación entre ellos, es decir;
  
* En la primera capa llamada Modelo: Se define qué datos deben contener la aplicación. Si el estado de estos datos cambia, el modelo generalmente notificará a la vista (para que la pantalla pueda cambiar según sea necesario) y, a veces, el controlador (si se necesita una lógica diferente para controlar la vista actualizada).
  
* Es decir aquí entra el circuito con todos sus sensores ya que ellos nos proporcionaran la lectura del ambiente y la mostrara en la vista al usuario de una manera en la que el usuario pueda visualizarla estructurada y entendible. Cada sensor mostrara lecturas diferentes como son; la temperatura, distancia, velocidad entre otras más y así se creará la primera capa de modelo. En este modelo entra también la base de datos ya que en ella se guardarán todos los datos recolectados por los sensores y estos datos serán enviados a la vista.
  
* En la segunda capa llamada Vista: La vista define cómo se deben mostrar los datos de la aplicación. En esta capa se mostrará en Dashboard que será desarrollado para que pueda mostrar los datos que los sensores leyeron del ambiente al cual serán expuestos, en esta capa se mostraran todos los datos estructurados que serán llamados de la base de datos para que puedan ser leídos de forma por el usuario y puedan entenderlos.
  
* La tercera capa llamada Controlador: El controlador contiene una lógica que actualiza el modelo y/o vista en respuesta a las entradas de los usuarios de la aplicación. En este se conectan las capas anteriores ya que cada una tiene una tarea diferente pero que conjuntas forman en producto, en el controlador creara que la funcionalidad de cada capa forme en sistema. Esta en la comunicación que se tendrá mediante red mqtt facilita a los desarrolladores el cifrado de mensajes y la autenticación de dispositivos y usuarios mediante protocolos de autenticación modernos.
  
# Tablero Trello

+ Sprint 1. Se genero el primer spring con la integración de la placa esp32 para poder agregar las funcionalidades del sensor ultrasónico, esta placa es provisional, ya que será sustituida por una Pantalla tactil ESP32.  <br>
 ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/Trello1.jpg)
+ Sprint 2. El desarrollo del circuito el cual sera el responsable de leer el comportamiento que se tiene al momento de realizar la actividad fisica (ciclismo).  <br>
 ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/Trello2.jpg)
+ Sprint 3. Que tanto el dashboard como el circuito tengan comunicación para que puedan cumplir con su objetivo y la integracion de la pantalla inteligente.  <br>
 ![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/Trello3.jpg)

# Circuito diseñado para el proyecto completo
En el siguiente circuito se muestra como estará diseñado nuestro circuito para el casco inteligente, en el cual se muestran todos los sensores mencionados anteriormente que tendrán como objetivo generar un producto de calidad y que pueda satisfacer las necesidades de nuestros usuarios ciclistas.

![](https://github.com/C3sarCruz/Bicicleta-inteligente/blob/main/circuito%20.jpeg)

# Actividades de la unidad 3
 **Maria Guadalupe Puente Gonzalez.

 **Cesar Guerrero Cruz.

	


# Resultados 
**SPRINT 1 - HU1 - Desarrollo del Dashboard (Aplicación).** 

**SPRITN 2 - HU2 – Desarrollo del circuito.**  

**SPRINT 3 - HU3 – Integración del Dashboard y Circuito.** 

# Resultados esperados del proyecto completo
El casco inteligente, ofrecen una serie de resultados esperados para los ciclistas. A continuación, se presentan algunos de estos resultados:

* Optimización del rendimiento: El casco inteligente está diseñada para ayudar a los ciclistas a optimizar su rendimiento. Este casco utiliza sensores y actuadores llamados dispositivos inteligentes esto para proporcionar una experiencia satisfactoria, permitiendo a los ciclistas entrenar.
* Datos en el Dashboard: El casco inteligente contara con un panel en el cual se mostrarán los datos se los sensores. Es importante asegurarse de que el software que se va a utilizar sea compatible con el casco inteligente seleccionada

En resumen, el casco inteligente ofrecen la posibilidad de optimizar el rendimiento, entrenar y disfrutar de una experiencia.




 

