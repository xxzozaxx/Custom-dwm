I tried my best to follow the suckless coding style.

None of the features was patched in, i hand coded every extra feature trying my best to fix all bugs found in the patches.

![Screenshot](http://i67.tinypic.com/169gf7t.jpg)
***
### Installation
```
make clean install
```
***
### Extra Features
* Master All Sides - The ability to have the master view on the left, right, top and bottom.
* Smart Direction - As we can now have the master on different sides smart direction fixes the problem of direction keys not being intuitive.
* Per Tag - Allows each tag to have a separate layout, master count, master size and visible bar
* Gaps - Gap around windows that can be adjusted on the fly.
* Fake Fullscreen - Only allow windows to fullscreen into space given to them.
* Hide Vacant Tags - Hide tags that are not in use.
* Move Stack - Move windows around in the stack.
* No Border - Remove the border when there is only one window visible.
* Resize Corners - The mouse is warped to the nearest corner when resizing windows.
* Bar Style - Removed blue title background, removed layout symbol, added extra color for unselected tags

***
### Keys
As i have drastically changed the keyboard layout i have included some of the changes below.

##### Main keys:
* mod + down|left|right|up = change window focus / resize master
* mod + shift + down|left|right|up = move window / change master count

##### Layout keys:
* mod + ctrl + down|left|right|up = move master
* mod + ctrl + space = set floating layout
* mod + ctrl + return = set monocle layout

##### Other keys
* mod + space = toggle floating
* mod + return = set as master
* mod + pagedown|pageup = change monitor focus
* mod + rightshift = show/hide bar
* mod + left bracket|right bracket = change inner gap size
* mod + shift + left bracket|right bracket = change outer gap size
* mod + esc = close window
* mod + shift + esc = quit dwm

***
I have also included my custom config.h just for my setup feel free to delete config.h to use default values from config.def.h.
***
### Related Projects
* [Dynamic Status](https://gitlab.com/Suphi/DynamicStatus)
* [Status Icon Fonts](https://gitlab.com/Suphi/StatusIconFonts)
