file="numbers.txt"
lock="numbers.lock"

if [[ ! -f $file ]]
then
    echo 1 >> $file
fi

while true
do
    if `ln $file $lock 2> /dev/null`
    then
        last_number=`tail --lines=1 $file`
        echo $last_number
        echo $(($last_number+1)) >> $file
        rm $lock
    fi
done
