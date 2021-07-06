defmodule MyList do
  defp _sum([], total), do: total
  defp _sum([ head | tail ], total), do: _sum( tail, total + head)

  def sum(list), do: _sum(list, 0)

  def sum_no_acc([]), do: 0
  def sum_no_acc([ head | tail ]), do: head + sum(tail)
end
