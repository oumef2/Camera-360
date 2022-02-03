CPPFLAGS+=-I/softslin/catapultc10_1b/Mgc_home/shared/include/ -I../ac_fixed/

mi_cost_bench : mi_cost.o mi_cost_bench.o
	g++ -o mi_cost_bench mi_cost.o mi_cost_bench.o



clean:
	rm -f mi_cost.o mi_cost_bench.o  mi_cost_bench img_out.pgm
	rm -rf Catapult* catapult.log design_checker*
