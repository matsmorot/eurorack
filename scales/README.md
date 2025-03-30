# scales
Scales is a quantizer first made by L.Geerinckx as a perfboard version. I wanted to see if I could learn a bit about schematics and PCB making, so I chose this module to be my first project, since I also needed a quantizer in my rack.

I decided to make some changes to the layout of the front panel, which you can see here.

<img src="./images/scales_kicad_3d.png" height="600px" /><br />

Mistakes were made in the first revision:
<ul>
  <li><b>WARNING!</b> The power connector is the wrong way around! The solution is however quite easy: just turn it around.</li>
  <li><b>D14</b> and <b>D17</b> were placed the wrong way. Just flip them.</li>
  <li>All the jack tracks but <b>CLOCK IN</b> were connected to the wrong legs (not GND). This can be solved by just bridging them.</li>
  <li>I forgot to remove a couple of tracks that are shorting nets. Will have to see if there is some way around this. Otherwise the   main PCB's are useless...</li>
  <li>The intention was to use flat head LEDs, but the holes are about 0.1 mm too small. "Normal" 3 mm tapered LEDs will fit.</li>
  <li>Unfortunately the holes for the tact button switches are also too small and will have to be drilled slightly. About as much as the plating.</li>
</ul>

Mistakes in revision 2:
<ul>
  <li>Power connector not fixed!</li>
</ul>

Original repo: https://github.com/PierreIsCoding/sdiy/tree/main/Quantizer
