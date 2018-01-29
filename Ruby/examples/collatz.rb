def build_collatz(num)
  if num == 1
    puts num.to_s
    return 1
  elsif num % 2 == 0 
    puts num.to_s
    return build_collatz(num/2)
  else
    puts num.to_s
    return build_collatz(num*3+1)
  end
end

print "Enter a number: "
number = gets.to_i
build_collatz(number)
