module BubbleSort(input [15:0] i,
            output [15:0] o);
  integer j,k;
  logic [3:0] swap;
  logic [15:0] temp;
  always_comb begin
    temp = i;
    
    for(j=0;j<4;j = j+1) begin
      for(k=1;k<4-j;k = k+1) begin
        
        if(temp[(4*k +3):(4*k)] < temp[(4*(k-1) +3):(4*(k-1))]) begin
          swap = temp[(4*k +3):(4*k)];
          temp[(4*k +3):(4*k)] = temp[(4*(k-1) +3):(4*(k-1))];
          temp[(4*(k-1) +3):(4*(k-1))] = swap;
          
        end
      end
    end
  end   
  assign o = temp;
endmodule
