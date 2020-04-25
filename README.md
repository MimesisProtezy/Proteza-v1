# Proteza-v1 🦾

<img src="https://i.imgur.com/YyTsZdl.jpg" width="70%">

To jest repozytorium ze wszystkimi plikami niezbędnymi do wykonania protezy bionicznej, która powstała w ramach olimpiady Zwolnieni z Teorii.<meta name="google-site-verification" content="7BU-_dNy4WX7rQMSjwO5azxOfN85TyO-x6rC1iT2Cm4" />

## Wstęp
Profesjonalne protezy bioniczne dostępne na rynku potrafią kosztować dzisiątki tysięcy złotych. Postanowiliśmy zaproponować znacznie tańszą alternatywę o podobnej funkcjonalności.
Pamiętaj, że jest to pierwsza wersja tego urządzenia i będzie ono udoskanalane.
W pierwszym prototypie zdecydowaliśmy się na podzielenie projektu na dwie części: właściwą protezę oraz opaskę sterującą. W protezie znajdują się serwa, baterie i ESP32, które wszystkim steruje, a w opasce sensory EMG, mała bateria oraz kolejne ESP32 odpowiedzialne za pobieranie danych z sensorów i przekazywania ich do protezy.

# Przygotowania

#### Narzędzia niezbędne do wykonania protezy ⚒️

* wkręty 2,5mm (często trzeba je przyciąć do pożądanej długości)
* śrubki 3mm
* nakrętki 3mm
* śrubokręt albo wkrętarka
* pilniki (do wykańczania wydruków)
* klej błyskawiczny np. kropelka (lub aceton w przypadku wydruku z ABS)
* żyłka wędkarska (najlepiej nie nylonowe, ponieważ ulegają one rozciągnięciu)
* lutownica
* drukarka 3D (my drukowaliśmy na Enderze 3)

#### Komponenty elektroniczne protezy 🦾

* [ESP32](https://botland.com.pl/pl/moduly-wifi/8893-esp32-wifi-bt-42-platforma-z-modulem-esp-wroom-32-zgodny-z-esp32-devkit.html) x2
* [Sensor emg](https://botland.com.pl/pl/czujniki-medyczne/5978-myoware-muscle-sensor-czujnik-do-pomiaru-aktywnosci-miesni-emg-869249000109.html) x3 - odczyt sygnałów elektrycznych z mięśni
* [Elektrody biomedyczne](https://botland.com.pl/pl/czujniki-medyczne/2604-elektrody-biomedyczne-10szt.html) x 2 (lub więcej) opakowań
* [Przewody do elektrod](https://botland.com.pl/pl/czujniki-medyczne/2605-przewody-do-elektrod-biomedycznych.html)
* [Powerboost](https://botland.com.pl/pl/ladowarki-lipol-moduly/10171-dfrobot-mp2636-power-booster-charger-module-modul-ladowarki-li-ionli-pol-6v25a.html) - odpowiedzialny za zasilanie oraz ładowanie protezy
* [Serwo](https://botland.com.pl/pl/serwa-typu-micro/10311-serwo-feetech-wing-ft3325m-micro.html) x4 - zdecydowaliśmy się na ten produkt ponieważ najlepiej spełnia parametry wystarczającej siły, głośności pracy oraz ceny
* [Zasilacz](https://botland.com.pl/pl/zasilacze-do-raspberry-pi-4b/7820-zasilacz-extreme-5v-31a-ze-zlaczem-usb-c-dla-raspberry-pi-4b-5901445617509.html) - można użyć innego zasilacza o podobnych parametrach
* [Złącze usb typu C do płytki stykowej](https://botland.com.pl/pl/akcesoria-do-plytek-stykowych/12658-pololu-usb-20-typ-c-zlacze-do-plytki-stykowej.html) x2 - umożliwa łatwy dostęp do portów ładowania i programowania
* [Ogniwa li-pol 2200mah](https://botland.com.pl/pl/akumulatory-li-pol/1313-ogniwo-li-pol-redox-2200mah-20c-1s-37v-90009947.html) x3
* [Gniazdo jack](https://botland.com.pl/pl/przewody-i-zlacza-audio/2734-gniazdo-jack-35-mm-stereo-zenskie-jy039-5p.html) x3 - umożliwa łatwe podłączenie przewodów elektrod

#### Komponenty elektroniczne opaski sterującej 🎛️

* [ESP32](https://botland.com.pl/pl/moduly-wifi/8893-esp32-wifi-bt-42-platforma-z-modulem-esp-wroom-32-zgodny-z-esp32-devkit.html)
* [Akumulator li-pol 1200mah](https://botland.com.pl/pl/akumulatory-li-pol/14159-akumulator-li-pol-akyga-1200mah-1s-37v-zlacze-jst-bec-gniazdo-50x34x6mm.html) - mały pobór energii opaski sterującej umożliwia umieszczenie mniejszej baterii, co pozwala na większy komfort użytkowania
* [Gniazdo do akumulatorów li-pol](https://botland.com.pl/pl/akcesoria-do-akumulatorow/1320-gniazdo-jst-bec-do-akumulatorow-li-pol.html) opaska jest ładowana przy użyciu PowerBoosta z protezy. To gniazdo usprawnia proces podłączania opaski do ładowania.

#### Pliki 3D do wydruku 🖨️

* [Dłoń](https://github.com/MimesisProtezy/Proteza-v1/tree/master/STLs/D%C5%82o%C5%84) - folder ze wszystkimi plikami potrzebnymi do wydrukowania dłoni protezy (można je pobrać także ze strony inmoov.fr)
* [Przedramię](https://github.com/MimesisProtezy/Proteza-v1/tree/master/STLs/Przedrami%C4%99) - folder z częściami przedramienia
* [Obudowa na baterie](https://github.com/MimesisProtezy/Proteza-v1/tree/master/STLs/Battery%20holder) - obudowa służąca do przymocowania baterii wewnątrz przedramienia
* [Obudowa na serwa](https://github.com/MimesisProtezy/Proteza-v1/tree/master/STLs/Servo%20holder) - obudowa służaca do przymocowania serw wewnątrz przedramienia
* [Nadgarstek](https://github.com/MimesisProtezy/Proteza-v1/blob/master/STLs/Wrist.stl) - umożliwia połączenie dłoni z przedramieniem
* [Nakładka na serwo](https://github.com/MimesisProtezy/Proteza-v1/blob/master/STLs/Servo%20pulley.stl) x4 - do tej częsci przywiązywane będą żyłki odpowiedzialne za ruch palców

# Wykonanie

#### Dłoń
Model dłoni został zbudowany w oparciu o projekt [InMoov](http://inmoov.fr/) dlatego zachęcamy do kierowania się ich fantastyczną instrukcją składania [dłoni](http://inmoov.fr/hand-and-forarm/) oraz [palców](http://inmoov.fr/finger-starter/)

#### Przedramię

Proces składania przedramienia należy rozpocząć od wydrukowania wszystkich niezbędnych części ([Przedramię](https://github.com/MimesisProtezy/Proteza-v1/tree/master/STLs/Przedrami%C4%99), [Obudowa na baterie](https://github.com/MimesisProtezy/Proteza-v1/tree/master/STLs/Battery%20holder), [Obudowa na serwa](https://github.com/MimesisProtezy/Proteza-v1/tree/master/STLs/Servo%20holder), [Nadgarstek](https://github.com/MimesisProtezy/Proteza-v1/blob/master/STLs/Wrist.stl)). Niektóre części, takie jak przedramię oraz obudowa na serwa będą wymagały drukowania z supportami, które po wydrukowaniu należy usunąć.

Kolejnym krokiem jest połączenie części obudowy na serwa w sposób przedstawiony na zdjęciu poniżej. Do złączenia części można użyć kleju szybkoschnącego takiego jak kropelka albo żywicy 5-minutowej.

<img src="https://i.imgur.com/VnTXLiS.png" width="40%">

Następnie na zębatki w serwach należy nałożyć [nakładki](https://github.com/MimesisProtezy/Proteza-v1/blob/master/STLs/Servo%20pulley.stl) i dokręcić je dołączonymi do serw śrubkami. Później wszystkie serwa przykręcamy do wydrukowanej i sklejonej wcześniej obudowy w sposób przedstawiony poniżej. Należy do tego użyć przyciętych do odpowiedniej długości 2.5 milimetrowych wkrętów. Złącza wychodzące z serw należy przeprowadzić przez odpowiednie otwory w obudowie.

<img src="https://i.imgur.com/Id26Rsu.png" width="40%">

Kolejnym krokiem jest przykręcenie obudowy na serwa wraz z zamontowanymi serwami w obudowie przedramienia. Należy użyć do tego pięciu 2.5 milimetrowych wkrętów.

<img src="https://i.imgur.com/qxjEH11.png" width="40%">

W tym momencie można przejść do złożenia obudowy na akumulatory. Pliki części obudowy na akumulatory zostały ponumerowane od góry do dołu, aby ułatwić złożenie. Poszczególne części należy połączyć wkrętami, wkręcając je przez wystające otwory montażowe. Oprócz tego części 1 i 2, 3 i 4, 5 i 6 należy skleić klejem szybkoschnącym.

<img src="https://i.imgur.com/xywRO7s.png" width="40%">

Po umieszczeniu akumulatorów w obudowie należy zlutować je równolegle. W tym momencie warto jest też przylutować powerboost'a do równolegle połączonych akumulatorów, mając na uwadze długość przewodów niezbędną do połączenia powerboost'a z akumulatorami, gdy będą już umieszczone w obudowie. Przed umieszczeniem akumulatorów w obudowie przedramienia należy przykręcić dwa [złącza USB typu C](https://botland.com.pl/pl/akcesoria-do-plytek-stykowych/12658-pololu-usb-20-typ-c-zlacze-do-plytki-stykowej.html) w sposób pokazany na zdjęciu poniżej. Nad złączami USB przykręcamy powerboost'a za pomocą jednego wkręta.

<img src="https://i.imgur.com/glh0Nix.png" width="40%">

Do jednego złącza USB typu C należy przylutować kabel zakończony z drugiej strony złączem USB typu A. Koniec kabla zakończony USB typu A podłączamy do portu USB w powerboost'cie. Dzięki temu jesteśmy w stanie w łatwy sposób ładować akumulatory w protezie poprzez podłączenie ładowarki zakończonej USB typu C. Przy lutowaniu kabla USB do złącza USB typu C w protezie nie jest konieczne łączenie wszystkich pinów. Wystarczy połączyć te odpowiedzialne za przesył prądu a nie danych (+5v i GND).

Do drugiego złącza typu C umieszczonego w protezie lutujemy kabel zakończony z drugiej strony złączem micro USB. Podłączamy go do portu USB w esp32. Dzięki temu będziemy w stanie programować esp32 podłączając się do niego w łatwy sposób. W tym wypadku musimy przylutować piny odpowiedzialne za przesył prądu i danych (+5v, D-, D+, GND).

Następnie możemy przykręcić wcześniej złożoną obudowę na akumulatory do protezy, w sposób pokazany na zdjęciu poniżej. Będą do tego potrzebne trzy wkręty. 

<img src="https://i.imgur.com/C7v4YeU.png" width="40%">

WIP

#### Schemat elektroniki w przedramieniu

<img src="https://i.imgur.com/ahhtjhWl.png" width="40%">

#### Opaska

Wszystkie elementy są połączone kablami według schematu i schowane w opasce z odpowiednimi wyprowadzeniami do przymocowania elektrod do sensorów EMG.

#### Schemat elektroniki w opasce

<img src="https://i.imgur.com/WfGwEmi.png" width="40%">

# Projekt realizowany w ramach olimpiady
<img src="https://zwolnienizteorii.pl/img/svg/zwzt_short.svg" width="15%">

# Sponsor projektu
<img src="https://i.imgur.com/eIJHFis.png" width="15%"> 

# Patroni medialni
<img src="https://i.imgur.com/1ywwYhg.jpg" width="20%" hspace="20">   <img src="https://i.imgur.com/eoWqzBg.png" width="15%" hspace="20">   <img src="https://i.imgur.com/Ypk4uo5.png" width="23%" hspace="20">   

# Partnerzy
<img src="https://i.imgur.com/Eoj9aD3.png" width="8%" hspace="20">      <img src="https://i.imgur.com/V6tm11q.png" width="25%" hspace="20">      <img src="https://i.imgur.com/fIbxIPx.png" width="10%" hspace="20">      <img src="https://i.imgur.com/crWA505.png" width="20%" hspace="20">

<img src="https://i.imgur.com/jsir4he.png" width="20%" hspace="20">      <img src="https://i.imgur.com/a5qzGyo.jpg" width="20%" hspace="20">
