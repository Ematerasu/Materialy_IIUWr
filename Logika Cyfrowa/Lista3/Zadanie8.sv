module circuit(
  output a, b, c, d, e ,f , g,
  input [3:0] i
);
  
  assign a = i[3] | i[1] | (!i[3] & i[2] & i[0]) | (!i[2] & !i[0]);
  assign b = !i[2] | (!i[1] & !i[0]) | (i[1] & i[0]);
  assign c = !i[1] | i[0] | (!i[3] & i[2]);
  assign d = i[3] | (i[1] & !i[0]) | (i[2] & !i[1] & i[0]) | (!i[2] & i[1]) | (!i[2] & !i[0]);
  assign e = (i[1] & !i[0]) | (!i[2] & !i[0]);
  assign f = (!i[1] & !i[0]) | (i[2] & !i[1]) | i[3] | (i[2] & i[1] & !i[0]);
  assign g = i[3] | (i[2] & !i[1]) | (i[1] & !i[0]) | (!i[3] & !i[2] & i[1]);
                     
endmodule
//Przesylam skany na ktorych widac jak uzyskalem te formuly
