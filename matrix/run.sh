g++ -c matrix.cpp
g++ -c run.cpp
g++ run.o matrix.o -o run
rm *.o
