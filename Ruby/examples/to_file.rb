# Module test
module ToFile
  def filename
    "object_#{self.object_id}.txt"
  end
# definition
  def to_f
    File.open(filename, 'w') {|file| file.write(to_s)}
  end
end

# Person class
class Person
  include ToFile
  attr_reader :name

  def initialize(name)
    @name = name
  end

  def to_s
    name
  end
end

Person.new('matz').to_f
