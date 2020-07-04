module adder(input a, b, c,
                 output o);
  assign o = a ^ b ^ c;
endmodule

module C_adder (input a, b, sub, c0,
                output c);
  assign c = ((a & b) ^ (b & sub)) | ((a & c0) ^ (c0 & sub)) | (b & c0);
endmodule

module fouradder(input [3:0] a, b,
                 input c0, sub,
                 output [3:0] o,
                 output c);
  logic c1, c2, c3;
  C_adder get_c1(a[0], b[0], sub, c0, c1);
  C_adder get_c2(a[1], b[1], sub, c1, c2);
  C_adder get_c3(a[2], b[2], sub, c2, c3);
  C_adder get_c(a[3], b[3], sub, c3, c);
  
  adder add1(a[0], b[0], c0, o[0]);
  adder add2(a[1], b[1], c1, o[1]);
  adder add3(a[2], b[2], c2, o[2]);
  adder add4(a[3], b[3], c3, o[3]);
endmodule  

module corr(input [3:0] i, 
            input c,
            output [3:0] o);
  assign o[0] = 0;
  assign o[1] = (i[3] & i[2]) | (i[3] & i[1]) | c;
  assign o[2] = o[1];
  assign o[3] = 0;
endmodule

module mod10(input [3:0] a, b,
             input c0, sub,
             output [3:0] o,
             output s);
  logic [3:0] wynik1, help;
  logic c1, c2;
  fouradder fa1(a, b, c0, sub, wynik1, c1);
  corr h1(wynik1, c1, help);
  fouradder fa2(wynik1, help, 0, sub, o, c2);
  assign s = c1 | c2;
endmodule
module main(input [7:0] a, b,
            input sub,
            output [7:0] o);
  logic [3:0] s1, s2;
  logic c, smth;
  logic [3:0] a1, a2, b1, b2;
  assign {a1, a2} = a;
  assign {b1, b2} = b;
  mod10 firstdigit(a2, b2, 0, sub, s1, c);
  mod10 seconddigit(a1, b1, c, sub, s2, smth);
  
  assign o = {s2, s1};
