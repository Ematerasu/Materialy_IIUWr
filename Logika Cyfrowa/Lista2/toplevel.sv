module Lista2(output o, input [3:0] i);
  assign o = (i[0] | i[2] | i[3]) & (i[0] | i[1] | i[3]) & (i[1] | i[2] | i[3]) & (i[0] | i[1] | i[2]) & (!i[0] | !i[1] | !i[2] | !i[3]);
  endmodule