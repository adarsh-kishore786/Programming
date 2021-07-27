defmodule Example do
  @author "Ash Ketchum"

  def get_author do
    @author
  end
end

IO.puts "Example was written by #{Example.get_author}"
