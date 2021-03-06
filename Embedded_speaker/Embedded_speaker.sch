EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 7750 2950 1000 1000
U 61EB7BA3
F0 "Filtre_PB_PH" 50
F1 "file61EB7BA2.sch" 50
$EndSheet
$Sheet
S 9450 1950 1000 1000
U 61EB7BF8
F0 "Ampli_Classe_D" 50
F1 "file61EB7BF7.sch" 50
$EndSheet
$Sheet
S 9450 3950 1000 1000
U 61EB7C56
F0 "Ampli_Classe_AB" 50
F1 "file61EB7C55.sch" 50
$EndSheet
$Sheet
S 6050 5200 2100 700 
U 61EB7CA4
F0 "Alimentation" 50
F1 "file61EB7CA3.sch" 50
$EndSheet
$Comp
L BM64:BM64 U2
U 1 1 61EB7E60
P 4400 1000
F 0 "U2" H 4400 1015 50  0000 C CNN
F 1 "BM64" H 4400 924 50  0000 C CNN
F 2 "" H 4400 1000 50  0001 C CNN
F 3 "" H 4400 1000 50  0001 C CNN
	1    4400 1000
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATtiny:ATtiny2313A-PU U1
U 1 1 61EB9721
P 2000 2500
F 0 "U1" H 2350 3800 50  0000 C CNN
F 1 "ATtiny2313A-PU" H 2350 3700 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm" H 2000 2500 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc8246.pdf" H 2000 2500 50  0001 C CNN
	1    2000 2500
	1    0    0    -1  
$EndComp
NoConn ~ 1400 2100
NoConn ~ 1400 1900
$Comp
L Device:R R1
U 1 1 61EBA2CA
P 1000 1700
F 0 "R1" V 793 1700 50  0000 C CNN
F 1 "10K" V 884 1700 50  0000 C CNN
F 2 "" V 930 1700 50  0001 C CNN
F 3 "~" H 1000 1700 50  0001 C CNN
	1    1000 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	1150 1700 1400 1700
Wire Wire Line
	850  1700 700  1700
Wire Wire Line
	700  1700 700  1000
Wire Wire Line
	700  1000 2000 1000
Wire Wire Line
	2000 1000 2000 1400
$Comp
L Device:C C1
U 1 1 61EBC671
P 700 2400
F 0 "C1" H 815 2446 50  0000 L CNN
F 1 "10uF" H 815 2355 50  0000 L CNN
F 2 "" H 738 2250 50  0001 C CNN
F 3 "~" H 700 2400 50  0001 C CNN
	1    700  2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  1700 700  2250
Connection ~ 700  1700
Wire Wire Line
	700  2550 700  3850
Wire Wire Line
	700  3850 1050 3850
Wire Wire Line
	2000 3850 2000 3600
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 61EBD5BF
P 700 850
F 0 "#FLG0101" H 700 925 50  0001 C CNN
F 1 "PWR_FLAG" H 700 1023 50  0000 C CNN
F 2 "" H 700 850 50  0001 C CNN
F 3 "~" H 700 850 50  0001 C CNN
	1    700  850 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 61EBDF72
P 1050 3700
F 0 "#FLG0102" H 1050 3775 50  0001 C CNN
F 1 "PWR_FLAG" H 1050 3873 50  0000 C CNN
F 2 "" H 1050 3700 50  0001 C CNN
F 3 "~" H 1050 3700 50  0001 C CNN
	1    1050 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 3700 1050 3850
Connection ~ 1050 3850
Wire Wire Line
	1050 3850 2000 3850
Wire Wire Line
	700  850  700  1000
Connection ~ 700  1000
$Comp
L power:GND #PWR0101
U 1 1 61EBE762
P 2000 4050
F 0 "#PWR0101" H 2000 3800 50  0001 C CNN
F 1 "GND" H 2005 3877 50  0000 C CNN
F 2 "" H 2000 4050 50  0001 C CNN
F 3 "" H 2000 4050 50  0001 C CNN
	1    2000 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3850 2000 4050
Connection ~ 2000 3850
$Comp
L power:+3.3V #PWR0102
U 1 1 61EBEDF5
P 2000 850
F 0 "#PWR0102" H 2000 700 50  0001 C CNN
F 1 "+3.3V" H 2015 1023 50  0000 C CNN
F 2 "" H 2000 850 50  0001 C CNN
F 3 "" H 2000 850 50  0001 C CNN
	1    2000 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 850  2000 1000
Connection ~ 2000 1000
$Comp
L Analog_Switch:CD4052B U3
U 1 1 61EC0631
P 3600 6150
F 0 "U3" H 3400 6950 50  0000 C CNN
F 1 "CD4052B" H 3400 6850 50  0000 C CNN
F 2 "" H 3750 5400 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4052b.pdf" H 3580 6350 50  0001 C CNN
	1    3600 6150
	1    0    0    -1  
$EndComp
Entry Wire Line
	4000 4000 4100 3900
Entry Wire Line
	4100 4000 4200 3900
Entry Wire Line
	3000 2700 2900 2600
Entry Wire Line
	3000 2800 2900 2700
Wire Wire Line
	2600 2600 2900 2600
Wire Wire Line
	2600 2700 2900 2700
Wire Wire Line
	4100 3650 4100 3900
Wire Wire Line
	4200 3650 4200 3900
Text Label 2700 2600 0    50   ~ 0
RX0
Text Label 2700 2700 0    50   ~ 0
TX0
Text Label 4100 3850 1    50   ~ 0
TX0
Text Label 4200 3850 1    50   ~ 0
RX0
NoConn ~ 3800 1600
NoConn ~ 3800 1700
NoConn ~ 3800 1800
NoConn ~ 3800 1900
NoConn ~ 3800 2300
NoConn ~ 3800 2400
NoConn ~ 3800 2500
$Comp
L Connector:AudioJack3_SwitchTR J6
U 1 1 61ED716A
P 1500 6600
F 0 "J6" H 1482 6925 50  0000 C CNN
F 1 "AudioJack3_SwitchTR" H 1482 6834 50  0000 C CNN
F 2 "" H 1500 6600 50  0001 C CNN
F 3 "~" H 1500 6600 50  0001 C CNN
	1    1500 6600
	1    0    0    -1  
$EndComp
Text Notes 750  7250 0    50   ~ 0
Bien r??fl??chir au choix du jack !
Text Notes 7400 7250 0    50   ~ 0
Interface Num??rique Analogique/
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 61ED948F
P 2100 5400
F 0 "J1" V 2162 5444 50  0000 L CNN
F 1 "Conn_01x02_Male" V 2253 5444 50  0000 L CNN
F 2 "" H 2100 5400 50  0001 C CNN
F 3 "~" H 2100 5400 50  0001 C CNN
	1    2100 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	2100 5650 2850 5650
Wire Wire Line
	2000 5650 1600 5650
Wire Wire Line
	1600 5650 1600 5750
$Comp
L power:GND #PWR0103
U 1 1 61EDB2FF
P 1600 5750
F 0 "#PWR0103" H 1600 5500 50  0001 C CNN
F 1 "GND" H 1605 5577 50  0000 C CNN
F 2 "" H 1600 5750 50  0001 C CNN
F 3 "" H 1600 5750 50  0001 C CNN
	1    1600 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 61EDB9E2
P 2850 5350
F 0 "R6" H 2920 5396 50  0000 L CNN
F 1 "10K" H 2920 5305 50  0000 L CNN
F 2 "" V 2780 5350 50  0001 C CNN
F 3 "~" H 2850 5350 50  0001 C CNN
	1    2850 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 5500 2850 5650
$Comp
L power:+3.3V #PWR0104
U 1 1 61EDC2D6
P 2850 5050
F 0 "#PWR0104" H 2850 4900 50  0001 C CNN
F 1 "+3.3V" H 2865 5223 50  0000 C CNN
F 2 "" H 2850 5050 50  0001 C CNN
F 3 "" H 2850 5050 50  0001 C CNN
	1    2850 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 5050 2850 5100
Text Notes 1250 5300 0    50   ~ 0
Choix du Canal Audio (L/R)
Wire Wire Line
	2000 5600 2000 5650
Wire Wire Line
	2100 5600 2100 5650
$Comp
L Device:R R4
U 1 1 61EDE2E9
P 5300 3100
F 0 "R4" V 5093 3100 50  0000 C CNN
F 1 "R" V 5184 3100 50  0000 C CNN
F 2 "" V 5230 3100 50  0001 C CNN
F 3 "~" H 5300 3100 50  0001 C CNN
	1    5300 3100
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 61EDEAFC
P 5300 3250
F 0 "R5" V 5400 3250 50  0000 C CNN
F 1 "R" V 5500 3250 50  0000 C CNN
F 2 "" V 5230 3250 50  0001 C CNN
F 3 "~" H 5300 3250 50  0001 C CNN
	1    5300 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	5150 3100 5000 3100
Wire Wire Line
	5000 3200 5150 3200
$Comp
L Device:LED D2
U 1 1 61EE183A
P 5700 3100
F 0 "D2" H 5693 2845 50  0000 C CNN
F 1 "LED" H 5693 2936 50  0000 C CNN
F 2 "" H 5700 3100 50  0001 C CNN
F 3 "~" H 5700 3100 50  0001 C CNN
	1    5700 3100
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D3
U 1 1 61EE2275
P 5700 3250
F 0 "D3" H 5700 3400 50  0000 C CNN
F 1 "LED" H 5700 3500 50  0000 C CNN
F 2 "" H 5700 3250 50  0001 C CNN
F 3 "~" H 5700 3250 50  0001 C CNN
	1    5700 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	5150 3200 5150 3250
Wire Wire Line
	5450 3250 5550 3250
Wire Wire Line
	5550 3100 5450 3100
Wire Wire Line
	5850 3100 6050 3100
Wire Wire Line
	6050 3100 6050 3250
Wire Wire Line
	5850 3250 6050 3250
Connection ~ 6050 3250
Wire Wire Line
	6050 3250 6050 3400
Wire Wire Line
	5000 1600 6050 1600
Wire Wire Line
	6050 1600 6050 3100
Connection ~ 6050 3100
$Comp
L power:GND #PWR0105
U 1 1 61EE6D59
P 6050 3400
F 0 "#PWR0105" H 6050 3150 50  0001 C CNN
F 1 "GND" H 6055 3227 50  0000 C CNN
F 2 "" H 6050 3400 50  0001 C CNN
F 3 "" H 6050 3400 50  0001 C CNN
	1    6050 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 61EE7501
P 3450 3400
F 0 "#PWR0106" H 3450 3150 50  0001 C CNN
F 1 "GND" H 3455 3227 50  0000 C CNN
F 2 "" H 3450 3400 50  0001 C CNN
F 3 "" H 3450 3400 50  0001 C CNN
	1    3450 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2900 3450 3400
$Comp
L Device:R R2
U 1 1 61EEA560
P 2850 1700
F 0 "R2" V 2643 1700 50  0000 C CNN
F 1 "R" V 2734 1700 50  0000 C CNN
F 2 "" V 2780 1700 50  0001 C CNN
F 3 "~" H 2850 1700 50  0001 C CNN
	1    2850 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 2900 3800 2900
Wire Wire Line
	3000 1700 3100 1700
Wire Wire Line
	2700 1700 2600 1700
NoConn ~ 3800 2100
NoConn ~ 3800 2600
NoConn ~ 3800 2700
NoConn ~ 4300 3650
NoConn ~ 4500 3650
NoConn ~ 4600 3650
$Comp
L Connector:TestPoint TP3
U 1 1 61EF22E2
P 5150 4700
F 0 "TP3" H 5208 4818 50  0000 L CNN
F 1 "ADC_TEMPERATURE_INPUT" H 5208 4727 50  0000 L CNN
F 2 "" H 5350 4700 50  0001 C CNN
F 3 "~" H 5350 4700 50  0001 C CNN
	1    5150 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4850 5150 4850
Wire Wire Line
	5150 4850 5150 4700
$Comp
L Connector:TestPoint TP1
U 1 1 61EF3806
P 5250 2500
F 0 "TP1" H 5308 2618 50  0000 L CNN
F 1 "USB+" H 5308 2527 50  0000 L CNN
F 2 "" H 5450 2500 50  0001 C CNN
F 3 "~" H 5450 2500 50  0001 C CNN
	1    5250 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP2
U 1 1 61EF3D45
P 5600 2600
F 0 "TP2" H 5658 2718 50  0000 L CNN
F 1 "USB-" H 5658 2627 50  0000 L CNN
F 2 "" H 5800 2600 50  0001 C CNN
F 3 "~" H 5800 2600 50  0001 C CNN
	1    5600 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2500 5250 2500
Wire Wire Line
	5000 2600 5600 2600
Text Notes 5050 1300 0    50   ~ 0
Voir l'int??r??t de la broche EAN\net son lien avec P2_0
NoConn ~ 5000 2400
NoConn ~ 5000 2300
NoConn ~ 5000 1900
NoConn ~ 5000 1700
NoConn ~ 5000 2900
NoConn ~ 5000 2800
Wire Wire Line
	5000 3000 5150 3000
Wire Wire Line
	5150 3000 5150 2750
Wire Wire Line
	5150 2750 6400 2750
Text Label 6400 2750 0    50   ~ 0
TX_INDICATOR
Text Notes 6250 2600 0    50   ~ 0
Utile pour v??rifier si le\nBM64 envoi un message
Wire Notes Line
	6200 2350 6200 2850
Wire Notes Line
	6200 2850 7300 2850
Wire Notes Line
	7300 2850 7300 2350
Wire Notes Line
	7300 2350 6200 2350
Wire Notes Line
	650  6300 2100 6300
Text Notes 700  7550 0    50   ~ 0
Voir si le multiplexeur peut\n??tre pilot?? sans le uC (Broche 9)
Wire Notes Line
	650  7650 2100 7650
Wire Notes Line
	650  6300 650  7650
Wire Notes Line
	2100 6300 2100 7650
Wire Notes Line
	8750 3150 9000 3150
Wire Notes Line
	9000 3150 9000 2400
Wire Notes Line
	9000 2400 9450 2400
Wire Notes Line
	8750 3750 9000 3750
Wire Notes Line
	9000 3750 9000 4500
Wire Notes Line
	9000 4500 9450 4500
Text Notes 9300 1700 0    59   Italic 0
Amplificateur du Sub-Woofer
Text Notes 9400 3700 0    59   Italic 0
Amplificateur du Tweeter
$Comp
L power:GND #PWR?
U 1 1 61F0D18C
P 3600 7100
F 0 "#PWR?" H 3600 6850 50  0001 C CNN
F 1 "GND" H 3605 6927 50  0000 C CNN
F 2 "" H 3600 7100 50  0001 C CNN
F 3 "" H 3600 7100 50  0001 C CNN
	1    3600 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 6850 3600 7000
Wire Wire Line
	3500 6850 3500 7000
Wire Wire Line
	3500 7000 3600 7000
Connection ~ 3600 7000
Wire Wire Line
	3600 7000 3600 7100
Wire Wire Line
	3500 7000 2850 7000
Wire Wire Line
	2850 6550 3100 6550
Connection ~ 3500 7000
NoConn ~ 3100 6450
NoConn ~ 4100 6350
NoConn ~ 4100 6450
NoConn ~ 4100 6550
NoConn ~ 4100 6650
Wire Wire Line
	3700 5100 3700 5450
Connection ~ 2850 5100
Wire Wire Line
	2850 5100 2850 5200
$Comp
L Device:C C2
U 1 1 61F1877A
P 2850 6250
F 0 "C2" H 2965 6296 50  0000 L CNN
F 1 "100nF" H 2965 6205 50  0000 L CNN
F 2 "" H 2888 6100 50  0001 C CNN
F 3 "~" H 2850 6250 50  0001 C CNN
	1    2850 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 6100 2850 5650
Connection ~ 2850 5650
Wire Wire Line
	2850 6400 2850 6550
Connection ~ 2850 6550
Wire Wire Line
	2850 6550 2850 7000
Wire Wire Line
	2850 5650 3100 5650
Wire Wire Line
	2850 5100 3700 5100
Wire Wire Line
	3100 5950 2350 5950
Wire Wire Line
	2350 5950 2350 7450
Wire Wire Line
	2350 7450 4550 7450
Text GLabel 4550 7450 2    50   Input Italic 0
AUDIO_OUT_MUX1
Entry Wire Line
	3400 2100 3500 2200
Entry Wire Line
	3400 1900 3500 2000
$Comp
L Device:LED D1
U 1 1 61EE8F98
P 3100 1850
F 0 "D1" V 2950 2000 50  0000 C CNN
F 1 "LED" V 3050 2000 50  0000 C CNN
F 2 "" H 3100 1850 50  0001 C CNN
F 3 "~" H 3100 1850 50  0001 C CNN
	1    3100 1850
	0    -1   -1   0   
$EndComp
Connection ~ 3450 2900
Wire Wire Line
	3500 2000 3800 2000
Wire Wire Line
	3500 2200 3800 2200
Wire Bus Line
	3400 900  3600 900 
Text Label 3550 2000 0    50   Italic 0
BRCH
Text Label 3550 2200 0    50   Italic 0
BLCH
Text Label 3400 900  0    50   Italic 0
BM64_AUDIO_CHANNELS
Entry Wire Line
	4600 6050 4700 5950
Entry Wire Line
	4600 6150 4700 6050
Wire Bus Line
	4700 5750 5150 5750
Wire Wire Line
	4600 6050 4100 6050
Wire Wire Line
	4100 6150 4600 6150
Text Label 4850 5750 0    50   Italic 0
BM64_AUDIO_CHANNELS
Text Notes 7000 6800 0    50   Italic 0
FL1 -> Filtre Passe Bas -> Ampli Classe D\nFL2 -> Filtre Passe Haut -> Ampli Classe AB\nPort USB du BM64 Utile pour MAJ du Firmware
Text Notes 8400 3200 0    100  Italic 0
FL1
Text Notes 8400 3800 0    100  Italic 0
FL2
Text Notes 6950 3750 0    100  Italic 0
AUDIO_IN
Wire Notes Line
	7650 3600 7650 3800
Wire Notes Line
	7650 3800 6900 3800
Wire Notes Line
	6900 3800 6900 3600
Wire Notes Line
	6900 3600 7650 3600
Wire Notes Line
	7250 3600 7250 3450
Wire Notes Line
	7250 3450 7750 3450
Wire Notes Line
	8400 3050 8700 3050
Wire Notes Line
	8700 3050 8700 3250
Wire Notes Line
	8700 3250 8400 3250
Wire Notes Line
	8400 3250 8400 3050
Wire Notes Line
	8400 3650 8700 3650
Wire Notes Line
	8700 3650 8700 3850
Wire Notes Line
	8700 3850 8400 3850
Wire Notes Line
	8400 3850 8400 3650
NoConn ~ 3800 3000
NoConn ~ 3800 3100
NoConn ~ 3800 3200
Wire Wire Line
	3100 2900 3450 2900
Wire Wire Line
	3100 2000 3100 2900
Wire Wire Line
	4400 3650 4400 5100
Wire Wire Line
	4400 5100 3700 5100
Connection ~ 3700 5100
Wire Bus Line
	4150 4000 4150 4400
Entry Wire Line
	4150 4400 4250 4500
Wire Wire Line
	4800 3650 4800 4500
Wire Wire Line
	4800 4500 4250 4500
Wire Wire Line
	4700 3650 4700 4850
Entry Wire Line
	2900 2800 3000 2900
Wire Wire Line
	2600 2800 2900 2800
Text Label 4800 3850 1    50   Italic 0
MFB
Text Label 2850 2800 2    50   Italic 0
MFB
NoConn ~ 4000 3650
Wire Wire Line
	3700 2800 3800 2800
Wire Wire Line
	3700 2800 3700 3900
Entry Wire Line
	3700 3900 3600 4000
Text Label 3700 3850 1    50   Italic 0
RST_B
Entry Wire Line
	2900 2900 3000 3000
Wire Wire Line
	2600 2900 2900 2900
Text Label 2900 2900 2    50   Italic 0
RST_B
NoConn ~ 2600 3200
Wire Notes Line
	4950 1950 4950 2250
Text Notes 5050 2150 0    50   Italic 0
Voir l'utilit?? de REV Key, \nFWD Key, Multi-SPK
Wire Notes Line
	6000 1950 6000 2250
Wire Notes Line
	4950 2250 6000 2250
Wire Notes Line
	4950 1950 6000 1950
Text GLabel 5850 7100 2    50   Input Italic 0
3.3v_OUT
Wire Wire Line
	5850 7100 5500 7100
Wire Wire Line
	5500 7100 5500 6950
$Comp
L power:+3.3V #PWR?
U 1 1 61F9EA50
P 5500 6950
F 0 "#PWR?" H 5500 6800 50  0001 C CNN
F 1 "+3.3V" H 5515 7123 50  0000 C CNN
F 2 "" H 5500 6950 50  0001 C CNN
F 3 "" H 5500 6950 50  0001 C CNN
	1    5500 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 5750 2100 5750
Text Label 2100 5750 0    50   Italic 0
J_TRIG
Wire Bus Line
	4700 5750 4700 6050
Wire Bus Line
	3400 900  3400 2100
Wire Bus Line
	3000 2700 3000 4000
Wire Bus Line
	3000 4000 4150 4000
$EndSCHEMATC
