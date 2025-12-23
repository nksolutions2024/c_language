obj-m = k1.o
 
ifdef ARCH
  
else
  KSRC = /lib/modules/$(shell uname -r)/build
endif

mods:
	make -C $(KSRC)  M=$(shell pwd) modules
 
clean:
	make -C $(KSRC)  M=$(shell pwd) clean
