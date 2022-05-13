## Installation:

# Boost:
- Unix: `pacman -S boost` / `sudo apt-get install libboost-all-dev`
- Windows: 
Download der komprimierten Archivdatei von der offiziellen Webseite: www.boost.org. Entpacken des Archiv z. B. unter „C:\Program Files“.
Anlegen einer Systemumgebungsvariable BOOST_ROOT mit dem Pfad zu den entpackten Dateien.

# g++:
- Unix:	`sudo apt-get install build-essential`

# mingw:
- Windows: Executable downloaden und enstprechend ausführen. Installationsanweisungen befolgen.

# Anwendung:
Mit dem Netzwerk Modul lassen sich Pakete der Größe 512 byte per TCP oder UDP verschicken und empfangen.

TO-DO: (Anwendungsbeispiele)

# Implementierungen:
Zusammen mit dem Verschlüsselung-Modul können die Nachrichten vor dem Versenden verschlüsselt und nach Empfang entschlüsselt werden.
Durch das Logging können (Fehler-)Meldungen, die bei der Übertragung von Nachrichten auftreten können, gewichtet, mit Zeitstempel 
in eine separate Log Datei geschrieben werden.
Mit Hilfe der Komprimierung können die Daten vor Versand komprimiert werden, um die Größe des Payloads der einzelnen 
Pakete zu verkleinern.

TO-DO: (Musterimplentierungen)

# Resúme:

TO-DO: (Was muss beim kompilieren beachtet werden?)

Die Komplexität ist sehr hoch. Es ist zwar relativ einfach mit Beispiel Code Nachrichten zu versenden und an einem anderen Gerät im Netzwerk,
welches auf dem jeweiligen Port lauscht, zu empfangen. Aber es gestaltet sich schwierig, eine Client - Server Kommunikation zu etablieren.

Die Installation der Libraries unter Windows ist sehr fehleranfällig und zeitintensiv.


