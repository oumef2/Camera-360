CPPFLAGS+=-I/softslin/catapultc10_1b/Mgc_home/shared/include/ -I../ac_fixed/

downscale_bench : downscale.o downscale_bench.o
	g++ -o downscale_bench downscale.o downscale_bench.o



clean:
	rm -f downscale.o downscale_bench.o  downscale_bench img_out.pgm
	rm -rf Catapult* catapult.log design_checker*
