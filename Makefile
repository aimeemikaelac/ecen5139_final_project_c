SRC_DIR			:= src
VERILOG_INCLUDES	:= drivers/midtermPriorityQueueVerilog
VERILOG			:= $(SRC_DIR)/midtermPriorityQueueVerilog.c
VERILOG_TARGET		:= runqueueVerilog
VERILOG_DRIVERS		:= $(foreach d, $(VERILOG_INCLUDES), $(wildcard $d/*.c))

.PHONY: clean

verilog: $(VERILOG)
	$(CC) -o $(VERILOG_TARGET) $^ $(VERILOG_DRIVERS) -I$(VERILOG_INCLUDES)

clean:
	$(RM) -rf *.o
	$(RM) -rf $(VERILOG_TARGET)
