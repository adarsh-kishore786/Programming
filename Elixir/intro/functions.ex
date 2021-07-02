f1 = fn
  0, 0, 0 -> "FizzBuzz"
  0, _, _ -> "Fizz"
  _, 0, _ -> "Buzz"
  _, _, c -> c
end

f2 = fn
  n -> f1.(rem(n, 3), rem(n, 5), n)
end

IO.puts f1.(0, 0, 0)
IO.puts f1.(0, 6, 7)
IO.puts f1.(0, 0, 8)
IO.puts f1.(:ok, 0, "hello")
IO.puts f1.(:ok, :error, :enoent)
IO.puts ""

IO.puts f2.(10)
IO.puts f2.(11)
IO.puts f2.(12)
IO.puts f2.(13)
IO.puts f2.(14)
IO.puts f2.(15)
IO.puts f2.(16)
