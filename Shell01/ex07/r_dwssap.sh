cat /etc/passwd | sed '/#/d' | sed -n 'n;p' | cut -d ':' -f 1 | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | sed 's/$/,/g' | xargs 
