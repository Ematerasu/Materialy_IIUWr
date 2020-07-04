module halfadder(
  input a, 
  input b,
  output o,
  output c
);

  assign o = a ^ b;
  assign c = a & b;

endmodule

module fulladder(
  input a,
  input b,
  input d,
  output o,
  output c
);

  logic t, c1, c2;

  halfadder ha1(a, b, t, c1);
  halfadder ha2(t, d, o, c2);

  assign c = c1 | c2;

endmodule

module multbythree(input[7:0] i,
                   output [9:0] o);
  
  logic c1, c2, c3, c4, c5, c6, c7;
  
  assign o[0] = i[0];
  fulladder fa1(i[1], i[0], 0, o[1], c1);
  fulladder fa2(i[2], i[1], c1, o[2], c2);
  fulladder fa3(i[3], i[2], c2, o[3], c3);
  fulladder fa4(i[4], i[3], c3, o[4], c4);
  fulladder fa5(i[5], i[4], c4, o[5], c5);
  fulladder fa6(i[6], i[5], c5, o[6], c6);
  fulladder fa7(i[7], i[6], c6, o[7], c7);  
  assign o[8] = i[7] ^ c7;
  assign o[9] = i[7] & c7;
  
  
endmodule

module Zad1(input [7:0] i,
            input [4:0] m, //one-hot
            output [9:0] o);
  
  logic [9:0] pom2, pom3, pom4;
  assign pom2 = i<<1;
  multbythree m1(i,pom3);
  assign pom4 = i<<2;
  
  assign o = m[1] ? i : (m[2] ? pom2 : (m[3] ? pom3 : (m[4] ? pom4 : i))); //Dla innych liczb zwraca poprostu wartosc wejscia.
endmodule
