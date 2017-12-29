find . -name '*.cu' | sed 's/.cu$//g' | map -t -I{} sh -c 'ln -s  {}.cu {}.cxx'
