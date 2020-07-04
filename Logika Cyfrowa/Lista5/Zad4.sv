module decoder(
input w0, w1,
input en,
output y0, y1, y2, y3
);

  assign y0 = !w0 & !w1 ? en : 0;
  assign y1 = w0 & !w1 ? en : 0;
  assign y2 = !w0 & w1 ? en : 0;
  assign y3 = w0 & w1 ? en : 0;
  
endmodule

module circuit(input [2:0] i,
            output [7:0] o);
  
  decoder d1(i[0], i[1], !i[2], o[0], o[1], o[2], o[3]);
  decoder d2(i[0], i[1], i[2], o[4], o[5], o[6], o[7]);
  
endmodule
