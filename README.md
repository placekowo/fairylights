# fairylights
Code to control 2-wire alternating polarity fairy light and Christmas lights using Arduino.

A few days ago, I bought these really nice fairy lights on Amazon. Sadly, the controller died shortly after. Most people would probably just return it, however I immediatly started taking it apart. The original controller seemed to be nothing but a super obscure MCU, a crystal, and a handful of passive components. This gave me the idea to try to recreate its functionality using an Arduino, and regain the functionality of my fairy lights.

Right now, the code is very much a work in progress - the use of delay functions messes up the button presses (I'm still learning ;-;) and the code overall is a bit of a mess. It's a start, however, and I couldn't find anyone else who was doing this.

The LED string consists of multiple LED's in parallel, with the polarity of the LED's being alternated. This allows controlling two sets of LED's, with only one pair of cables, saving GPIO pins, and cost for the manufacture. This is used in many different styles of Christmas lights, as well as other decorations. This is called charlieplexing, and these lights use a simple version of it.

See the code in action here: https://www.youtube.com/watch?v=6Bf3h2NrNbw
