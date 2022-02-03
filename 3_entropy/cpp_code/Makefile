CPPFLAGS+=-I/softslin/catapultc10_1b/Mgc_home/shared/include/ -I../ac_fixed/

entropy_bench : entropy.o entropy_bench.o
	g++ -o entropy_bench entropy.o entropy_bench.o



clean:
	rm -f entropy.o entropy_bench.o  entropy_bench img_out.pgm
	rm -rf Catapult* catapult.log design_checker*
