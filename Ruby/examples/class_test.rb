# Class Test
#

class Parent
  def initialize(name="Same", age=0)
    @name = name
    @age = age
  end

  def name
    @name
  end

  def test_method
    puts "I am from parent"
  end

  def self.helper_method
    puts "Self test"
  end

  def call_helper
    puts helper_method
  end

  helper_method

end

# Descriptive comment
class Child < Parent 
  def initialize(name="test", age=0)
    @name = name
    @age = age
  end
end

puts Parent.call_helper
puts "hello"
kate = Parent.new
puts kate.call_helper

john = Child.new("Jason", 5)

puts john.name

p john.test_method

p john.call_helper
