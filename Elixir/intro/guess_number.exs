defmodule Chop do
  def guess(actual, m1..m2) when actual < m1 or actual > m2 do
    IO.puts "Number not in range"
  end

  def guess(actual, m1..m2) when actual >= m1 and actual <= m2 do
    mid = div(m1 + m2, 2)
    IO.puts "Is it #{mid}?"
    if mid == actual do
      _guess(mid)
    else
      if (actual < mid) do
        guess(actual, m1..mid)
      else
        guess(actual, mid..m2)
      end
    end
  end

  def _guess(actual), do: IO.puts "Yes, it is #{actual}!"
end
