class Kolekcja
    def initialize()
        @kol = Array.new
    end

    def swap(i,j)
        temp = @kol[i]
        @kol[i] = @kol[j]
        @kol[j] = temp
    end

    def length()
        return @kol.length()
    end

    def get(i)
        return @kol[i];
    end

    def insert(i, v)
      @kol[i] = v
    end

    def add(x)
        @kol[@kol.length()] = x
        return nil
    end

    def printAll()
      for i in 0..(@kol.length()-1) do
        puts @kol[i]
      end
    end

end

class Sortowanie
    def sort1(kol)
        n = kol.length()
        for i in 0..(n-1) do
            for j in 1..(n-i-1) do
            if kol.get(j-1) > kol.get(j)
                kol.swap(j-1, j)
                  end
              end
           end
    return kol
      end

    def sort2(kol)
      n = kol.length()
      for i in 1..(n-1) do
       value = kol.get(i)
       j = i - 1
       while (j >= 0) && (kol.get(j) > value)
         kol.insert(j+1, kol.get(j))
         j -= 1
       end
       kol.insert(j+1, value)
     end
     return kol
  end

end

test = Kolekcja.new()

test.add(1)
test.add(2)
test.add(3)
test.add(9)
test.add(4)
test.add(6)
test.add(7)
test.add(8)

test2 = Kolekcja.new()
test2.add(1)
test2.add(2)
test2.add(3)
test2.add(9)
test2.add(4)
test2.add(6)
test2.add(7)
test2.add(8)



test.swap(0, 2)
test.printAll()
puts ""
test2.printAll
puts ""

test3 = Sortowanie.new()

test = test3.sort1(test)
test2 = test3.sort2(test2)
puts ""
test.printAll()
puts ""
test2.printAll()

#Wzorzec Strategy





