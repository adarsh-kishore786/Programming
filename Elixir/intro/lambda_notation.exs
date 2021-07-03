f1 = fn
  x -> x + 2
end

f1a = &(&1 + 2)

f2 = fn
  x -> IO.inspect x
end

f2a = &(IO.inspect &1)

IO.inspect Enum.map [1, 2, 3, 4], f1
IO.inspect Enum.map [1, 2, 3, 4], f1a
IO.puts ""
Enum.map [1, 2, 3, 4], f2
IO.puts "\n"
Enum.map [1, 2, 3, 4], f2a
