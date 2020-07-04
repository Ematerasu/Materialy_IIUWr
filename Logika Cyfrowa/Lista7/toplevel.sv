module tff(output q, nq, input t, clk, nrst);
logic ns, nr, ns1, nr1, j, k;
nand n1(ns, clk, j), n2(nr, clk, k),
n3(q, ns, nq), n4(nq, nr, q, nrst),
n5(ns1, !clk, t, nq), n6(nr1, !clk, t, q),
n7(j, ns1, k), n8(k, nr1, j, nrst);
endmodule

module main(input clk, nrst, step, down, output [3:0] out);
  logic [3:0] t, nq;
  //z map karnaugh
  assign t[0] = (!down & !step) | (!down & step & 0) | (down & !step) | (down & step & 0);
  assign t[1] = (!down & !step & !nq[0]) | (!down & step) | (down & !step & nq[0]) | (down & step);
  assign t[2] = (!down & !step & !nq[1] & !nq[0]) | (!down & step & !nq[1]) | (down & !step & nq[0] & nq[1]) | (down & step & nq[1]);
  assign t[3] = (!down & !step & !nq[2] & !nq[1] & !nq[0]) | (!down & step & !nq[2] & !nq[1]) | (down & !step & nq[2] & nq[1] & nq[0]) | (down & step & nq[1] & nq[2]);
  
  tff tf1(out[0], nq[0], t[0], clk, nrst);
  tff tf2(out[1], nq[1], t[1], clk, nrst);
  tff tf3(out[2], nq[2], t[2], clk, nrst);
  tff tf4(out[3], nq[3], t[3], clk, nrst);

endmodule
