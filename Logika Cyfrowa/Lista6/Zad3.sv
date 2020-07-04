module dff(output q, nq, input clk, d);
logic r, s, nr, ns;
nand gq(q, nr, nq), gnq(nq, ns, q),
gr(nr, clk, r), gs(ns, nr, clk, s),
gr1(r, nr, s), gs1(s, ns, d);
endmodule
//przycisk en wlacza uklad, po tym jak f_by_4 bedzie w stanie wysokim en wylaczamy
//mialem problem jak to zrobic bez en.
module Zad3(input clk, input en, output f_by_4);
  logic nq, nq2, f_by_2, x;
  or o1(x, en, nq2);
  dff d1(f_by_2, nq, clk, x);
  dff d2(f_by_4, nq2, clk, f_by_2);
endmodule
