# Class name
class FileTest
  def open(fname)
    self.do_open(fname)
    if block_given?
      yield(self)
      self.close
    else
      return self
    end
  end
end
