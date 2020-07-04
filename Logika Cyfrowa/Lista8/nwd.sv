module nwd(
  input [15:0] a, b,
input ini, clk,
  output [15:0] s,
output fin
);
logic cmp;
  logic [15:0] newa;
  logic [15:0] newb;
assign cmp = newa > 15'b0 & newb > 15'b0 & newa != newb;
assign fin = !cmp;
assign s = newa>newb ? newa : newb; //gdyby jedno z nich wyzerowalo sie to liczba != 0 jest NWD
  
always_ff @(posedge clk)
if (ini) begin
newa <= a;
newb <= b;
end 
  else if (cmp) begin
        if(newa>newb) begin
     newa <= newa-newb;
  end
  else begin
   newb <= newb-newa;
end
        end
endmodule
