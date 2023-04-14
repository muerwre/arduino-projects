#include "DHT.h"
#define DHTPIN 2 // Тот самый номер пина, о котором упоминалось выше
// Одна из следующих строк закоментирована. Снимите комментарий, если подключаете датчик DHT11 к arduino
// DHT dht(DHTPIN, DHT22);  //Инициация датчика
DHT dht(DHTPIN, DHT11);
void setup()
{
  Serial.begin(115200);
  dht.begin();
}
void loop()
{
  delay(1000);                     // 2 секунды задержки
  float h = dht.readHumidity();    // Измеряем влажность
  float t = dht.readTemperature(); // Измеряем температуру
  if (isnan(h) || isnan(t))
  { // Проверка. Если не удается считать показания, выводится «Ошибка считывания», и программа завершает работу
    Serial.println("Ошибка считывания");
    return;
  }
  Serial.print("h:");
  Serial.print(h);
  Serial.print(",");
  Serial.print("t:");
  Serial.print(t);
  Serial.println("");
}