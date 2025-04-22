# scales
Scales is a quantizer first made by L.Geerinckx as a perfboard version. I wanted to see if I could learn a bit about schematics and PCB making, so I chose this module to be my first project, since I also needed a quantizer in my rack.

I decided to make some changes to the layout of the front panel, which you can see here.

<img src="./images/scales_kicad_3d.png" height="600px" /><br />

## Mistakes were made in the first revision:
<ul>
  <li><b>WARNING!</b> The power connector is the wrong way around! The solution is however quite easy: just turn it around.</li>
  <li><b>D14</b> and <b>D17</b> were placed the wrong way. Just flip them.</li>
  <li>All the jack tracks but <b>CLOCK IN</b> were connected to the wrong legs (not GND). This can be solved by just bridging them.</li>
  <li>I forgot to remove a couple of tracks that are shorting nets. Will have to see if there is some way around this. Otherwise the   main PCB's are useless...</li>
  <li>If you by some strange accident happen to have revision 1 (no rev number on the main PCB), throw it away!</li>
</ul>

## PCB rev 2:
<ul>
  <li>Power connector not fixed! Make sure to flip it!</li>
  <li>I have moved the buttons to different input pins on the Arduino Nano, so the original code won't work with this PCB.</li>
</ul>

## PCB rev 3:
<ul>
  <li>Pins A6 and A7 can not be used on the Arduino Nano without bridging them to other pins. I have connected them to D11 and D12 on mine. Another option is to use an <b>LGT8F328P</b> board, where you can use A6 and A7 as digital pins.</li>
  <li>I noticed that the mounting holes from rev 1 has disappeared from the layout. Will add them in rev 4.</li>
</ul>

## PCB rev 4:
<ul>
  <li>Added missing 2.5 mm mounting hole</li>
</ul>

## Panel rev 1:
<ul>
  <li>The intention was to use flat head LEDs, but the holes are about 0.1 mm too small. "Normal" 3 mm tapered LEDs will fit, but just barely. Just put them flush to the panel and it will work out OK.</li>
  <li>Unfortunately the holes for the tact button switches are also too small and will have to be drilled slightly. About as much as the plating. I'm using 13 mm's, but 14 would probably work as well.</li>
  <li>Unfortunately a mounting hole through the panel is needed. Without one, the PCB will move when you press the buttons. Very annoying. Will fix in rev 2 of the panel.</li>
</ul>

## Panel rev 2:
<ul>
  <li>0.1 mm wider holes for LEDs and buttons</li>
  <li>2.5 mm mounting hole added</li>
</ul>

Original repo: https://github.com/PierreIsCoding/sdiy/tree/main/Quantizer
