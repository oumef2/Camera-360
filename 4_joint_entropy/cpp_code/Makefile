CPPFLAGS+=-I/softslin/catapultc10_1b/Mgc_home/shared/include/ -I../ac_fixed/

joint_entropy_bench : joint_entropy.o joint_entropy_bench.o
	g++ -o joint_entropy_bench joint_entropy.o joint_entropy_bench.o
	
clean:
	rm -f joint_entropy.o joint_entropy_bench.o  joint_entropy_bench img_out.pgm
	rm -rf Catapult* catapult.log design_checker*
