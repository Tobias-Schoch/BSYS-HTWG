chap5_1
In dieser Datei initalisieren wir eine Variable mit einer Zahl, verändern diese und schauen inwiefern dies Einfluss hat auf Child und Parent Prozess.

chap5_2
In dieser Datei öffnen wir eine File und schauen, ob sie sowohl von Child als von Parent geöffnet werden kann. 
Dafür benötigen wir die dont-delete-me.txt

chap5_3
Alternativmethode zu wait(). Wir verwenden hierfür eine Methode mit kill() - SIGSTOP / SIGCONT.

chap5_4
Wir lassen viele verschiedene exec() versionen laufen.

chap5_5
Mit wait() sorgen wir dafür, dass der Parent Prozess solange wartet, bis der Child Prozess fertig ist.

chap5_6
Mit waitpid() ersetzen wir wait() mit dem selben Programmcode wie in chap5_5.

chap5_7
Im Child Prozess schließen wir den Standard Output und schauen ob danach noch etwas ausgegeben wird. 

chap5_8
In dieser File schließen wir in Kind1 den Standard Output und leiten den Output von Kind1 mittels einer Pipe zu Kind2. 
