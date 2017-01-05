
ZMPINC:=-I../include
ZMQLIB:=-L../bin -lzmqclient64
ROCKETMQ:=-L../bin -lrocketmq64
CURLLIB:=-L../libs/curl/lib -lcurl
OBJDIR:=obj
OUT1:=producertest 
OUT2:=consumertest
OUT3:=orderproducer
OUT4:=orderconsumer

all:$(OUT1) $(OUT2) $(OUT3) $(OUT4)

$(OUT1):ProducerMain.o
	g++ -o $@ $^ $(ZMQLIB) $(ROCKETMQ) $(CURLLIB)

$(OUT2):ConsumerMain.o  ConcurrentMsgListenerImpl.o
	g++ -o $@ $^ $(ZMQLIB) $(ROCKETMQ) $(CURLLIB)

$(OUT3):OrderProducerMain.o
	g++ -o $@ $^ $(ZMQLIB) $(ROCKETMQ) $(CURLLIB)

$(OUT4):OrderConsumerMain.o OrderMsgListenerImpl.o
	g++ -o $@ $^ $(ZMQLIB) $(ROCKETMQ) $(CURLLIB)

crdir:
	mkdir -p $(OBJDIR)
%.o : %.cpp
	g++ -g -c $(ZMPINC) $^ -o $@ 

.PHONY : clean
clean:
	rm -rf *.o $(OUT1) $(OUT2) $(OUT3) $(OUT4)
