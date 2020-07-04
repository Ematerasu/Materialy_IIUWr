//oparte na
// https://www.geeksforgeeks.org/universal-shift-register-in-digital-logic/?fbclid=IwAR2HQirSANuzILXHjEhvcElgl04_UxaIHjjEoU4OhQdxlbp88P24eXovtCE
//przerzutnik z digitaljs
module d_latch(
  input d, e,
  output q, nq
);

  logic s, r;

  nor g1(q, r, nq);
  nor g2(nq, s, q);
  and g3(r, e, nd);
  and g4(s, e, d);
  not g5(nd, d);

endmodule

module mux(input i0, i1, i2, i3, input l, r, output o);
  
  assign o = l & r ? i3 : l ? i2 : r ? i1 : i0;
  
endmodule

module main(input l, r, i, c,
            input [7:0] d,
            output [7:0] q);
  
  logic pom1, pom2, pom3, pom4, pom5, pom6, pom7, pom8;
  
  mux m1(q[0], i, q[1], d[0], l, r, pom1);
  d_latch d1(pom1, c, q[0],);
  
  mux m2(q[1], q[0], q[2], d[1], l, r, pom2);
  d_latch d2(pom2, c, q[1],);
  
  mux m3(q[2], q[1], q[3], d[2], l, r, pom3);
  d_latch d3(pom3, c, q[2],);
  
  mux m4(q[3], q[2], q[4], d[3], l, r, pom4);
  d_latch d4(pom4, c, q[3],);
  
  mux m5(q[4], q[3], q[5], d[4], l, r, pom5);
  d_latch d5(pom5, c, q[4],);
  
  mux m6(q[5], q[4], q[6], d[5], l, r, pom6);
  d_latch d6(pom6, c, q[5],);
  
  mux m7(q[6], q[5], q[7], d[6], l, r, pom7);
  d_latch d7(pom7, c, q[6],);
  
  mux m8(q[7], q[6], i, d[7], l, r, pom8);
  d_latch d8(pom8, c, q[7],);
  
endmodule
