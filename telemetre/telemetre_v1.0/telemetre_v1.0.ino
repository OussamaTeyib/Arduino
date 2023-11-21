/* Télémètre à ultrason
 * Sans l'utlisation d'un écran (Version portable)
 */

// La vitesse du son à 25 °C
#define VITESSE 340
// Les broches
const int trig = 7;
const int echo = 8;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(trig, LOW);
  // Préparer la voie série pour afficher les mésures
  Serial.begin(9600);
}

void loop() {
  // Déclencher le ping
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Lire la durée de l'état haute sur la broche "Echo"
  unsigned long duree = pulseIn(echo, HIGH); // en microseconds

  if (duree > 30000)
  {
    Serial.println("Onde perdue!");
  }
  else
  {
    duree /= 2;

    float temps = duree / 1000000.0; // on met en seconds
    float distance = temps * VITESSE * 100;

    Serial.print("Duree = ");
    Serial.println(temps);
    Serial.print("Distance = ");
    Serial.println(distance);
  }

  // petite pause
  delay(256);
}
