# Proteza-v1 🦾

<img src="https://i.imgur.com/YyTsZdl.jpg" width="70%">

To jest repozytorium ze wszystkimi plikami niezbędnymi do wykonania protezy bionicznej, która powstała w ramach olimpiady Zwolnieni z Teorii.

## Wstęp
Profesjonalne protezy bioniczne dostępne na rynku potrafią kosztować dzisiątki tysięcy złotych. Postanowiliśmy zaproponować znacznie tańszą alternatywę o podobnej funkcjonalności.
Pamiętaj, że jest to pierwsza wersja tego urządzenia i będzie ono udoskanalane.
W pierwszym prototypie zdecydowaliśmy się na podzielenie projektu na dwie części: właściwą protezę oraz opaskę sterującą. W protezie znajdują się serwa, baterie i ESP32, które wszystkim steruje, a w opasce sensory EMG, mała bateria oraz kolejne ESP32 odpowiedzialne za pobieranie danych z sensorów i przekazywania ich do protezy.

# Przygotowania

#### Narzędzia niezbędne do wykonania protezy ⚒️

* wkręty 2,5mm (często trzba je przyciąć do pożądanej długości)
* śrubki 3mm
* nakrętki 3mm
* śrubokręt albo wkrętarka
* pilniki (do wykańczania wydruków)
* klej błyskawiczny np. kropelka (lub aceton w przypadku wydruku z ABS)
* żyłka wędkarska (najlepiej nie nylonowe, ponieważ ulegają one rozciągnięciu)
* lutownica

#### Komponenty elektroniczne protezy 🦾

* [ESP32](https://botland.com.pl/pl/moduly-wifi/8893-esp32-wifi-bt-42-platforma-z-modulem-esp-wroom-32-zgodny-z-esp32-devkit.html)
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

WIP

# Wykonanie

#### Dłoń
Model dłoni został zbudowany w oparciu o projekt [InMoov](http://inmoov.fr/) dlatego zachęcamy do kierowania się ich fantastyczną instrukcją składania [dłoni](http://inmoov.fr/hand-and-forarm/) oraz [palców](http://inmoov.fr/finger-starter/)

#### Przedramię

WIP

#### Schemat elektroniki w przedramieniu

<img src="https://i.imgur.com/ahhtjhWl.png" width="40%">

#### Opaska

Wszystkie elementy są połączone kablami według schematu i schowane w opasce z odpowiednimi wyprowadzeniami do przymocowania elektrod do sensorów EMG.

#### Schemat elektroniki w opasce

<img src="https://i.imgur.com/WfGwEmi.png" width="40%">
