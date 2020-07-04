module microwave(input clk, nrst, door, start, finish,
     output heat, light, bell);
  
  logic [4:0] q; //stany
  
    always_ff @(posedge clk or negedge nrst) begin
      if(!nrst) q <= 5'b00001;
      else if(q[0]) begin //closed
          q[0] <= !((start & !door) | door) ? 1 : 0;
          q[1] <= door ? 1 : 0;
          q[2] <= start & !door ? 1 : 0;
        end
      else if(q[1]) begin //open
          q[0] <= !door ? 1 : 0;
          q[1] <= door ? 1 : 0;
        end
      else if(q[2]) begin //cook
          q[2] <= !(finish | door) ? 1 : 0; 
          q[3] <= finish & !door ? 1 : 0;
          q[4] <= door ? 1 : 0;
        end
      else if(q[3]) begin //bell
          q[1] <= door ? 1 : 0;
          q[3] <= !door & finish ? 1 : 0;
        end
      else if(q[4]) begin //pause
          q[2] <= !door ? 1 : 0;
          q[4] <= door ? 1 : 0;
        end
    end
  
  assign heat=q[2];
  assign light=q[2] | q[1] | q[4];
  assign bell=q[3];
endmodule
