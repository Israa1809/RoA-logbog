# RoA-logbog - Israa El-Haj Moussa
Valgfag: ***Robotter og Automatisering***

----

## 22-08-2023

På semesterets første dag, fik vi i klassen en introduktion til RoA som valgfag, 
lidt C++ og så fik vi udleveret en **NodeMCU 1.0 (ESP-12E Module)**, 
som vi skal arbejde med i forskellige projekter.

Jeg kunne desværre ikke gå igang med at eksperimentere med min NodeMCU, 
da jeg manglede et USB-C til Micro USB-kabel, 
fordi min Mac ikke understøtter den almindelige USB-indgang.
Denne blev heldigvis købt og leveret dagen efter, og morskaben kan nu for alvor gå igang. 

Derudover blev vi bedt om at downloade og konfigurere PlatformIO, 
som er et plugin til Visual Studio Code, 
som gør det muligt at programmere NodeMCU'en i **C++**.

Projekt: FirstBlink

```cpp
#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```
![](Images/NodeMCU.jpg)
-----

## 25-08-2023

I dag fik vi en opgave, der gik ud på at lave et lyskryds i gruppen. Der var ikke nok dioder til at lave 2 lyskryds, så vi kunne kun lave 1,5. 
Vi blev ikke færdige på dagen, og fortsatte derfor arbejdet i gruppen i fritiden.
![](Images/trafiklys.png)
Projekt: traficlight + video


-----

## 29-08-2023
I dag fik vi vi en ny komponent vi skulle lege med. Denne gang var det en knap. Ved at trykke på knappen kunne vi tænde for en blå diode.
Hvder gruppe i klassen fik udleveret en komponent, som vi skulle lave noget med, og så skulle vi præsentere det for resten af klassen.
Vi fik en sonar, der kunne måle afstand. Vi prøvede i lang tid at få det til at virke, dog uden held. Dagen efter prøvede Tobias så, og det viste sig, at sonaren nok var defekt. 

Projekt: Button + sonar
![](Images/button.jpg)

-----

## 31-08-2023 
I dag skulle vi downloade et setup til vores NodeMCU, så vi kunne påvirke den igennem wifi. Vi valgte i gruppen at arbejde med 3 dioder, 
der hver havde deres farve, og påvirke dem til at slukke og tænde igennem wifi. Jeg glemte desværre at tage et billede af hvordan det så ud i browseren, 
men det er faktisk bare en url, hvor det er vi kan ændre stien. fx. /1 for tænd og /2 for sluk

Projekt: Wifi + video
-----
## 05-09-2023 - syg

-----
## 07-09-2023 - syg

-----
## 12-09-2023

-----
## 15-09-2023
I dag skulle vi 3D printe en samlemekanisme til vores togbane. Vi lavede dem i plenum, og startede med en prototype, som vi så kunne lave om på,
hvis der var noget der ikke passede. Vi justerede et par gange i bl.a. hullet og tykkelsen af benen på vores pin. 
På billederne er de grønne dem vi startede med at lave. 
Den første vi lavede var løs, så vi justerede i målene for at få pin og hul til at passe bedre sammen. Så havde vi en printerfejl på
numemr 2, og denne fik vi fikset ved at sætte den til at printe igen. Den tredje endte med at blive god, men vi justerede takken på "benet" den til 2mm og 3mm som blev endnu mere robuste.
Vi lavede også nogle med runde pin's og en stor sort version, så man bedre kunne se det.
![](Images/IMG_3946.jpg)![](Images/IMG_3951.jpg)![](Images/IMG_3957.jpg)![](Images/IMG_3962.jpg)
![](Images/slutprodukt.jpg)

-----
## 19-09-2023

-----
## 22-09-2023

-----
## 26-09-2023

-----
## 29-09-2023

-----
## 03-10-2023

-----
## 06-10-2023

-----
## 10-10-2023

-----
## 13-10-2023

