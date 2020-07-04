module tff(output q, nq, input t, clk, nrst);
logic ns, nr, ns1, nr1, j, k;
nand n1(ns, clk, j), n2(nr, clk, k),
n3(q, ns, nq), n4(nq, nr, q, nrst),
n5(ns1, !clk, t, nq), n6(nr1, !clk, t, q),
n7(j, ns1, k), n8(k, nr1, j, nrst);
endmodule
module syncnt(output [2:0] q, input en, clk, nrst, down);
genvar n;
logic [2:0] t, nq;
  assign t = {(down ? nq[1] : q[1] ) & t[1], (down ? nq[0] : q[0]) & t[0], en};
  tff tf1(q[0], nq[0], t[0], clk, nrst);
  tff tf2(q[1], nq[1], t[1], clk, nrst);
  tff tf3(q[2], nq[2], t[2], clk, nrst);
  
         
endmodule
