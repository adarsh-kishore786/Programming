defmodule MyList do
  def len([]), do: 0
  def len([_head|tail]), do: 1 + len tail

  def square([]), do: []
  def square([ head | tail ]), do: [ head*head | square(tail) ]

  def add([], _n), do: []
  def add([ head | tail ], n), do: [ head + n | add(tail, n) ]

  # Let's generalize now
  def map([], _func), do: []
  def map([ head | tail], func), do: [ func.(head) | map(tail, func) ]
end
