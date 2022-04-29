EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Regulator_Linear:LM317_TO-252 U4
U 1 1 61F853DA
P 5100 3250
F 0 "U4" H 5100 3492 50  0000 C CNN
F 1 "LM317_TO-252" H 5100 3401 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 5100 3500 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/snvs774n/snvs774n.pdf" H 5100 3250 50  0001 C CNN
	1    5100 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+VDC #PWR?
U 1 1 61F85A54
P 2400 2950
F 0 "#PWR?" H 2400 2850 50  0001 C CNN
F 1 "+VDC" H 2400 3225 50  0000 C CNN
F 2 "" H 2400 2950 50  0001 C CNN
F 3 "" H 2400 2950 50  0001 C CNN
	1    2400 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3250 4800 3250
$Comp
L power:GND #PWR?
U 1 1 61F8655E
P 5100 4200
F 0 "#PWR?" H 5100 3950 50  0001 C CNN
F 1 "GND" H 5105 4027 50  0000 C CNN
F 2 "" H 5100 4200 50  0001 C CNN
F 3 "" H 5100 4200 50  0001 C CNN
	1    5100 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61F86E5F
P 5100 3850
F 0 "R?" H 5170 3896 50  0000 L CNN
F 1 "R" H 5170 3805 50  0000 L CNN
F 2 "" V 5030 3850 50  0001 C CNN
F 3 "~" H 5100 3850 50  0001 C CNN
	1    5100 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61F8726A
P 5450 3650
F 0 "R?" V 5243 3650 50  0000 C CNN
F 1 "R" V 5334 3650 50  0000 C CNN
F 2 "" V 5380 3650 50  0001 C CNN
F 3 "~" H 5450 3650 50  0001 C CNN
	1    5450 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 3550 5100 3650
Wire Wire Line
	5300 3650 5100 3650
Connection ~ 5100 3650
Wire Wire Line
	5100 3650 5100 3700
Wire Wire Line
	5100 4000 5100 4100
$Comp
L Device:C C?
U 1 1 61F881D1
P 4200 3700
F 0 "C?" H 4315 3746 50  0000 L CNN
F 1 "100nF" H 4315 3655 50  0000 L CNN
F 2 "" H 4238 3550 50  0001 C CNN
F 3 "~" H 4200 3700 50  0001 C CNN
	1    4200 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 61F88CEF
P 6150 3800
F 0 "C?" H 6265 3846 50  0000 L CNN
F 1 "10uF" H 6265 3755 50  0000 L CNN
F 2 "" H 6188 3650 50  0001 C CNN
F 3 "~" H 6150 3800 50  0001 C CNN
	1    6150 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3250 5800 3250
Wire Wire Line
	5800 3250 5800 3650
Wire Wire Line
	5800 3650 5600 3650
Wire Wire Line
	4200 3850 4200 4100
Wire Wire Line
	4200 4100 5100 4100
Connection ~ 5100 4100
Wire Wire Line
	5100 4100 5100 4200
Wire Wire Line
	2400 2950 2400 3250
Wire Wire Line
	4200 3250 4200 3550
Wire Wire Line
	5800 3250 6150 3250
Wire Wire Line
	6150 3250 6150 3650
Connection ~ 5800 3250
Wire Wire Line
	5100 4100 6150 4100
Wire Wire Line
	6150 4100 6150 3950
Text GLabel 6700 3250 2    50   Input Italic 0
3.3v_OUT
Wire Wire Line
	6700 3250 6150 3250
Connection ~ 6150 3250
Text GLabel 6700 2700 2    50   Input Italic 0
FILTERED_POWER_OUT
$Comp
L Device:D_Zener D3
U 1 1 61F8F47A
P 3400 3250
F 0 "D3" H 3400 3467 50  0000 C CNN
F 1 "D_Zener" H 3400 3376 50  0000 C CNN
F 2 "" H 3400 3250 50  0001 C CNN
F 3 "~" H 3400 3250 50  0001 C CNN
	1    3400 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3250 3800 3250
Connection ~ 4200 3250
Wire Notes Line
	3950 2100 2750 2100
Text Notes 2800 2350 0    50   Italic 0
Approfondir et vérifier cet \nétage de filtrage\nSource : Digikey
$Comp
L Device:C C?
U 1 1 61F912B4
P 3100 2750
F 0 "C?" V 2848 2750 50  0000 C CNN
F 1 "C" V 2939 2750 50  0000 C CNN
F 2 "" H 3138 2600 50  0001 C CNN
F 3 "~" H 3100 2750 50  0001 C CNN
	1    3100 2750
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 61F91825
P 3600 2750
F 0 "R?" V 3393 2750 50  0000 C CNN
F 1 "R" V 3484 2750 50  0000 C CNN
F 2 "" V 3530 2750 50  0001 C CNN
F 3 "~" H 3600 2750 50  0001 C CNN
	1    3600 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	3250 2750 3450 2750
Wire Notes Line
	2750 2100 2750 3600
Wire Notes Line
	3950 2100 3950 3600
Wire Notes Line
	2750 3600 3950 3600
Wire Wire Line
	2950 2750 2900 2750
Wire Wire Line
	2900 2750 2900 3250
Wire Wire Line
	2400 3250 2900 3250
Connection ~ 2900 3250
Wire Wire Line
	2900 3250 3250 3250
Wire Wire Line
	3750 2750 3800 2750
Wire Wire Line
	3800 2750 3800 3250
Connection ~ 3800 3250
Wire Wire Line
	3800 3250 4200 3250
Wire Wire Line
	6700 2700 4200 2700
Wire Wire Line
	4200 2700 4200 3250
Wire Notes Line
	6800 4900 6800 5850
Wire Notes Line
	6800 5850 4750 5850
Wire Notes Line
	4750 5850 4750 4900
Wire Notes Line
	4750 4900 6800 4900
Text Notes 4850 5150 0    50   Italic 0
Réfléchir si une nécéssité d'avoir une autre \ntension d'alimentation pour les filtres
Text Notes 7050 6700 0    50   Italic 0
LM317_Vout = 1.25*(1 + (R2/R1)) + IADJ[R2]
Text Notes 4850 5700 0    50   Italic 0
LM317 3.3v -> Voir la doc pour calculer \nle rapport R2/R1 pour avoir 3.3V en sortie
$EndSCHEMATC
