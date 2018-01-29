#Descriptive Comment
class GUESS_NUM
  number = rand(10)
  counter = 0
  until counter > 6
    puts "I'm thinking of a number from 1-10..\nEnter number: "
    guess = gets.to_i

    counter += 1
    if guess < number 
      puts "Too low"

    elsif guess > number 
      puts "Too high"

    elsif guess == number
      puts "Congratulations, #{number} was the number"
      exit 
    end

  end
  puts "Sorry, number was #{number}!"
end
