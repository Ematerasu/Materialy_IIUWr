//Lista1
module toplevel(output o, input a, b, c, d, x, y);
	assign o = (!x && ((a && !y) || (b && y))) || (x && ((c && !y) || (d && y)));
endmodule
