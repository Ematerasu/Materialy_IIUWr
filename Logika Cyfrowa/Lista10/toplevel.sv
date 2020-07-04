module pamiec(input nrst, push, step, input [15:0] d,
                  input [1:0] op, output [9:0] cnt,
              output [15:0] out);
  
  logic [15:0] mem [0:1023]; //1024x16
  
  always_ff @(posedge step or negedge nrst) begin
    if(!nrst) cnt <= 0;
    else if(push) cnt <= cnt + 1;
    else if(cnt > 0 && (op == 2'd3 || op == 2'd2)) cnt <= cnt - 1;
  end

  always_ff @(posedge step) begin
    if(push) mem[cnt] <= d;
    else if(op == 2'd1) mem[cnt-1] <= mem[cnt-1] * -1;
    else if(op == 2'd2) mem[cnt-2] <= mem[cnt-2] + mem[cnt-1];
    else if(op == 2'd3) mem[cnt-2] <= mem[cnt-2] * mem[cnt-1];
  end
  
  assign out = !nrst ? 0 : mem[cnt-1];
endmodule

module kalkulator(input nrst, push, step, input [15:0] d,
                  input [1:0] op, output [9:0] cnt,
                  output [15:0] out);
 
  pamiec memo(nrst, push, step, d, op, cnt, out);
 
endmodule
