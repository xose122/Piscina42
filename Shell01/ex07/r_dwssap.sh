cat /etc/passwd | grep -v "#" | sed '1d; n; d' | cut -d: -f1 | rev | sort -r | sed -n $FT_LINE1,$FT_LINE2\p|sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/, /g' | tr '\n' '.'
