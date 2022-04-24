# Triangle Project Code.

# Triangle analyzes the lengths of the sides of a triangle
# (represented by a, b and c) and returns the type of triangle.
#
# It returns:
#   :equilateral  if all sides are equal
#   :isosceles    if exactly 2 sides are equal
#   :scalene      if no sides are equal
#
# The tests for this method can be found in
#   about_triangle_project.rb
# and
#   about_triangle_project_2.rb
#
class TriangleError < StandardError
end

def triangle(a, b, c)
  # WRITE THIS CODE
  if illegal_triangle(a, b, c)
    raise TriangleError, "A Triangle Error"
  end

  if a == b and b == c
    :equilateral
  elsif (a == b) or (b == c) or (c == a)
    :isosceles
  else
    :scalene
  end
end

# Error class used in part 2.  No need to change this code.

def illegal_triangle(a, b, c)
  if (a + b <= c) or (b + c <= a) or (c + a <= b)
    return true
  end
  false
end
