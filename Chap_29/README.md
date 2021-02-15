<b>Gruppe 15 | Tobias Schoch, Luis Nothvogel <br>
Aufgaben wurden auf dem HTWG Container ausgeführt </b> <br> <br>
<b>29.4</b> <br>
Die Vermutung liegt nahe, dass bei geringer Threadanzahl die HoH-LinkedList schlechter performed als die normale LinkedList denn für wenige Iterationen wäre dies zu viel Overhead. Bei höherer Threadanzahl performed vermutlich die HoH-LinkedList besser, da gleichzeitig drüber iteriert werden kann. Und bei der LinkedList muss jedes mal auf die gesamte Iteration gewartet werden. 
Im Beispiel unten haben wir jeweils die Version aus dem Buch (linkedlist) und unsere (linkedListHoH) mit 1 Thread und mit 20 Threads laufen lassen. Wir haben hierbei eine Listgröße von 10000 verwendet und das zu findende Element 60. Wir haben verschieden große Listgrößen zum testen verwendet (10, 100, 1000, 10000, 100000). Bei kleineren Listen (10, 100, 100, 1000) war die Version aus dem Buch immer schneller egal wie viele Threads wir hatten. Erst bei größeren Listgrößen von (10.000, 100.000…) ergab sich das angenommene Verhalten. Also ist anzunehmen, dass man erst eine bestimmte Anzahl von Iteration benötigt damit die HoH-LinkedList besser ist. <br>
<br><b>29.5</b><br>
Wir haben uns für einen balancierten Binärbaum mit einfachem Lock entschieden. Also einer vom Buch vorgeschlagenen Datenstruktur. Wir haben dafür immer eine init, insert und search methode implementiert. Diese sollten mit code kommentaren selbsterklärend sein.<br>
Wie man an den Screenshots sehen kann, wird die Performance immer besser je mehr Threads dazu kommen. Allerdings haben wir bei 20 Threads einen Performance Cap. Bei 30, 40 … usw. wurde es nicht mehr besser von der Performance. <br>

<b>29.6</b> <br>
Wir haben im Grunde das Gleiche gemacht wie bei der LinkedListe. Denn wir haben uns für ein Couple Locking entschieden. Die Erwartung wird vermutlich ähnlich wie bei der LinkedList sein. D.h. bei geringer Threadanzahl dürfte die Version mit dem simplen Lock besser performen und bei höherer Threadanzahl dürfte die Version mit couple locking besser performen.
Wir haben das ganze wie bei 29.5 mit verschieden vielen Threads getestet. Wir haben immer 600 Iterationen verwendet. Allerdings war zu bemerken, dass die Version mit dem simplen lock immer schneller war. Wir haben das ganze dann nochmal mit mehr Iteration wie bei 29.4 getestet, doch es kam immer noch dasselbe raus.

<b>Wo wird gemessen, und warum wird da gemessen? </b> <br>
Wir starten die Messung immer vor der while schleife und beenden diese nachdem der Lesezugriff gemacht wurde. Dadurch erhalten wir die Zeit die der Thread gebraucht hat um zu der gewünschten Stelle zu iterieren. <br>

<b>Welche locking strategies wurden benutzt und warum?</b> <br>
Wir haben uns für das couple locking entschieden da dies gut im Buch beschrieben war und wir dies vorher bei der LinkedList schonmal verwendert hatten. Diese ist auch recht einfach zu implementieren.