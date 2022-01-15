EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 7350 7500 0    50   ~ 0
BM64_BREAKOUT_BOARD
Text Notes 10550 7650 0    50   ~ 0
1.0
Text Notes 7050 6750 0    100  ~ 0
By Niro
$Comp
L BM64:BM64 U1
U 1 1 61F2EA08
P 4850 1750
F 0 "U1" H 4850 1765 50  0000 C CNN
F 1 "BM64" H 4850 1674 50  0000 C CNN
F 2 "BM64:BM64" H 4850 1750 50  0001 C CNN
F 3 "" H 4850 1750 50  0001 C CNN
	1    4850 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x22_Male J1
U 1 1 61F2F9DE
P 3150 3350
F 0 "J1" H 3258 4531 50  0000 C CNN
F 1 "Conn_01x22_Male" H 3258 4440 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x22_P2.54mm_Vertical" H 3150 3350 50  0001 C CNN
F 3 "~" H 3150 3350 50  0001 C CNN
	1    3150 3350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x22_Male J2
U 1 1 61F3A1B6
P 6850 3450
F 0 "J2" H 6822 3332 50  0000 R CNN
F 1 "Conn_01x22_Male" H 6822 3423 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x22_P2.54mm_Vertical" H 6850 3450 50  0001 C CNN
F 3 "~" H 6850 3450 50  0001 C CNN
	1    6850 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3350 2350 4250 2350
Wire Wire Line
	4250 2450 3350 2450
Wire Wire Line
	3350 2550 4250 2550
Wire Wire Line
	4250 2650 3350 2650
Wire Wire Line
	3350 2750 4250 2750
Wire Wire Line
	3350 2850 4250 2850
Wire Wire Line
	3350 2950 4250 2950
Wire Wire Line
	4250 3050 3350 3050
Wire Wire Line
	3350 3150 4250 3150
Wire Wire Line
	4250 3250 3350 3250
Wire Wire Line
	3350 3350 4250 3350
Wire Wire Line
	4250 3450 3350 3450
Wire Wire Line
	3350 3550 4250 3550
Wire Wire Line
	4250 3650 3400 3650
Wire Wire Line
	3350 3750 4250 3750
Wire Wire Line
	4250 3850 3350 3850
Wire Wire Line
	3350 3950 4250 3950
Wire Wire Line
	3350 4050 4300 4050
Wire Wire Line
	4300 4050 4300 4450
Wire Wire Line
	4300 4450 4450 4450
Wire Wire Line
	4450 4450 4450 4400
Wire Wire Line
	3350 4150 4250 4150
Wire Wire Line
	4250 4150 4250 4500
Wire Wire Line
	4250 4500 4550 4500
Wire Wire Line
	4550 4500 4550 4400
Wire Wire Line
	3350 4250 4200 4250
Wire Wire Line
	4200 4250 4200 4550
Wire Wire Line
	4200 4550 4650 4550
Wire Wire Line
	4650 4550 4650 4400
Wire Wire Line
	3350 4350 4150 4350
Wire Wire Line
	4150 4350 4150 4600
Wire Wire Line
	4150 4600 4750 4600
Wire Wire Line
	4750 4600 4750 4400
Wire Wire Line
	3350 4450 4100 4450
Wire Wire Line
	4100 4450 4100 4650
Wire Wire Line
	4100 4650 4850 4650
Wire Wire Line
	4850 4650 4850 4400
Wire Wire Line
	5450 2350 6550 2350
Wire Wire Line
	6650 2450 5450 2450
Wire Wire Line
	5450 2550 6650 2550
Wire Wire Line
	6650 2650 5450 2650
Wire Wire Line
	5450 2750 6650 2750
Wire Wire Line
	6650 2850 5450 2850
Wire Wire Line
	5450 2950 6650 2950
Wire Wire Line
	6650 3050 5450 3050
Wire Wire Line
	5450 3150 6650 3150
Wire Wire Line
	5450 3250 6650 3250
Wire Wire Line
	6650 3350 5450 3350
Wire Wire Line
	5450 3450 6650 3450
Wire Wire Line
	6650 3550 5450 3550
Wire Wire Line
	5450 3650 6650 3650
Wire Wire Line
	6650 3750 5450 3750
Wire Wire Line
	5450 3850 6650 3850
Wire Wire Line
	5450 3950 6650 3950
Wire Wire Line
	6650 4050 5400 4050
Wire Wire Line
	5400 4050 5400 4450
Wire Wire Line
	5400 4450 5250 4450
Wire Wire Line
	5250 4450 5250 4400
Wire Wire Line
	5150 4400 5150 4500
Wire Wire Line
	5150 4500 5450 4500
Wire Wire Line
	5450 4500 5450 4150
Wire Wire Line
	5450 4150 6600 4150
Wire Wire Line
	6650 4250 5500 4250
Wire Wire Line
	5500 4250 5500 4550
Wire Wire Line
	5500 4550 5050 4550
Wire Wire Line
	5050 4550 5050 4400
Wire Wire Line
	4950 4600 5550 4600
Wire Wire Line
	5550 4600 5550 4350
Wire Wire Line
	5550 4350 6600 4350
Wire Wire Line
	4850 4650 5600 4650
Wire Wire Line
	5600 4650 5600 4450
Wire Wire Line
	5600 4450 6650 4450
Connection ~ 4850 4650
Wire Wire Line
	4950 4400 4950 4600
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 61F57CFB
P 2850 4550
F 0 "#FLG0101" H 2850 4625 50  0001 C CNN
F 1 "PWR_FLAG" H 2850 4723 50  0000 C CNN
F 2 "" H 2850 4550 50  0001 C CNN
F 3 "~" H 2850 4550 50  0001 C CNN
	1    2850 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4650 2850 4650
Wire Wire Line
	2850 4650 2850 4550
Connection ~ 4100 4650
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 61F5B0BA
P 2850 3550
F 0 "#FLG0102" H 2850 3625 50  0001 C CNN
F 1 "PWR_FLAG" H 2850 3723 50  0000 C CNN
F 2 "" H 2850 3550 50  0001 C CNN
F 3 "~" H 2850 3550 50  0001 C CNN
	1    2850 3550
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 61F5E880
P 6550 2200
F 0 "#FLG0104" H 6550 2275 50  0001 C CNN
F 1 "PWR_FLAG" H 6550 2373 50  0000 C CNN
F 2 "" H 6550 2200 50  0001 C CNN
F 3 "~" H 6550 2200 50  0001 C CNN
	1    6550 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2200 6550 2350
Connection ~ 6550 2350
Wire Wire Line
	6550 2350 6650 2350
Wire Wire Line
	6600 4150 6600 4100
Wire Wire Line
	6600 4100 7200 4100
Wire Wire Line
	7200 4100 7200 4050
Connection ~ 6600 4150
Wire Wire Line
	6600 4150 6650 4150
$Comp
L power:PWR_FLAG #FLG0105
U 1 1 61F6551F
P 7500 4250
F 0 "#FLG0105" H 7500 4325 50  0001 C CNN
F 1 "PWR_FLAG" H 7500 4423 50  0000 C CNN
F 2 "" H 7500 4250 50  0001 C CNN
F 3 "~" H 7500 4250 50  0001 C CNN
	1    7500 4250
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 61F5CF44
P 7200 4050
F 0 "#FLG0103" H 7200 4125 50  0001 C CNN
F 1 "PWR_FLAG" H 7200 4223 50  0000 C CNN
F 2 "" H 7200 4050 50  0001 C CNN
F 3 "~" H 7200 4050 50  0001 C CNN
	1    7200 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 4350 6600 4300
Wire Wire Line
	6600 4300 7500 4300
Wire Wire Line
	7500 4300 7500 4250
Connection ~ 6600 4350
Wire Wire Line
	6600 4350 6650 4350
Wire Wire Line
	2850 3550 2850 3600
Wire Wire Line
	2850 3600 3400 3600
Wire Wire Line
	3400 3600 3400 3650
Connection ~ 3400 3650
Wire Wire Line
	3400 3650 3350 3650
$EndSCHEMATC
