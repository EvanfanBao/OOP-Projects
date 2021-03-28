#!/bin/bash

#test1: pdadd--right input
echo "2025.02.10
This is a test for pdadd
just add one entity." > data.txt
./pdadd
#test2: pdadd--invalid argument--record the PC date
echo "sfdf
something wrong." > data.txt
./pdadd
#test3: pdadd--no time date--date is 0--record the PC date
echo "0
test skip record date." > data.txt
./pdadd


#test4: pdlist--no argument
echo  "pdlist_1 ./pdlist" >> list.txt
./pdlist
echo "" >> list.txt

#test5: pdlist--start and end parameter
echo  "pdlist_2 ./pdlist --start 2015.04.19 --end 2020.06.04" >> list.txt
./pdlist --start 2015.04.19 --end 2020.06.04
echo -e "" >> list.txt

#test6: pdlist--s and e (abbreviation)
echo  "pdlist_3 ./pdlist -s 2015.04.19 -e 2020.06.04" >> list.txt
./pdlist -s 2015.04.19 -e 2020.06.04
echo -e "" >> list.txt

#test7: pdlist--s or e
echo  "pdlist_4 ./pdlist --start 2015.04.19" >> list.txt
./pdlist --start 2015.04.19
echo -e "" >> list.txt
echo  "pdlist_5 ./pdlist -e 2020.06.04" >> list.txt
./pdlist -e 2020.06.04
echo -e "" >> list.txt

#test8: pdshow
echo "pdshow_1 ./pdshow 2010.04.12" >> show.txt
./pdshow 2020.04.17

#test9: pdshow exception capture. according to the exception, it may show the PC Date content if any
echo "pdshow_2 ./pdshow ssfds" >> show.txt
./pdshow ssfds

#test10: pdremove on succeed 0
echo -e "\npdremove_1 ./pdremove 2020.04.22" >> out.txt
./pdremove 2020.04.22
echo $? >> out.txt

#test11: pdremove on fail 127 --- acutally I return -1. unsign 127 is sign -1
echo "pdremove_2 ./pdremove" >> out.txt
./pdremove
echo $? >> out.txt

