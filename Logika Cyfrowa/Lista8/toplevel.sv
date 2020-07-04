module pwm(input clk, input [15:0] d,
           input [1:0] sel,
           output [15:0] cnt, cmp, top,
           output out);
  
  always_ff @(posedge clk) begin
    if(sel == 2'd3) cnt <= d;
    else if (cnt >= top) cnt <= 16'b0;
    else cnt <= cnt + 1'd1;
  end
  
  always_ff @(posedge clk) begin
    if(sel == 2'd2) top <= d;
  end
  
  always_ff @(posedge clk) begin
    if(sel == 2'd1) cmp <= d;
  end
  
  always_ff @(posedge clk) begin
    if(cnt  >= cmp) out <= 1'b0;
    else out <= 1'b1;
  end
endmodule
