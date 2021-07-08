defmodule MyList do
  defp _span(to, to, list), do: [ to | list ]

  defp _span(from, to, list) do
    if (from < to) do
      new_list = [ to | list ]
      _span(from, to - 1, new_list)
    else
      IO.puts "from should be less than to"
    end
  end

  def span(from, to), do: _span(from, to, [])
end
