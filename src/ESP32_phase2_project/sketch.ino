#include <DHT.h>

#define DHTPIN 27
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Pinos dos botões (N, P, K)
#define BTN_N 15
#define BTN_P 2
#define BTN_K 4

// Sensor de pH (LDR)
#define LDR_PIN 34

// Relé (bomba)
#define RELAY_PIN 5

// Estados "toggle" dos nutrientes
bool nState = false;
bool pState = false;
bool kState = false;

// Estados anteriores dos botões
bool lastN = HIGH;
bool lastP = HIGH;
bool lastK = HIGH;

int humidity = 40;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(BTN_N, INPUT_PULLUP);
  pinMode(BTN_P, INPUT_PULLUP);
  pinMode(BTN_K, INPUT_PULLUP);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  // Leitura atual dos botões
  bool currentN = digitalRead(BTN_N);
  bool currentP = digitalRead(BTN_P);
  bool currentK = digitalRead(BTN_K);

  // Detecta clique no botão N
  if (lastN == HIGH && currentN == LOW) {
    nState = !nState;
    delay(200);
  }

  // Detecta clique no botão P
  if (lastP == HIGH && currentP == LOW) {
    pState = !pState;
    delay(200);
  }

  // Detecta clique no botão K
  if (lastK == HIGH && currentK == LOW) {
    kState = !kState;
    delay(200);
  }

  // Atualiza os estados anteriores
  lastN = currentN;
  lastP = currentP;
  lastK = currentK;

  // Leitura do LDR (pH)
  int ldrValue = analogRead(LDR_PIN);
  float ph = map(ldrValue, 0, 4095, 0, 14);

  // Umidade do solo (simulada pelo DHT)
  float umidade = dht.readHumidity() + humidity;

  // Exibição serial
  Serial.print(nState);
  Serial.print(","); Serial.print(pState);
  Serial.print(","); Serial.print(kState);
  Serial.print(","); Serial.print(ph, 1);
  Serial.print(","); Serial.print(umidade);

  bool condicoesIdeais = false;

  // Condição para acionar a irrigação
  bool temNPK = nState && pState && kState;
  bool phIdeal = ph >= 6 && ph <= 7;
  bool abaixoUmidadeIdeal = umidade < 80;
  if (temNPK && phIdeal && abaixoUmidadeIdeal) {
    condicoesIdeais = true;
  }

  // Controle da bomba
  digitalWrite(RELAY_PIN, condicoesIdeais ? HIGH : LOW);

  if (condicoesIdeais) {
    humidity += 5;
  } else {
    humidity -= 2;
  }
  Serial.print(","); Serial.print(condicoesIdeais);
  Serial.println();

  delay(1000);
}
