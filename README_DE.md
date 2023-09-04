# Splines
## Willkommen zum Bezier-Splines-Projekt! Dieses Projekt bietet eine einfache und bequeme Möglichkeit, Bezier-Splines mit der eigenen hochstufigen Visualisierungsbibliothek [`TESTWIN32APP_GRAPHICAPP`](https://github.com/quqveik1/TESTWIN32_GRAPHICAPP) zu erstellen und zu visualisieren.

## Funktionen des Programms
- Benutzer können auf den Bildschirm klicken, um Steuerpunkte für die Splines festzulegen.
- Falls ein Fehler gemacht wurde, kann der Benutzer den Bildschirm löschen und neue Steuerpunkte auswählen.

<img src="https://user-images.githubusercontent.com/64206443/235349246-40d57425-71fa-4c71-8611-0360a097dc5b.png" width="600">

## Technische Komponenten

Das Projekt besteht aus zwei Hauptklassen:

### 1. SplineArr

`SplineArr` ist eine Klasse, die die Schlüsselpunkte des Splines speichert und Funktionen für die Arbeit mit ihnen bietet.
Die Hauptidee hinter dieser Klasse besteht darin, dass sie Zwischenpunkte generieren kann, wenn Sie Nicht-Ganzzahlen an operator[] übergeben. Wenn Sie operator[] mit Ganzzahlen aufrufen, werden die Steuerpunkte zurückgegeben.

- `keyPoints`: Vektor der Schlüsselpunkte des Splines
- `calcPoint(double dindex)`: Berechnet einen Punkt auf dem Spline mit einem Bruchindex
- `size() const`: Gibt die Anzahl der Schlüsselpunkte des Splines zurück
- `push(Vector point)`: Fügt einen neuen Schlüsselpunkt zum Spline hinzu
- `sortedPush(Vector point)`: Fügt einen neuen Schlüsselpunkt zum Spline hinzu und sortiert die Punkte
- `sort()`: Sortiert die Schlüsselpunkte des Splines
- `clear()`: Löscht den Spline (entfernt alle Schlüsselpunkte)
- `operator[](size_t index)`: Gibt eine Referenz auf den Schlüsselpunkt mit dem angegebenen Index zurück
- `operator[](double dindex)`: Gibt einen Spline-Punkt mit einem Bruchindex zurück

### 2. SplineControl

`SplineControl` ist von [`MultiLayCoordinatSystemWindow`](https://github.com/quqveik1/TESTWIN32_GRAPHICAPP/blob/main/MultiLayCoordinatSystemWindow.h) abgeleitet und bietet Funktionen für die Benutzerinteraktion und die Verwaltung der Visualisierung von Bezier-Splines. Es hat die folgenden Eigenschaften und Methoden:

- `splineArr`: `SplineArr`-Objekt, das die Schlüsselpunkte des Splines enthält
- `keyPointsColor`: Farbe der Schlüsselpunkte
- `keyPointsLayIndex`: Schichtindex, auf dem die Schlüsselpunkte angezeigt werden
- `keyPointsR`: Radius der Schlüsselpunkte
- `interPolDelta`: Interpolationsdelta für das Zeichnen von Splines
- `SplineControl(AbstractAppData* _app)`: Klassenkonstruktor
- `updateScreenPoints()`: Aktualisiert Bildschirmpunkte basierend auf den aktuellen Schlüsselpunkten des Splines
- `pushStartPoints()`: Fügt Startpunkte für die Demonstration hinzu
- `onClick(Vector mp)`: Mausklick-Ereignishandler
- `onMessageRecieve(const char* name, void* data)`: Nachrichtenhandler für die Auswahl von Steuerpunkten

--------------------------
# Anleitung zum Starten der Anwendung unter Windows
- Anforderungen: Für die vollständige Funktionalität der Anwendung ist Windows 7 erforderlich.
- Laden Sie die Anwendung von diesem Link herunter: https://github.com/quqveik1/Splines/releases/latest
- Führen Sie die heruntergeladene .exe-Datei aus und ignorieren Sie Antivirus-Warnungen, die besagen, dass das Programm gefährlich ist.
In diesem Fenster sollten Sie auf diese Schaltfläche klicken.

<img src="https://user-images.githubusercontent.com/64206443/182945554-ed4d18c6-a25d-4d0d-a331-e268643b3031.png" width="400">

- Der Installationsassistent der Anwendung wird geöffnet; befolgen Sie die Anweisungen.
