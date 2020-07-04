module g(input [3:0] a, b,
	output [3:0] g
);
   assign g[0] = a[0] & b[0];
   assign g[1] = a[1] & b[1];
   assign g[2] = a[2] & b[2];
   assign g[3] = a[3] & b[3];
endmodule

module p(input [3:0] a, b,
	output [3:0] p
);
   assign p[0] = a[0] | b[0];
   assign p[1] = a[1] | b[1];
   assign p[2] = a[2] | b[2];
   assign p[3] = a[3] | b[3];

endmodule

module Fadder(input [3:0] a, b,
             input c0,
             output [3:0] s,
             output gs, ps
);
  logic [3:0] g, p;
  logic [2:0] c;

  g get_g(a, b, g);
  p get_p(a, b, p);
  
  assign c[0] = g[0] | (p[0] & c0);
  assign c[1] = g[1] | (g[0] & p[1]) | (p[0] & p[1] & c0);
  assign c[2] = g[2] | (g[0] & p[1] & p[2]) | (p[2] & g[1]) | (c0 & p[0] & p[1] & p[2]);

  assign s[0] = a[0] ^ b[0] ^ c0;
  assign s[1] = a[1] ^ b[1] ^ c[0];
  assign s[2] = a[2] ^ b[2] ^ c[1]; 
  assign s[3] = a[3] ^ b[3] ^ c[2];
  
  assign gs = (g[0] & p[1] & p[2] & p[3]) | (g[1] & p[2] & p[3]) | (g[2] & p[3]) | g[3];
  assign ps = p[0] & p[1] & p[2] & p[3];
	

endmodule


module glowny_sumator(input [15:0] a, b,
  		      output [15:0] o);

  logic [3:0] a0, a1, a2, a3;
  logic [3:0] b0, b1, b2, b3;
  logic [3:0] s0, s1, s2, s3;
  logic [3:0] c, g, p;
  assign {a3, a2, a1, a0} = a;
  assign {b3, b2, b1, b0} = b;
  assign c[0] = 0;

  Fadder fa1(a0, b0, c[0], s0, g[0], p[0]);
  assign c[1] = g[0] | (p[0] & c[0]);
  Fadder fa2(a1, b1, c[1], s1, g[1], p[1]);
  assign c[2] = g[1] | (g[0] & p[1]) | (p[0] & p[1] & c[0]);
  Fadder fa3(a2, b2, c[2], s2, g[2], p[2]);
  assign c[3] = g[2] | (g[0] & p[1] & p[2]) | (p[2] & g[1]) | (c[0] & p[0] & p[1] & p[2]);
  Fadder fa4(a3, b3, c[3], s3, g[3], p[3]);

  assign o = {s3, s2, s1, s0};

endmodule


