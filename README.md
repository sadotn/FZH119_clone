# FZH119_clone

# overview
FZH119 is a LED (Light Emitting Diode Display) drive control and application circuit, which integrates MCU digital interface, data latch, LED drive and other circuits inside. This product has excellent performance and reliable quality. Mainly used in LED display drive of electronic products. Adopt SOP28 encapsulation form.
Feature Description
- Using CMOS technology
- Display mode (8 segments×16 bits)
- Brightness adjustment circuit (duty cycle 8 levels adjustable)
-  Two-wire serial interface (SCLK, DIN)
- Oscillation mode: built-in RC oscillator
- Built -in power-on reset circuit
- Package form: SOP28 , TSSOP20
Interface Description
The data of the microprocessor communicates with FZH119 through the two-wire bus interface . When CLK is high level when inputting data, the signal on DIN must remain unchanged; only when the clock signal on CLK is low level, the signal on DIN can be Change. The input of data is always the low bit first, and the high bit is transmitted later. The start condition of data input is when CLK is high level, DIN changes from high level to low level; the end condition is when CLK is high level, DIN level changes from low level to high level .

# The instruction data transmission process is as follows:
![image](https://github.com/sadotn/FZH119_clone/assets/90098747/8f21595b-cf50-4531-ba58-b6df0611dd37)

# Write SRAM data address automatically add 1 mode:
![image](https://github.com/sadotn/FZH119_clone/assets/90098747/3c734a56-cfc6-4ee1-9877-001443d8ad4a)


Command1: set data
Command2: set address
data1~N: transmission display data (up to 16 bytes, can not be written more)
Command3: control display

Write SRAM data fixed address mode:
![image](https://github.com/sadotn/FZH119_clone/assets/90098747/9a53b580-6c58-42f3-a83b-24172680796a)


Command1: set data
Command2: set address
data1: transfer display data
CommandN: set address
dataN: transmission display data (up to 16 bytes, can not be written more)
Command3: control display

# Kind tips:
It is necessary to pull up the 10K resistor on the data line pin of the FZH119 chip. If it is not connected, it may not be displayed. At the same time, if the IIC line is relatively long, two 104 capacitors should be connected. Personally, I suggest adding it at the beginning. The voltage of the 51 microcontroller I use is 3.3V and it cannot work normally without the pull-up. Other platforms have not been tested.
The program is compatible with a variety of FZHxxx series chips. This is a custom chip package, and other IC programs are equally applicable. If the usage is different, just modify this function: fzh_WriteSram( 0x40,START_SRAM,temp_buff,3,fzh_light_grade);
The reference circuit is provided as follows:

