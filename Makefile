any: build clean

build:
	@gcc src/main.c -o FerrumForge -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	@./FerrumForge
	@make clean

clean:
	@rm -f ./FerrumForge