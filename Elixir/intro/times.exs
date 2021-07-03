defmodule Times do
  def double(n) do
    n * 2
  end

  def triple(n) do
    n * 3
  end

  def quadruple(n) do
    double(double(n))
  end
end

defmodule Welcome do
  def greet(msg, name) do
    IO.puts msg
    IO.puts "How are you, #{name}?"
  end
end
