class Jawna
  def initialize(tekst)
    @tekst = tekst
  end
  def zaszyfruj(klucz)
    for i in 0...@tekst.length
      @tekst[i] = klucz[@tekst[i]]
    end
    Zaszyfrowane.new(@tekst)
  end
  def to_s
    @tekst
  end
end

class Zaszyfrowane
  def initialize(tekst)
    @tekst = tekst
  end
  def odszyfruj(klucz)
    @klucz = klucz
    for i in 0...@tekst.length
      @tekst[i] = @klucz.invert[@tekst[i]]
    end
    Jawna.new(@tekst)
  end
  def to_s
    @tekst
  end
end

klucz = {"a" => "z", "b" => "a", "c" => "b", "d" => "c",
"e" => "d", "f" => "e", "g" => "f", "h" => "g", "i" => "h",
"j" => "i", "k" => "j", "l" => "k", "m" => "l", "n" => "m",
"o" => "n", "p" => "o", "r" => "p", "s" => "r", "t" => "s",
"u" => "t", "v" => "u", "w" => "v", "x" => "w", "y" => "x", "z" => "y"}

test = Jawna.new("ruby")
test.zaszyfruj(klucz)
puts test

test2 = Zaszyfrowane.new(test.to_s)
test2.odszyfruj(klucz)
puts test2

test3 = Jawna.new("dominikbudzki")
test3.zaszyfruj(klucz)
puts test3

test4 = Zaszyfrowane.new(test3.to_s)
test4.odszyfruj(klucz)
puts test4