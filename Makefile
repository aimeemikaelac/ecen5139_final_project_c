SRC_DIR			:= src
VERILOG_INCLUDES	:= drivers/midtermPriorityQueueVerilog
HLS_INCLUDES		:= drivers/midtermPriorityQueueHls
MINHEAP_INCLUDES	:= drivers/minHeapHls
VERILOG			:= $(SRC_DIR)/midtermPriorityQueueVerilog.c
HLS			:= $(SRC_DIR)/midtermPriorityQueueHls.c
MINHEAP			:= $(SRC_DIR)/minHeapHls.c
VERILOG_TARGET		:= runqueueVerilog
HLS_TARGET		:= runqueueHls
MINHEAP_TARGET		:= runqueueMinHeap
VERILOG_DRIVERS		:= $(foreach d, $(VERILOG_INCLUDES), $(wildcard $d/*.c))
HLS_DRIVERS		:= $(foreach d, $(HLS_INCLUDES), $(wildcard $d/*.c))
MINHEAP_DRIVERS		:= $(foreach d, $(MINHEAP_INCLUDES), $(wildcard $d/*.c))

.PHONY: clean

verilog: $(VERILOG)
	$(CC) -o $(VERILOG_TARGET) $^ $(VERILOG_DRIVERS) -I$(VERILOG_INCLUDES)

hls: $(HLS)
	$(CC) -o $(HLS_TARGET) $^ $(HLS_DRIVERS) -I$(HLS_INCLUDES)

minheap: $(MINHEAP)
	$(CC) -o $(MINHEAP_TARGET) $^ $(MINHEAP_DRIVERS) -I$(MINHEAP_INCLUDES)

clean:
	$(RM) -rf *.o
	$(RM) -rf $(VERILOG_TARGET)
	$(RM) -rf $(HLS_TARGET)
	$(RM) -rf $(MINHEAP_TARGET)
