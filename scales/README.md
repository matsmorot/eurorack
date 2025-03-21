# scales
Scales is a quantizer first made by L.Geerinckx as a perfboard version. I wanted to see if I could learn a bit about schematics and PCB making, so I chose this module to be my first project, since I also needed a quantizer in my rack.

I decided to make some changes to the layout of the front panel, which you can see here.

<img src="./images/scales_kicad_3d.png" height="600px" /><br />

Mistakes were made in the first revision:
<ul>
<li><b>D14</b> and <b>D17</b> were placed the wrong way. Just flip them.</li>
<li>All the jack tracks but <b>CLOCK IN</b> were connected to the wrong legs (not GND). This can be solved by just bridging them.</li>
<li>The biggest mistake was that I forgot to remove a couple of tracks that are shorting nets. Will have to see if there is some way around this. Otherwise the main PCB's are useless...</li>
</ul>

Original repo: https://github.com/PierreIsCoding/sdiy/tree/main/Quantizer
