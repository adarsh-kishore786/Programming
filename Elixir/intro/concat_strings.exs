prefix =
fn s1 ->
  fn s2->
    String.to_charlist(s1) ++ String.to_charlist(" ") ++ String.to_charlist(s2)
  end
end

IO.puts prefix.("Mrs.").("Smith")
IO.puts prefix.("Elixir").("Rocks")
