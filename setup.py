from distutils.core import setup, Extension

module1 = Extension('hello2', sources = ['hello2.c'])

setup (name = 'hello2',
        version = '1.0',
        description = 'This is a demo package',
        ext_modules = [module1])
