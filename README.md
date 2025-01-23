Roboter-Projekt: 4WD Mecanum-Chassis + Greifarm (ArmPi Pro) + Raspberry Pi 5 + LiDAR + OpenCV

Willkommen in meinem Roboter-Projekt!
Dieses Repository enthält den Code, die Dokumentation und die Konfigurationen für einen autonomen Roboter, der auf einem 4WD Mecanum-Rad-Chassis basiert. Ausgestattet mit einem ArmPi Pro-Greifarm, einem Orbbec Oradar MS200 LiDAR und einer Kamera, nutzt der Roboter C++, OpenCV und den LiDAR Sensor, um Hindernisse zu vermeiden, Objekte zu erkennen und autonom zu navigieren.

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

1. Überblick

Das Ziel dieses Projekts ist es, einen vielseitigen Roboter zu entwickeln, der:
	•	Autonom navigieren kann.
	•	Hindernisse erkennt und vermeidet (LiDAR).
	•	Objekte erkennt (OpenCV) und diese mit einem Greifarm präzise manipuliert.

2. Funktionen & Features

	•	Mecanum-Wheel-Fahrgestell: Ermöglicht Bewegungen in alle Richtungen.
	•	ArmPi Pro-Greifarm: Präzise Objektmanipulation dank Servo-Motoren.
	•	Orbbec Oradar MS200 LiDAR: Hinderniserkennung, Abstandsmessung, Erkennungs der Position im Gelände und anpassung der einzelnen Motoren, um unpräzise Algorithmusberechnungen auszugleichen.
	•	OpenCV-basierte Objekterkennung: Analyse von Farben, Formen und Grössen dank KI.
	•	Modularer C++-Code: Sauber strukturierte Klassen für Navigation, Vision und Steuerung.

3. System-Architektur

Ein vereinfachtes UML-Diagramm beschreibt die Hauptklassen:
	•	RobotSystem: Koordiniert alle Subsysteme.
	•	NavigationSystem: Nutzt LiDAR-Daten für Pfadplanung, Hindernisvermeidung und Kommunikation mit MotorController.
	•	VisionSystem: Erkennt Objekte über OpenCV.
	•	ArmController: Steuert den ArmPi Pro-Greifarm.
	•	MotorController: Steuerung der Mecanum-Wheels.
	•	Logger: Schreibt Systemmeldungen und Fehler.

4. Installation & Vorbereitung

Voraussetzungen:
	•	Hardware: Raspberry Pi 4, ArmPi Pro-Greifarm, LiDAR (Orbbec Oradar MS200).
	•	Software:
	•	CMake: Für den Build-Prozess.
	•	OpenCV: Installation via sudo apt-get install libopencv-dev.
	•	LiDAR-Treiber und SDK (abhängig vom Modell).
    •   WiringPi Bibliothek

5. Setup:
	a)	Repository klonen:

git clone https://gitlab.com/danielrmv/Entwicklung-einer-Robotersteuerungssoftware-fuer-ein-autonomes-Fahrzeugmodell
    oder
    https://github.com/daniel-rmv/Entwicklung-einer-Robotersteuerungssoftware-fuer-ein-autonomes-Fahrzeugmodell

cd Implementation/RobotControlSystem


	b)	Build-Ordner erstellen und kompilieren:

mkdir build && cd build
cmake ..
make


	c)	Programm ausführen:

sudo ./RobotControlSystem
oder
./RobotControlSystem

6. Projektstruktur

RobotControlSystem/
├── CMakeLists.txt          # Build-Konfiguration
├── src/                    # Quellcode
│   ├── main.cpp            # Einstiegspunkt
│   ├── RobotSystem.cpp
│   ├── NavigationSystem.cpp
│   ├── VisionSystem.cpp
│   ├── ArmController.cpp
│   ├── MotorController.cpp
│   ├── Motor.cpp
│   ├── LidarSensor.ccp
│   ├── ServoMotor.cpp
│   ├── Motor.cpp
│   ├── Gripper.cpp
│   ├── Camera.cpp
│   └── Logger.cpp
├── include/                # Header-Dateien
├── resources/              # Trainingsdaten, Bilder
├── docs/                   # Dokumentationen, UML-Diagramme
└── README.md               # Dieses Dokument

7. Build & Run

Build:
	1.	Kompiliere das Projekt mit CMake und make.
	2.	Stelle sicher, dass alle Abhängigkeiten installiert sind.

Ausführen:
	1.	Starte das Programm mit ./RobotControlSystem oder sudo ./RobotControlSystem.
	2.	Konfiguriere ggf. Ports und Sensoreinstellungen (z. B. config.yaml).

8. Verwendung (Use Cases)

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
	•	Benutzeroberfläche: GUI zur Echtzeit-Überwachung und Steuerung.

Lizenz & Kontakt
	•	Lizenz: MIT
	•	Kontakt:
	•	GitLab: danielrmv
    •   GitHub: danielrmv   
	•	E-Mail: info@danielwuermli.com

Dieses Projekt steht unter der [MIT-Lizenz](./LICENSE). Weitere Informationen findest du in der LICENSE-Datei.

Feedback und Verbesserungsvorschläge sind jederzeit willkommen! 🎉
