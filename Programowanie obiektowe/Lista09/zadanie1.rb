class Funkcja
  def initialize(&wejscie)
        @a_proc = Proc.new(&wejscie)
    end

    def value(x)
        @a_proc.call(x)
    end
    
    def zerowe(a, b, e)
      for i in (a..b).step(e)
        if value(i)==0
          return i
        end
      end
      return nil
    end

    def pole(a, b) #z https://gist.github.com/gysel/3257429
      a = a.to_f
      b = b.to_f
      result = 0.0

      dx = (b - a) / 1000
      dx_half = dx / 2
      for i in 0 ... 1000
        result += value(a + (i * dx))
      end
      result * dx
    end

    def poch(x)
      x.to_f
      d = 0.0000001
      x1 = x - d
      x2 = x + d
      y1 = value(x1)
      y2 = value(x2)

      (y2-y1)/(x2-x1)
    end
  end

test = Funkcja.new { |x| x*x }
puts test.value(2)
puts test.zerowe(0, 2, 1)
puts test.pole(0,2)
puts test.poch(2)
puts ""
test2 = Funkcja.new { | x | x*x*Math.sin(x) }
puts test2.value(2)
puts test2.zerowe(0, 2, 1)
puts test2.pole(0,2)
puts test2.poch(2)  