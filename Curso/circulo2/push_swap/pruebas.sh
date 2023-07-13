setup=$(rm -f salida.txt resultado.txt)
check=$(diff salida.txt resultado.txt 2> /dev/null | wc -l | awk '{if ($1 != 0) {print "KO"} else {print "OK"}}')

echo "Prueba con 2 elementos"
$setup; touch salida.txt; ./push_swap 1 2 > resultado.txt;
echo $check

echo "Pruebas con 3 elementos"
$setup; touch salida.txt; ./push_swap 1 2 3 > resultado.txt;
$setup; echo "rra\nsa\n" >> salida.txt; ./push_swap 1 3 2 >> resultado.txt;
$setup; echo "sa\n" >> salida.txt; ./push_swap 2 1 3 >> resultado.txt;
$setup; echo "rra\n" >> salida.txt; ./push_swap 2 3 1 >> resultado.txt;
$setup; echo "ra\n" >> salida.txt; ./push_swap 3 1 2 >> resultado.txt;
$setup; echo "ra\nsa\n" >> salida.txt; ./push_swap 3 2 1 >> resultado.txt;
echo $check