module ctrlpath(input clk, nrst, start, a_eq_b,
               output ready);
  
  always_ff @(posedge clk or negedge nrst) begin
    if (!nrst) begin 
      ready <= 1'b1;
    end
      else case (ready)
        1'b1: if (start) begin
            ready <= 1'b0;
          end
        1'b0: if(a_eq_b) begin
          ready <= 1'b1;
        end
      endcase
  end
endmodule

module datapath(input clk, nrst, start, ready, input [7:0] ina, inb,
                output [7:0] out, output a_eq_b);
  
  logic [7:0] a, b;
  always_ff @(posedge clk) begin
    case (ready)
        1'b1: if (start) begin
            a <= ina;
            b <= inb;
              a_eq_b <= ina == inb;
          end
        1'b0: if(a == b) begin
          out <= a;
          a_eq_b <= 1'b1;
        end
          else begin
            if(a < b) begin
              a <= b;
              b <= a;
            end
          else a <= a - b;
          end
      endcase
  end
endmodule

module circuit(input clk, nrst, start, input [7:0] ina, inb,
               output [7:0] out, output ready);
  
  logic a_eq_b;
  ctrlpath ctrlpath1(clk, nrst, start, a_eq_b, ready);
  datapath datapath1(clk, nrst, start, ready, ina, inb, out, a_eq_b);
endmodule
