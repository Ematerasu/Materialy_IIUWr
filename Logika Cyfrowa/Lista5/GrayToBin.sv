module GrayToBin(input [31:0] i,
                 output [31:0] o);
  logic pom;
  logic [31:0] temp;
  integer j;
  always_comb begin
    pom = i[31];
    temp[31] = i[31];
    for(j = 30;j>=0;j=j-1) begin
      temp[j] = i[j] ^ pom;
      pom = temp[j];
    end
  end  
  assign o = temp;
  
endmodule
