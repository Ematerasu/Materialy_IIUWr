class Fixnum
    def czynniki
        wynik = []

        for i in 1..self do
            if self % i == 0
                wynik.push((i))
            end
        end
        return wynik
    end

    def ack(y)
        if self == 0
            return y+1
        elsif y == 0 
            return (self-1).ack(1)
        else
            return (self-1).ack(self.ack(y-1))
        end
    end
    
    def doskonala
        suma_czynnikow = self.czynniki

        if self == suma_czynnikow.inject(0, :+) - self
            return true
        else
            return false
        end
    end

    def zamiana
        wynik = ""
        for i in 0..self.to_s.length do
            case self.to_s[i]
            when '0'
                wynik += ' zero'
            when '1'
                wynik += ' jeden'
            when '2'
                wynik += ' dwa'
            when '3'
                wynik += ' trzy'
            when '4'
                wynik += ' cztery'
            when '5'
                wynik += ' piec'
            when '6'
                wynik += ' szesc'
            when '7'
                wynik += ' siedem'
            when '8'
                wynik += ' osiem'
            when '9'
                wynik += ' dziewiec'
            end
        end
        return wynik
    end
end
puts "Czynniki liczby 6 to #{6.czynniki}"
puts "Funkcja Ackermana od 2 = #{2.ack(1)}"
puts "28 jest doskonala? #{28.doskonala}"
puts "496 jest doskonala? #{496.doskonala}"
puts "495 jest doskonala?  #{495.doskonala}"
puts "Slownie 123: #{123.zamiana}"