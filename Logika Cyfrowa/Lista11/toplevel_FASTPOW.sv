module circuit(input clk, nrst, start, input [15:0] inx, input [7:0] inn,
               output [15:0] out, output ready);
  
  logic [15:0] x;
  logic [7:0] n;
  logic [15:0] a;
  logic [15:0] mult;
  
  always_ff @(posedge clk or negedge nrst) begin
    if (!nrst) begin 
      ready <= 1'b1;
    end
      else case (ready)
        1'b1: if (start) begin
        a <= 15'd1;
        x <= inx;
        n <= inn;
        ready <= 1'b0;
          end
        1'b0: if(n == 0) begin
        out <= a;
          ready <= 1'b1;
        end
          else begin
//uzywam "=" zamiast "<=" zeby wartosc do mult przypisalo od razu
          if(!n[0]) mult = x;
          else mult = a;
      mult = mult * x;
//poniewaz przypisanie nieblokujace powoduje blad i wartosc dont care na wyjsciu
          if(!n[0]) begin
            x <= mult;
          n <= n >> 1;
        end
         else begin
            a <= mult;
           n <= n-1;
          end
        end
      endcase
  end
endmodule
