CPPFLAGS+=-I/softslin/catapultc10_1b/Mgc_home/shared/include/ -I../ac_fixed/

wrap_bench : wrap.o wrap_bench.o
	g++ -o wrap_bench wrap.o wrap_bench.o



clean:
	rm -f wrap.o wrap_bench.o  wrap_bench img_out.pgm
	rm -rf Catapult* catapult.log design_checker*
