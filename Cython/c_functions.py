from setuptools import Extension, setup
from Cython.Build import cythonize

ext_modules = [
    Extension
    (
      "c_functions",
      sources=["c_functions.pyx"],
      libraries=["m"]  # Unix-like specific
    )
]

setup(
    name="Demos",
    ext_modules = cythonize(ext_modules)
)
