fejlettprog
===========

fantasztikus

Feladatkiírás

A feladat olyan osztálysablon írása, amely prioritási sor adatszerkezetet 
valósít meg. A sorba beszúrható elemek típusát és a rendezést a sablon 
paraméterei határozzák meg. A prioritási sor az elemeit a rendezés szerint
növekvõ sorrendben tárolja, azaz legelöl a legkisebb elemet. A prioritási sor
méretét csak a rendelkezésre álló memória korlátozza, de a dinamikusan allokált
memória felszabadítását biztosítani kell!

A sablon legyen példányosítható egy (csak típus) és két (típus és rendezés) 
paraméterrel is. Amennyiben a rendezés paraméter nincs feltüntetve 
példányosításkor, úgy az alapértelmezett rendezés a < operátort
használja.

A prioritási sor adatszerkezetnek rendelkeznie kell elõre és hátrafelé haladó
iterátorokkal, és mindkettõnek kétirányúnak kell lennie. Azaz mindkét 
iterátortípusnak támogatnia kell a ++ és -- operátorokkal történõ léptetést is.
Az elõrefelé haladó iterátor a rendezés szerinti legkisebb elemtõl kell 
induljon, és a ++ mûvelet hatására a nagyobb elemek felé lépked (-- mûveletre
fordítva), míg a hátrafelé haladó iterátor (++ esetén) a legnagyobbtól halad a
legkisebb elem felé.

Az osztálysablon publikus interfésze (a sablon neve, a sablonparaméterezése, a 
publikus metódusainak szignatúrája) kötött, azaz legalább az alábbiaknak meg
kell felelnie (de amennyiben a feladatkiírás szükségessé teszi további publikus
metódusokkal, belsõ típusokkal bõvíthetõ, valamint az osztály törzsén kívül is 
szerepelhetnek további típusok, metódusok):