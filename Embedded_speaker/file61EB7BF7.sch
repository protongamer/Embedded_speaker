EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 2100 1600 2    50   Input Italic 0
FILTERED_POWER_OUT
Wire Wire Line
	2100 1600 1750 1600
Wire Wire Line
	1750 1600 1750 1500
$Comp
L power:VDD #PWR?
U 1 1 61FA67ED
P 1750 1500
AR Path="/61FA67ED" Ref="#PWR?"  Part="1" 
AR Path="/61EB7C56/61FA67ED" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1750 1350 50  0001 C CNN
F 1 "VDD" H 1765 1673 50  0000 C CNN
F 2 "" H 1750 1500 50  0001 C CNN
F 3 "" H 1750 1500 50  0001 C CNN
	1    1750 1500
	1    0    0    -1  
$EndComp
Wire Notes Line
	3400 3300 1200 3300
Wire Notes Line
	1200 1050 1200 3300
Wire Notes Line
	3400 1050 3400 3300
Wire Notes Line
	1200 1050 3400 1050
Text Notes 1300 1200 0    50   Italic 0
Ce que vous risquez d'avoir besoin
$EndSCHEMATC
