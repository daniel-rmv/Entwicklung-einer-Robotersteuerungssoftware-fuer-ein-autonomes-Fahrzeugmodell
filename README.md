Roboter-Projekt: 4WD Mecanum-Chassis + Greifarm (ArmPi Pro) + Raspberry Pi 5 + LiDAR + OpenCV

Willkommen in meinem Roboter-Projekt!
Dieses Repository enthält den Code, die Dokumentation und die Konfigurationen für einen autonomen Roboter, der auf einem 4WD Mecanum-Rad-Chassis basiert. Ausgestattet mit einem ArmPi Pro-Greifarm, einem Orbbec Oradar MS200 LiDAR und einer Kamera, nutzt der Roboter C++, OpenCV und weitere Technologien, um Hindernisse zu vermeiden, Objekte zu erkennen und autonom zu navigieren.

Inhaltsverzeichnis
	1.	Überblick
	2.	Funktionen & Features
	3.	System-Architektur
	4.	Installation & Vorbereitung
	5.	Projektstruktur
	6.	Build & Run
	7.	Verwendung (Use Cases)
	8.	Weiterentwicklung
	9.	Lizenz & Kontakt

Überblick

Das Ziel dieses Projekts ist es, einen vielseitigen Roboter zu entwickeln, der:
	•	Navigieren kann (holonomes Fahren mit Mecanum-Wheels).
	•	Hindernisse erkennt und vermeidet (LiDAR).
	•	Objekte erkennt (OpenCV) und diese mit einem Greifarm präzise manipuliert.

Funktionen & Features
	•	Mecanum-Wheel-Fahrgestell: Ermöglicht Bewegungen in alle Richtungen.
	•	ArmPi Pro-Greifarm: Präzise Objektmanipulation dank Servo-Motoren.
	•	Orbbec Oradar MS200 LiDAR: Hinderniserkennung, Abstandsmessung und potenzielles SLAM.
	•	OpenCV-basierte Objekterkennung: Analyse von Farben, Formen und KI-Modelle.
	•	Modularer C++-Code: Sauber strukturierte Klassen für Navigation, Vision und Steuerung.

System-Architektur

Ein vereinfachtes UML-Diagramm beschreibt die Hauptklassen:
	•	RobotSystem: Koordiniert alle Subsysteme.
	•	NavigationSystem: Nutzt LiDAR-Daten für Pfadplanung und Hindernisvermeidung.
	•	VisionSystem: Erkennt Objekte über OpenCV.
	•	ArmController: Steuert den ArmPi Pro-Greifarm.
	•	MotorController: Steuerung der Mecanum-Wheels.
	•	Logger: Schreibt Systemmeldungen und Fehler.

Installation & Vorbereitung

Voraussetzungen:
	•	Hardware: Raspberry Pi 5, ArmPi Pro-Greifarm, LiDAR (Orbbec Oradar MS200).
	•	Software:
	•	CMake: Für den Build-Prozess.
	•	OpenCV: Installation via sudo apt-get install libopencv-dev.
	•	LiDAR-Treiber und SDK (abhängig vom Modell).

Setup:
	1.	Repository klonen:

git clone https://gitlab.com/danielrmv/Entwicklung einer Robotersteuerungssoftware für ein autonomes Fahrzeugmodell.git
cd RoboterProjekt


	2.	Build-Ordner erstellen und kompilieren:

mkdir build && cd build
cmake ..
make


	3.	Programm ausführen:

./RoboterProjekt

Projektstruktur

RoboterProjekt/
├── CMakeLists.txt          # Build-Konfiguration
├── src/                    # Quellcode
│   ├── main.cpp            # Einstiegspunkt
│   ├── RobotSystem.cpp
│   ├── NavigationSystem.cpp
│   ├── VisionSystem.cpp
│   ├── ArmController.cpp
│   ├── MotorController.cpp
│   └── ...
├── include/                # Header-Dateien
├── resources/              # Trainingsdaten, Bilder
├── docs/                   # Dokumentationen, UML-Diagramme
└── README.md               # Dieses Dokument

Build & Run

Build:
	1.	Kompiliere das Projekt mit CMake und make.
	2.	Stelle sicher, dass alle Abhängigkeiten installiert sind.

Ausführen:
	1.	Starte das Programm mit ./RoboterProjekt.
	2.	Konfiguriere ggf. Ports und Sensoreinstellungen (z. B. config.yaml).

Verwendung (Use Cases)

1. Navigation & Hindernisvermeidung
	•	Ziel: Der Roboter navigiert sicher zu vordefinierten Wegpunkten.
	•	Ablauf:
	1.	NavigationSystem::navigate(myPath)
	2.	LiDAR erkennt Hindernisse.
	3.	Der Roboter weicht aus oder stoppt.

2. Objekterkennung & Greifen
	•	Ziel: Der Roboter erkennt Objekte (z. B. “roter Würfel”) und greift diese.
	•	Ablauf:
	1.	VisionSystem::detectObjects()
	2.	ArmController::pickObject()
	3.	Objekt wird transportiert und abgelegt.

Weiterentwicklung
	•	ROS2-Integration: SLAM für dynamische Navigation.
	•	Erweiterte Objekterkennung: TensorFlow oder YOLO für komplexere Modelle.
	•	Benutzeroberfläche: GUI zur Echtzeit-Überwachung und Steuerung.

Lizenz & Kontakt
	•	Lizenz: MIT
	•	Kontakt:
	•	GitLab: danielrmv
	•	E-Mail: info@danielwuermli.com

Feedback und Verbesserungsvorschläge sind jederzeit willkommen! 🎉

MIT License

Copyright (c) 2025 Daniel Würmli

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.