class Funkcja2
    def initialize(&wejscie)
          @a_proc = Proc.new(&wejscie)
      end
  
      def value(x, y)
          @a_proc.call(x, y)
      end

      def objetosc(a, b, c, d)
        #tego nie rozumiem
      end

      def poziomica(a,b,c,d,wysokosc)
        przyblizenie = 0.01
        result = []
        for x in a..b
          for y in c..d
            if (wysokosc - value(x, y)).abs < przyblizenie || (value(x, y) - wysokosc).abs < przyblizenie
              result += [[x, y]]
            end
          end
        end
        result
      end
    end

test = Funkcja2.new { |x, y| x*y }
test.poziomica(0, 3, 1, 4, 6)