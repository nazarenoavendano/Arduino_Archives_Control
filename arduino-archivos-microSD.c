#include <SD.h>

#define PIN_SPI_CS 6

void setup() {
  Serial.begin(9600);

  if (!SD.begin(PIN_SPI_CS)) {
    Serial.println("La tarjeta SD no se pudo iniciar");
    while (1);
  }

  File file = SD.open("archivoNaza.txt", FILE_WRITE);

  if (file) {
    file.println("¡Hola, desde mi Arduino!");
    file.close();
  } else {
    Serial.println("Error con el archivo.");
  }

  file = SD.open("archivo.txt", FILE_READ);

  if (file) {
    while (file.available()) {
      Serial.write(file.read());
    }
    file.close();
  } else {
    Serial.println("Error al abrir el archivo.");
  }
}

void loop() {
  //acá podría tomar medidas de un sensor 
}

