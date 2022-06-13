btree:
	g++ --std=c++17  ./src/lib/btree/btree.cpp  ./test/btree_func_check.cpp -o ./bin/btree.out 
	./bin/btree.out > ./logs/btree_func_check.log


ntree:
	g++ --std=c++17  ./src/lib/ntree/ntree.cpp  ./test/ntree_func_check.cpp -o ./bin/ntree.out 
	./bin/ntree.out > ./logs/ntree_func_check.log

clean:
	rm -rf *.log
	rm -rf *.out
	cd bin; rm -rf *.out
	cd logs; rm -rf *.log