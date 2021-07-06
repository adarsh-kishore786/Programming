defmodule Extension do
  def getExt(filename) do
    arr = String.split(filename, ".")
    val = List.last arr
    IO.puts ".#{val}"
  end
end
