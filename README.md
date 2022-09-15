compile p1: g++ -g -Wall -std=c++11 -c split.cpp
g++ -g -Wall -std=c++11 split_test.cpp split.cpp -o split
run p1: ./split

compile p2:  g++ -g -Wall ulliststr.cpp ulliststr_test.cpp -o ulliststr_test
run p2: ./ulliststr_test

