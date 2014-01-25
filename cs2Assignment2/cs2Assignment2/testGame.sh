#! /bin/bash 
#test script for jens cs2 program
# by levi balling
#clear
echo -e "cleaning files"
rm Valresult*
rm gameResult*
echo -e "starting testing"
echo 
STR=0
X=0
O=1
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game << 'EOF'
3
1
2
2
1
3
3
1
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game << 'EOF'
3
2
3
3
2
4
4
2
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
3
4
4
3
5
5
3
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
4
5
5
4
6
6
4
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
1
2
3
2
1
1
3
3
2
3
1
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
2
3
4
3
2
2
4
4
3
4
2
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
3
4
5
4
3
3
5
5
4
5
3
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
4
5
6
5
4
4
6
6
5
6
4
EOF
)>> "gameResult$STR.txt" 2>&1
# test 9
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
2
1
1
3
3
2
1
2
3
1
2
3
1
EOF
)>> "gameResult$STR.txt" 2>&1
#test 10
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
2
1
1
3
3
2
1
2
3
1
2
3
3
EOF
)>> "gameResult$STR.txt" 2>&1
#test 11
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
3
2
2
4
4
3
2
3
4
2
3
4
2
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
3
2
2
4
4
3
2
3
4
2
3
4
4
EOF
)>> "gameResult$STR.txt" 2>&1
#test 13
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
4
3
3
5
5
4
3
4
5
3
4
5
3
EOF
)>> "gameResult$STR.txt" 2>&1

STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
4
3
3
5
5
4
3
4
5
3
4
5
5
EOF
)>> "gameResult$STR.txt" 2>&1
#test 15
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
5
4
4
6
6
5
4
5
6
4
5
6
4
EOF
)>> "gameResult$STR.txt" 2>&1
#test 16
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
5
4
4
6
6
5
4
5
6
4
5
6
6
EOF
)>> "gameResult$STR.txt" 2>&1
#test 17
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
1
2
1
2
1
EOF
)>> "gameResult$STR.txt" 2>&1
#test 18
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
2
1
2
1
2
EOF
)>> "gameResult$STR.txt" 2>&1
#test 19
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
3
1
3
1
3
EOF
)>> "gameResult$STR.txt" 2>&1

#test 20
STR=$((STR + 1))
echo -e '\n'
echo -e "Testing $STR"
(valgrind --log-file="Valresult$STR.txt" ./game <<-EOF
3
4
1
4
1
4
EOF
)>> "gameResult$STR.txt" 2>&1

grep -B8 "Player Wins" gameResult*.txt
grep -B8 "ERROR SUMMARY:" Valresult*.txt
