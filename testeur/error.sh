clear
echo "\n\n\n-------------------\nTests for checker :\n\nYou need to have always Error\n----------------------\n\n"
sleep 2.5

echo "./checker -v"
./checker -v
echo ""
sleep 0.5

echo "./checker test"
./checker test
echo ""
sleep 0.5

echo "./checker -v test"
./checker -v test
echo ""
sleep 0.5

echo "./checker 2 3 a"
./checker 2 3 a
echo ""
sleep 0.5

echo "./checker 2 3 a"
./checker -v 2 3 a
echo ""
sleep 0.5

echo "./checker -v "2 3 a""
./checker -v "2 3 a"
echo ""
sleep 0.5

echo "./checker 0 0"
./checker 0 0
echo ""
sleep 0.5

echo "./checker -v 0 0"
./checker -v 0 0
echo ""
sleep 0.5

echo "./checker 4 3 2 1 4"
./checker 4 3 2 1 4
echo ""
sleep 0.5

echo "./checker 21474836478"
./checker 2147483648
echo ""
sleep 0.5

echo "./checker -2147483649"
./checker -2147483649
echo ""
sleep 0.5

echo "./checker 11111111111111111111111111111"
./checker 111111111111111111111111111111
echo ""
sleep 0.5

echo "./checker -9223372036854775808 (=LONG_MIN)"
./checker -9223372036854775808
echo ""
sleep 0.5

echo "./checker 9223372036854775807 (= LONG_MAX)"
./checker 9223372036854775807
echo ""
sleep 0.5

echo "./checker 9223372036854775808 (= LONG_MAX + 1)"
./checker 9223372036854775808
echo ""
sleep 0.5

echo "./checker 1 2 3 -2147483649"
./checker 1 2 3 -2147483649
echo ""
sleep 0.5

echo "./checker 0 10 -1 a 4"
./checker 0 10 -1 a 4
echo ""
sleep 0.5

echo "./checker -v6 0 4 2 1"
./checker -v6 0 4 2 1
echo ""
sleep 0.5

echo "./checker "-v 4 3 2 1""
./checker "-v 4 3 2 1"
echo ""
sleep 0.5

echo "./checker "- 4 3 2 1""
./checker "- 4 3 2 1"
echo ""
sleep 0.5

echo "./checker - 4 3 2 1"
./checker - 4 3 2 1
echo ""
sleep 0.5

echo "./checker 2 -v 3 0"
./checker 2 -v 3 0
echo ""
sleep 0.5

echo "echo -n "sa" | ./checker 0 1 2 3"
echo -n "sa" | ./checker 0 1 2 3
echo ""
sleep 0.5

echo "echo -n "sa" | ./checker 1 0 2 3"
echo -n "sa" | ./checker 1 0 2 3
echo ""
sleep 0.5

echo "echo "sa\\n" | ./checker 0 1 2 3"
echo "sa\n" | ./checker 0 1 2 3
echo ""
sleep 0.5

echo "echo -n "sa" | ./checker 0 0"
echo -n "sa" | ./checker 0 0
echo ""
sleep 0.5
