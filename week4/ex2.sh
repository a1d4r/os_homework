gcc ex2.c -o ex2
./ex2 &
pstree $!
for i in {2..5}; do
    sleep 5
    pstree $!
done