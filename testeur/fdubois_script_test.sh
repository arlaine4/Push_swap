
#!/bin/sh

echo "Testing 21 times for 3 numbers"
for n in {1..21}; do ARG=`ruby -e "puts (-1..1).to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l; sleep 0.105 ; done
sleep 1
echo "Testing 42 times for 5 numbers"
for n in {1..42}; do ARG=`ruby -e "puts (-2..2).to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker $ARG && ./push_swap $ARG | wc -l; sleep 0.21 ; done
sleep 1
echo "Testing 42 times for 100 numbers"
for n in {1..42}; do ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker $ARG && ./push_swap $ARG | wc -l; done
sleep 1
echo "Testing 5 times for 500 numbers"
for n in {1..5}; do ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker $ARG && ./push_swap $ARG | wc -l; done
echo "Done!"
