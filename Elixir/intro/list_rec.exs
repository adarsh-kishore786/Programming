defmodule ListRec do
  def mapsum([], _), do: 0
  def mapsum([ head | tail], func) do
    func.(head) + mapsum(tail, func)
  end

  defp _max([], val), do: val
  defp _max([ head | tail ], val) do
    if (head > val) do
      _max(tail, head)
    else
      _max(tail, val)
    end
  end

  def max([ head | tail ]), do: _max(tail, head)

  def caeser([], _), do: []
  def caeser([ head | tail ], n) do
    if (head >= 65 && head <= 92) do
      a = rem(head - 65 + n, 26)
      [ a + 65 | caeser(tail, n) ]
    else
      a = rem(head - 97 + n, 26)
      [ a + 97 | caeser(tail, n) ]
    end
  end
end
