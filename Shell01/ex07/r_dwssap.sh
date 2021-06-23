cat /etc/passwd | sed '/#/d' | sed -n 'n;p' 
