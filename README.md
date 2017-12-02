
# Tincon / A MAZE. Alternative Controller Workshop 2017

Ziel: Baue dein individuelles Eingabegerät<br>
Material: Arduino mit 32U4-Chip, Arcade-Buttons, Sensor-Module, Jumper-Kabel

Für dieses Projekt geeignet sind Arduinos mit 32U4-Chip (z.B. "Leonardo") - denn diese melden sich am PC als Tastatur an, wenn sie per USB angeschlossen werden. Mit relativ wenigen Zeilen Code können Eingaben am Arduino (z.B. durch Sensoren) als Tastatur-Eingabe weitergereicht werden.

## Hardware

Passende <b>Arduino-Boards</b> sind im Internet erhältlich - z.B. via Ebay, hier wird einfach nach "32U4" gesucht. Manche Angebote kommen aus China und es kann einige Wochen dauern, bis von hier geliefert wird. Lieferungen aus Deutschland sind etwas teurer, dafür wird schnell geliefert.

<b>Sensoren</b> können einzeln oder "gebrauchsfertig" als Module gekauft werden. Zum Einstieg in die Sensoren-Welt empfiehlt sich ein Sensor-Kit. Suche dafür auf Ebay nach "arduino sensor kit". 

Der Sensor wird mit Jumper-Kabeln mit dem Arduino verbunden. 

Hier die Schaltung für die Sensor-Module
![Alt text](Schaltplan/Sensor.jpg?raw=true "Title")

Für einfache Buttons kann die Pullup-Schaltung verwendet werden
![Alt text](Schaltplan/Pullup-Button.jpg?raw=true "Title")

Und so ein Accelerometer-Modul könnte eine Maus ersetzen
![Alt text](Schaltplan/Accelerometer.jpg?raw=true "Title")
Um dieses Modul zu nutzen, wird eine weitere Bibliothek benötigt. Hier ein (englisches) Tutorial zu der Komponente: https://playground.arduino.cc/Main/MPU-6050

## Software

Zuerst wird die Entwicklungsumgebung "Arduino IDE" installiert -> https://www.arduino.cc/en/main/software
<br>Das Arduino-Board wird per USB mit dem PC verbunden und in der IDE unter Werkzeuge/Board/Arduino Leonardo ausgewählt.
<br>TC_SensorInput.ino wird in der IDE geöffnet und über einen Klick auf den Pfeil oben links ("Hochladen") auf den Arduino übertragen.

Auf manchen Betriebssystemen mit manchen Leonardo-Boards funktioniert das einfach so - sollte das Hochladen aber nicht funktionieren, liegt es wahrscheinlich an dem Tastatur-Modus, mit dem das Board gerade registriert ist. Um das Board in den Übertragungsmodus zu versetzen, wird der Reset-Button auf dem Leonardo gedrückt und gehalten, während man den Upload startet.

Um den Code an die eigene Schaltung anzupassen, können diese Zeilen verändert werden:

```c
int signalPlayer1 = 8;          // der Pin für Player 1
int signalPlayer2 = 9;          // der Pin für Player 2

const char keyPlayer1 = 'q';    // die "Taste", die Player 1 drückt
const char keyPlayer2 = 'p';    // die "Taste", die Player 2 drückt

boolean analogInput = false;    // sollen analoge Signale verarbeitet werden: analogInput = true;
boolean pullupPinMode = true;   // wurde eine Pullup-Button-Schaltung gebaut: pullupPinMode = true; 
```

Was leider <b>nicht</b> funktioniert:
Sondertasten wie SHIFT oder CTRL sind sogenannte "Modifizierer" und können nicht als eigenständige Inputs an den PC gesendet werden :(

