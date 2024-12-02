# Entwicklung einer Robotersteuerungssoftware für ein autonomes Fahrzeugmodell

Das Ziel meines autonomen Fahrzeugmodells ist es, mit einer KI basierenden Objekterkennung, ein gezeigtes Objekt (von vier verschiedenen Objekten) in einer vorgegebenen Zone zu finden und es zu einem festgelegten Zielort zurückzubringen. Der Fokus liegt dabei auf den folgenden Must Haves und Nice To Haves:

## Features
Must Haves
1.	Grundlegende Navigation:
    •	Programmierung von Bewegungsabläufen (vorwärts, rückwärts, drehen).
    •	Fähigkeit, sich autonom auf vordefinierten Pfaden zu bewegen.
2.	Hinderniserkennung und -vermeidung:
    •	Integration von Ultraschall- oder Infrarotsensoren zur Abstandsmessung.
    •	Implementierung von Algorithmen zur Echtzeit-Hindernisvermeidung.
3.	Grundlegende Sensorik:
    •	Nutzung von Sensoren zur Erkennung von Wänden und Personen.
    •	Verarbeitung der Sensordaten zur Entscheidungsfindung.
4.	Hardware-Integration:
    •	Verbindung des Raspberry Pi mit Motoren, Sensoren und ggf. Aktoren.
    •	Sicherstellung der Energieversorgung und Stabilität des Systems.
5.	Programmierung in C++:
    •	Verwendung von C++ zur Entwicklung effizienter und stabiler Software.
    •	Strukturierter und kommentierter Code für bessere Wartbarkeit.
6.	Mechanischer Arm:
    •	Entwicklung und Integration eines funktionierenden Greifarms.
    •	Programmierung der Greiffunktion für das Aufnehmen und Ablegen.
7.	Dokumentation:
    •	Ausführliche Beschreibung des Projektverlaufs und der technischen Umsetzung.
    •	Erklärung der Herausforderungen und deren Lösungen.
Nice To Haves
1.	Erweiterte Navigation:
    •	Implementierung von Karten und Pfadplanung (z.B. A*-Algorithmus).
    •	Fähigkeit, dynamisch neue Routen zu berechnen.
2.	Maschinelles Lernen:
    •	Einsatz von Machine-Learning-Algorithmen zur besseren Hinderniserkennung.
    •	Training des Systems zur Erkennung spezifischer Objekte oder Personen.
3.	Kameraintegration:
    •	Nutzung einer Kamera zur Bildverarbeitung.
    •	Objekterkennung mittels Computer Vision (z.B. OpenCV).
5.	Benutzeroberfläche:
    •	Entwicklung einer GUI zur Überwachung und Steuerung des Roboters.
    •	Anzeige von Sensordaten und Systemstatus in Echtzeit.
6.	Netzwerkkommunikation:
    •	Fernsteuerung oder -überwachung über WLAN oder Bluetooth.
    •	Möglichkeit zur Aktualisierung der Software über das Netzwerk.
7.	Energieverwaltung:
    •	Implementierung von Energiesparmodi.
    •	Anzeige des Batteriestatus und Warnung bei niedrigem Ladestand.
8.	Modulares Design:
    •	Aufbau des Roboters in modularer Bauweise für einfache Erweiterungen.
    •	Dokumentation für zukünftige Anpassungen oder Verbesserungen.
9.	Sicherheitsfunktionen:
    •	Not-Aus-Schalter und Sicherheitsprotokolle.
    •	Einhaltung von Sicherheitsstandards für Robotik-Anwendungen.

## Installation
1. Klone das Repository:
   ```bash
   git clone https://gitlab.com/danielrmv/entwicklung-einer-robotersteuerungssoftware-fuer-ein-autonomes-fahrzeugmodell.git

   cd entwicklung-einer-robotersteuerungssoftware-fuer-ein-autonomes-fahrzeugmodell

   g++ main.cpp -o robotersteuerung

## Usage
Starte das Programm:
```bash
./robotersteuerung

## Contact
Daniel Würmli  
[daniel.wuermli@icloud.com](mailto:daniel.wuermli@icloud.com)