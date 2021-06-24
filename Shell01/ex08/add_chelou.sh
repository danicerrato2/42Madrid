base1="\'\\\"\?\!" 
base2="mrdoc"
base5="01234"

str1_b5=$(echo $FT_NBR1 | tr $base1 01234)
str1_b10=$(echo "obase=10; ibase=5; $str1_b5" | bc)

str2_b5=$(echo $FT_NBR2 | tr $base2 $base5)
str2_b10=$(echo "obase=10; ibase=5; $str2_b5" | bc)

sum_b10=$(bc<<<"$str1_b10+$str2_b10")
sum_b13=$(echo "obase=13; $sum_b10" | bc)

echo $sum_b13 | tr 0123456789ABC 'gtaio luSnemf'
