ex="lemipc"
display="lemipc_display"

#20 players for each team by default
nb=20
#remove display on term
flag='1>/dev/null 2>/dev/null'
#press enter when the game can start
echo='echo |'

#modify param
if [ "$#" -gt 0 ]; then
    nb=$1
fi
if [ "$2" == 'a' ]; then
    flag=''
fi
if [ "$3" == 'a' ]; then
    echo=''
fi

i=0
while [ "$i" -lt "$nb" ]
do
    sh -c "sh -c '$echo ./$ex 1' $flag &"
    sh -c "sh -c '$echo ./$ex 2' $flag &"
    sh -c "sh -c '$echo ./$ex 3' $flag &"
    sh -c "sh -c '$echo ./$ex 4' $flag &"
    sh -c "sh -c '$echo ./$ex 5' $flag &"
    sh -c "sh -c '$echo ./$ex 6' $flag &"
    i=`expr $i + 1`
done

if [ "$#" -gt 3 ]; then
    sh -c "./$display"
    sh -c "./$ex clean 1>/dev/null"
fi
